#include "module.h"
int main()
{
    SetConsoleCP(1251);//ввід і вивід української мови
    SetConsoleOutputCP(1251);
    string file1_name = "inputfile.txt";
    string file2_name = "outputfile.txt";
    create_text(file1_name);//введення тексту у файл
    add(file1_name, file2_name);//додавання зміненого тексту у другий файл
    output(file1_name);//виведення файлів
    output(file2_name);
}
