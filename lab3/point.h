#pragma once
#include <iostream>
using namespace std;
class Point
{
    double x, y, z;
public:
    int static counter;
    Point();
    Point(double x, double y, double z);
    void print(); 
    double GetX(); 
    double GetY(); 
    double GetZ(); 
};
