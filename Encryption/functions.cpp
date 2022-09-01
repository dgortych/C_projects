#include "FUNCTIONS.H"

void Key_initialization(int* key_tab, const char* n_key)
{
	for (int i = 0; i < 256; i++)
	{
		key_tab[i] = i;		
	}
	                                                                        // inicjalizacja klucza
	int j = 0;
	for (int i = 0; i < 256; i++)
	{
		j = (j + key_tab[i] + n_key[i % strlen(n_key)]) % 256;
		swap(key_tab[i], key_tab[j]);
	}	
}

char Generation_and_encryption(int* key_tab,  char input_sign)
{
	static int i = 0;
	static int j = 0;
	char output_sign;
				                                                     
	i = (i + 1) % 256;
	j = (j + key_tab[i]) % 256;
	swap(key_tab[i], key_tab[j]);
	output_sign = (key_tab[(key_tab[i] + key_tab[j]) % 256]) ^ input_sign;           //operacja XOR oraz zwrocenie zaszyfrowanego bajtu
	return output_sign; 
}


