#include "function.h"
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string file1_name = "file1.txt";
    string file2_name = "file2.txt";
    string file3_name = "file3.txt";
    CreateStore(file1_name);
    output(file1_name);
    ChangePrice(file1_name, file2_name);
    output(file2_name);
    CreateFile3(file2_name, file3_name);
    output(file3_name);

}
