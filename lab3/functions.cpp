#include "functions.h"
vector<Point> CreateArray()
{
    vector <Point> points;
    double x, y, z;
    char c;
    do
    {
        cout << "������ ���������� ����� � �������:" << endl;
        cout << "x=";cin >> x;
        cout << "y=";cin >> y;
        cout << "z=";cin >> z;
        Point A(x, y, z);
        points.push_back(A);
        cout << "����������?(+/0)";cin >> c;
        cin.ignore();
    } while (c != '0');
    return points;
}
void output(vector<Point> points)
{
    for (int i = 0;i < points.size();i++)
    {
        cout << "����� " << i + 1 << ":";
        points[i].print();
    }
}