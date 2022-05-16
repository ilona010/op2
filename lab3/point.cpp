#include "point.h"
int Point::counter = 0;
Point::Point():x(0), y(0), z(0) { }
Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    if (x > 0 && y > 0 && z > 0)
    {
        if (floor(x) == x && floor(y) == y && floor(z) == z) ++counter;
    }
}
void Point::print() { cout << "(" << x << ";" << y << ";" << z << ")" << endl; }
double Point::GetX() { return x; }
double Point::GetY() { return y; }
double Point::GetZ() { return z; }