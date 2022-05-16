#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;
struct Good
{
    char Name[50];
    char data1[11];
    char data2[11];
    double Price;
};
void CreateStore(string name);
void output(string name);
void ChangePrice(string name1, string name2);
void CreateFile3(string name1, string name2);
long int CountDays(char* data);