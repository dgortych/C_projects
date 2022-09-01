#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

void Key_initialization(int* key_tab, const char* n_key);
char Generation_and_encryption(int* key_tab,  char input_sign);