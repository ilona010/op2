#include "point.h"
Point::Point() :r(0), f(0), z(0) {};
Point::Point(double r, double f, double z)
{
    this->r = r;
    this->f = f;
    this->z = z;
}
double Point::GetR()
{
    return r;
}
double Point::GetF()
{
    return f;
}
double Point::GetZ()
{
    return z;
}
double Point::dist()
{
    double d = sqrt(pow(z, 2) + pow(r, 2));
    return d;
}
Point& Point::operator++()
{
    ++f;
    return *this;
}
Point& Point::operator+=(double x)
{
    r += x;
    return *this;
}
bool Point::operator==(const Point& A)
{
    if (r == A.r && f == A.f && z == A.z) return true;
    else return false;
}
void Point::print()
{
    cout << r << '\t' << f << '\t' << z << endl;
}