
#include "point.h"
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Point P1;
    double r2, f2, z2,r3,f3,z3;
    cout << "input point:" <<endl;
    cout << "r=";cin >> r2;cin.ignore();
    cout << "f=";cin >> f2;cin.ignore();
    cout << "z=";cin >> z2;cin.ignore();
    Point P2(r2, f2, z2);
    cout << "input point:" << endl;
    cout << "r=";cin >> r3;cin.ignore();
    cout << "f=";cin >> f3;cin.ignore();
    cout << "z=";cin >> z3;cin.ignore();
    Point P3(r3, f3, z3);
    cout << "P1:";P1.print();
    cout << "P2:";P2.print();
    cout << "P3:";P3.print();
    ++P1;
    cout << "P1:";P1.print();
    double x;
    cout << "input x:";cin >> x;cin.ignore();
    P2 += x;
    cout << "P2:";P2.print();
    if (P1 == P2) cout << "P1 is equal to P2" << endl;
    else cout<< "P1 is not equal to P2" << endl;
    double d = P3.dist();
    cout << "distance="<<d<<endl;
}
