#pragma once
#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;
class Point
{
    double r, f, z;
public:
    Point();
    Point(double r, double f, double z);
    double GetR();
    double GetF();
    double GetZ();
    double dist();
    void print();
    Point& operator++();
    Point& operator+=(double x);
    bool operator==(const Point& A);
};