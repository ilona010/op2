#include "functions.h"
void CreateStore(string name)
{
    char s;
    cout << "Введіть 0 для створення нового файла або + для доповнення:";cin >> s;
    cin.ignore();
    fstream file;
    if (s == '0')
    {
        file.open(name, ios::out, ios::binary);
    }
    else if (s == '+')
    {
        file.open(name, ios::app, ios::binary);
    }
    if (file.is_open())
    {
        char c;
        do
        {
            Good a;
            cout << "назва:";cin.getline(a.Name, 100);
            cout << "дата виготовлення:";cin.getline(a.data1, 11);
            cout << "кінцевий термін придатності:";cin.getline(a.data2, 11);
            cout << "ціна:";cin >> a.Price;
            file.write((char*)&a, sizeof(Good));
            cout << "prod?(+/0)";cin >> c;
            cin.ignore();
        } while (c != '0');
    }
    else cout << "Файл не вдалося відкрити!" << endl;
    file.close();
}
long int CountDays(char* data)
{
    const int MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int d = int(data[0] - 48) * 10 + int(data[1] - 48);
    int m = int(data[3] - 48) * 10 + int(data[4] - 48);
    int y = int(data[6] - 48) * 1000 + int(data[7] - 48) * 100 + int(data[8] - 48) * 10 + int(data[9] - 48);
    long int k = y * 365 + d;
    for (int i = 0;i < m - 1;i++)
    {
        k += MonthDays[i];
    }
    return k;
}
void ChangePrice(string name1, string name2)
{
    Good a;
    ifstream file1(name1, ios::binary);
    ofstream file2(name2, ios::binary);
    while (file1.read((char*)&a, sizeof(Good)))
    {
        long int d1 = CountDays(a.data1);
        long int d2 = CountDays(a.data2);
        int term = d2 - d1;
        if (term <= 14)
        {
            a.Price -= (a.Price * 0.05);
        }
        if (term > 365)
        {
            a.Price += (a.Price * 0.03);
        }
        file2.write((char*)&a, sizeof(Good));
    }
    file1.close();
    file2.close();
}
void CreateFile3(string name1, string name2)
{
    Good a;
    ifstream file1(name1, ios::binary);
    ofstream file2(name2, ios::binary);
    char data[11];
    cout << "введіть поточну дату:";cin.getline(data, 11);
    while (file1.read((char*)&a, sizeof(Good)))
    {
        int m = int(data[3] - 48) * 10 + int(data[4] - 48);
        int m1 = int(a.data1[3] - 48) * 10 + int(a.data1[4] - 48);
        int y = int(data[6] - 48) * 1000 + int(data[7] - 48) * 100 + int(data[8] - 48) * 10 + int(data[9] - 48);
        int y1 = int(a.data1[6] - 48) * 1000 + int(a.data1[7] - 48) * 100 + int(a.data1[8] - 48) * 10 + int(a.data1[9] - 48);
        if (y == y1)
        {
            if (m1 < m)
            {
                file2.write((char*)&a, sizeof(Good));
            }
        }
        else
        {
            file2.write((char*)&a, sizeof(Good));
        }
    }
    file1.close();
    file2.close();
}
void output(string name)
{
    Good a;
    ifstream file(name, ios::binary);
    cout << name << ":" << endl;
    cout << "назва" << "\t" << "дата виготовлення" << "\t" << "кінцевий термін придатності" << "\t" << "ціна" << endl;
    while (file.read((char*)&a, sizeof(Good)))
    {
        cout << a.Name << "\t" << a.data1 << "\t\t" << a.data2 << "\t\t\t" << a.Price << endl;
    }
    file.close();
}