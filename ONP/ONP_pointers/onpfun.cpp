#include "ONPFUN.h"
#include "dSTACK.h"
#include "Stack.h"

#define DOT '.'
double GetNum()
{
	char c;
	double res = 0;
	int    sign = 0;

	skipSpaces();

	if ( ( c = getchar() ) == '-' ) sign = 1;  // pomijanie znakow
	else if ( c != '+' ) ungetc(c, stdin);

	while ( isDigit( c = getchar() ) )    //horner czesc rzeczywista
		res = res * 10 + c - '0';

	if (c == DOT)
	{
		double coef = 0.1;
		while ( isDigit( c = getchar() ) )    // czesc u³amkowa
		{
			res += (c - '0') * coef;
			coef *= 0.1;
		}
	}
	ungetc(c, stdin);

	if ( sign ) res = -res;
	return res;
}

int isDigit( char c )
{
	return  ( c <= '9' && c >= '0' );
}
void skipSpaces()
{
	char c;
	while ( ( c = getchar() ) == ' ' );  
	ungetc(c, stdin);
}
char getOper()
{
	skipSpaces();
	return  getchar();
}
int isOper( char c )
{
	switch ( c )
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^': return 1;
	}
	return 0;
}
int prior( char c )
{
	switch ( c )
	{
	case '+':
	case '-': return 1;
	case '*':
	case '/': return 2;
	case '^': return 3;
	}
	return 0;
}
double Eval( char nOper, double arg1, double arg2 )
{
	switch ( nOper )
	{
	case '+': return arg1 + arg2;
	case '-': return arg1 - arg2;
	case '*': return arg1 * arg2;
	case '/':  if ( fabs( arg2 ) > 1e-15 )  // dzielenie przez 0
		return arg1 / arg2;
		perror( "ERROR : Devisin by 0 (Eval)" );
		return DBL_MIN;
	case '^': return pow( arg1, arg2 );   
	}
	return 0;
}


double calcONP()
{
	char c;

	StackItem* pStack = initStack();
	DStackItem* pDStack = initDStack();

	dpush( GetNum(), &pDStack );
	while ( isOper( c = getchar() ) )
	{
		while ( prior( c ) <= prior( top( pStack ) ) )
		{
			double t = dpop( &pDStack );
			dpush( Eval( pop( &pStack ), dpop( &pDStack ), t ), &pDStack );
		}
		push( c, &pStack );
		dpush( GetNum(), &pDStack );
	}
	while ( !isEmpty( pStack ) )
	{
		double t = dpop( &pDStack );
		dpush( Eval( pop( &pStack ), dpop( &pDStack ), t ), &pDStack);
	}
	return dpop( &pDStack );
} 
/*
void ONP()
{
	char c;
	StackItem* pStack = initStack();
	while ((c = getchar()) != '\n')
	{
		if (!isOper(c))
			putchar(c);
		else
		{
			while (prior(c) <= prior(top(pStack)))
				putchar(pop(&pStack));
			push(c, &pStack);
		}
	}
	while (!isEmpty(pStack))
		putchar(pop(&pStack));
}
*/