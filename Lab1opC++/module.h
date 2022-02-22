#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
void create_text(string file_name);
string* split(string line, int& wordnum);
int lengthLongest(string line, int& wordNum);
void add(string file1_name, string file2_name);
void output(string file_name);