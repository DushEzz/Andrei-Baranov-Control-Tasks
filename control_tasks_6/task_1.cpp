#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    system("chcp 1251");

    ofstream out("poem.txt", ios::out | ios::binary);
    
    if (!out)
    {
        cout << "Файл открыть невозможно\n";

        return 1;
    }

    cout << "Введите стихотворение. Завершите его, нажав два раза на Enter: \n";
    string line = "";
    do
    {
        getline(cin, line); out << line << "\n";
    } 
    while (line != "");
    
    out.close();

    return 0;
}
