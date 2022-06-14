#pragma once
#include <iostream>
#include<string>
#include<vector>

using namespace std;

class Num
{

public:
    int n;
    Num(int n);
    Num();
    virtual void increase(int x);
    virtual void reducing(int x);
    virtual double mod();

};
class RationalNum :public Num
{
    int denominator;
public:
    RationalNum(int num, int denominator);
    void reducing(int x) override;
    double mod() override;
    friend ostream& operator<<(ostream& out, const RationalNum& num);
};
class CompNum :public Num
{
    int im;
public:
    CompNum(int re, int im);
    void increase(int x) override;
    double mod() override;
    friend ostream& operator<<(ostream& out, const CompNum& num);
};
vector<RationalNum> CreateArrRational(int x);
vector<CompNum> CreateArrComp(int x);
double Sum(vector<RationalNum> rnum, vector<CompNum> cnum);
template<typename T> void print(vector<T> arr)
{
    for (int i = 0;i < arr.size();i++)
    {
        cout << arr[i];
    }
}
