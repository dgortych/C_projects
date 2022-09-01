#include "FUNCTIONS.H"

int main()
{  
    fstream input_file, output_file;
    input_file.open("input.txt");
    output_file.open("output.txt");
    if( !(input_file || output_file) )
    {
        perror("Failed to open files");
        return 1;
    }
 
    int* Key_tab = new int[256];
    const char* key = "klucz";                // klucz

    Key_initialization(Key_tab, key);         // inicjalizacja klucza

    while (!input_file.eof())
        output_file << Generation_and_encryption(Key_tab, input_file.get());           //operacja XOR oraz zwrocenie zaszyfrowanego bajtu
   
    delete[] Key_tab;
    input_file.close();
    output_file.close();
    return 0;
}

