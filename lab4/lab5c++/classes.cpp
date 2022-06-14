#include "classes.h"
Num::Num(int n)
{
    this->n = n;
}
Num::Num()
{
    this->n = 0;
}
void Num::increase(int x)
{
    n *= x;
}
void Num::reducing(int x)
{
    n /= x;
}
double Num::mod()
{
    return abs(n);
}
RationalNum::RationalNum(int num, int denominator) :Num(num)
{
    this->denominator = denominator;
}
void RationalNum::reducing(int x)
{
    denominator *= x;
}
double RationalNum::mod()
{
    double x = fabs((double)n / (double)denominator);
    return x;
}
ostream& operator<<(ostream& out, const RationalNum& num)
{

    out << num.n << "/" << num.denominator << endl;
    return out;
}
CompNum::CompNum(int re, int im) :Num(re)
{
    this->im = im;
}
void CompNum::increase(int x)
{
    n *= x;
    im *= x;
}
double CompNum::mod()
{
    return sqrt(pow(n, 2) + pow(im, 2));
}
ostream& operator<<(ostream& out, const CompNum& num)
{
    out << num.n << "+i*" << num.im << endl;
    return out;
}
vector<RationalNum> CreateArrRational(int x)
{
    srand(time(NULL));
    vector<RationalNum> numbers;
    for (int i = 0;i < x;i++)
    {
        int n1 = rand() % 10 - 10;
        int n2 = rand() % 10 + 1;
        RationalNum num(n1, n2);
        numbers.push_back(num);
    }
    return numbers;
}
vector<CompNum> CreateArrComp(int x)
{
    srand(time(NULL));
    vector<CompNum> numbers;
    for (int i = 0;i < x;i++)
    {
        int n1 = rand() % 10;
        int n2 = rand() % 10;
        CompNum num(n1, n2);
        numbers.push_back(num);
    }
    return numbers;
}
double Sum(vector<RationalNum> rnum, vector<CompNum> cnum)
{
    double s = 0;
    for (int i = 0;i < rnum.size();i++)
    {
        s += rnum[i].mod();
    }
    for (int i = 0;i < cnum.size();i++)
    {
        s += cnum[i].mod();
    }
    return s;
}