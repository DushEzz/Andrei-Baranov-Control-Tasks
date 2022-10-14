#include <iostream>
#include <string>

using namespace std;

bool validate_snils (string snils)
{
    int count = 0;

    snils.erase(remove(snils.begin(), snils.end(), ' '), snils.end()); // Удаляем все пробелы и тире из строки
    snils.erase(remove(snils.begin(), snils.end(), '-'), snils.end());

    for (int i = 0; i < snils.length(); i++) // В цикле проходим по каждому символу и проверяем следующие 2 (справа от него) на их совпадение
    {
        if (snils[i] >= '0' and snils[i] <= '9') // Если строка является цифрой, то увеличиваем счетчик на 1
        {
            count += 1;
        }

        if (snils[i] == snils[i + 1] && snils[i + 1] == snils[i + 2]) // Проверка на совпадение
        {
            return false;
        }
    }

    if (count != 9) // Если цикл пройден успешно, проверяем на то, что номер СНИЛС содежит 9 цифр, а не других символов
    {
        return false;
    }

    return true;
}

int main()
{
    system("chcp 1251");

    string snils;
    cout << "Введите номер СНИЛС (9 цифр): "; getline(cin, snils);; // Получаем от пользователя номер СНИЛС
    
    bool is_valid = validate_snils(snils); // Проверяем валидность введенного номера 

    if (is_valid)
    {
        cout << "Данный номер СНИЛС валидный\n";
    }
    else
    {
        cout << "Данный номер СНИЛС не валидный\n";
    }

    return 0;
}