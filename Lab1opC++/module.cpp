#include "module.h"
void create_text(string file_name)//введення тексту у файл
{
    char s;
    cout << "Введіть с для створення нового файла або а для доповнення:";cin >> s;
    fstream file;
    if (s == 'с')
    {
        file.open(file_name, ios::out);
    }
    else if (s == 'а')
    {
        file.open(file_name, ios::app);
        file << '\n';
    }
    if (file.is_open())
    {
        cout << "Введіть текст:" << endl;
        string text;
        cin.ignore();
        getline(cin, text, (char)20);
        file << text;

    }
    else cout << "Файл не вдалося відкрити!" << endl;
    file.close();
}

string* split(string line, int& wordnum)//розбиття рядка на слова і їх  кількість
{
    string* words = new string[line.length()];
    int index = 0;
    string buffer = "";
    for (size_t i = 0;i < line.length();i++)
    {
        if (line[i] == ' ')
        {
            if (line[i - 1] != ' ' && i - 1 >= 0)
            {
                words[index++] = buffer;
                buffer = "";
            }
        }
        else
        {
            buffer += line[i];
        }
    }
    if (line[line.length() - 1] != ' ')
    {
        words[index++] += buffer;
    }
    wordnum = index;
    return words;
}
int lengthLongest(string line, int& wordNum)//довжина найдовшого слова
{
    string* words = split(line, wordNum);
    int length_word = 0;
    for (int i = 0;i < wordNum;i++)
    {
        if (words[i].length() > length_word)
        {
            length_word = words[i].length();
        }
    }
    return length_word;
}
void add(string file1_name, string file2_name)//створення другого файла
{
    ifstream infile(file1_name);
    ofstream outfile(file2_name);
    string buffer, new_text;
    while (getline(infile, buffer))
    {
        int wordcount = 0;
        int size = lengthLongest(buffer, wordcount);
        new_text += to_string(wordcount) + ' ' + buffer + ' ' + to_string(size) + '\n';

    }
    outfile << new_text;
    infile.close();
    outfile.close();
}
void output(string file_name)//виведення вмісту файла
{
    cout << "файл " << file_name << ":" << endl;
    ifstream file(file_name);
    string line;
    while (!file.eof())
    {
        getline(file, line);
        cout << line << endl;
    }
    file.close();
}