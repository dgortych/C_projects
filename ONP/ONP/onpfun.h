#pragma once
#ifndef ONPFUN_H
#define ONPFUN_H
#include <stdio.h>

double GetNum();
void skipSpaces();
int isOper(char nOper);
int prior(char nOper);
int isDigit(char c);
double ONP();
char getOper();
void onp();
double Eval(char nOper, double argl, double arg2);  //do kalkulatora

#endif
