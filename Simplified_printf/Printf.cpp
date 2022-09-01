#include "PRINTF.H"

void outDec(int n)
{
	if (!n)
	{
		putchar('0');
		return;
	}
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	outNum(n);
}
void outChar( char c )
{
	putchar(c);
}
void outStr(char* c)
{
	while (*c)
		putchar(*c++);
      
}
void outDouble(double d)
{
	if (d > 0 || d <= -1)
		outDec(d);

	if (d < 0)
	{
		d = -d;
		if (d > -1)
			outChar('-');
	}
	putchar('.');
	double r = 10;
	int prec = 5;    // dokladnosc po przecinku
	for (int i = 0; i < prec; i++)
	{
		int x = ((long long)(d * r)) % 10;
		outChar(x + '0');
		r *= 10;
	}
}	
void outNum(int n)    
{
	if (n > 0)
	{
		outNum(n / 10);
		outChar(n % 10 + '0');
	}
}
int Printf(const char* sFormat, ...) 
{
	va_list args;
	va_start(args, sFormat);
	int ret_val = PrintfV(sFormat, args);
	va_end(args);
	return ret_val;
}
int PrintfV(const char* sFormat, va_list arg_list )
{
	char c ;
	int res = 0;
	while (c = *sFormat++)
	{
		switch (c)
		{
		  case '%':
			 switch (c = *sFormat++)
			 {
			  case 'c': outChar(va_arg(arg_list, char));    break;
			  case 'd': outDec(va_arg(arg_list, int));    break;
			  case 's': outStr(va_arg(arg_list, char*));    break;
			  case 'f': outDouble(va_arg(arg_list, double));   break;
			  default: outChar('%'); outChar(c);
			 }break;
		  case '`': c = '\'';  break;
		  default: outChar(c); break;
		}
	}
	return 0;
}

