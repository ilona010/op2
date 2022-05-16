#include "functions.h"
#include "point.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector < Point > points= CreateArray();
    output(points);
    cout << "кількість точок з цілочисельними координатами,які попадають в перший октант=" << Point::counter << endl;
}

