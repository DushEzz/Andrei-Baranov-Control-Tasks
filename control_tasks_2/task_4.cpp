#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    system("chcp 1251");

    srand(time(NULL)); // Это чтобы каждый раз были новые рандомные числа
    
    int random_y = rand() % 5 - 2; // Вычисляем рандомные координаты центра мишени в диапазоне от -2 до 2 включительно
    int random_x = rand() % 5 - 2;

    cout << "Случайный центр мишени: (" << random_x << ", " << random_y << ")" << endl;

    double hindrance = double(rand()) / RAND_MAX; // Вычисляем рандомную помеху в диапазоне от 0 до 1 (RAND_MAX - это максимальное значение, которое может выдать функция rand)
    cout << "Помеха при выстреле: " << hindrance << endl;

    int shoot_type;
    cout << "Выберите тип мишени (1 или 2): "; cin >> shoot_type;

    while (shoot_type != 1 && shoot_type != 2) // Если был выбрать неправильный тип мишени, с помощью цикла while повторно спршиваем пользователя, пока он не введет корректный тип
    {
        cout << "Введите, пожалуйста, корректное значение типа мишени (1 или 2): "; cin >> shoot_type;
    }

    int total_points = 0, amount = 5; // Общее количество очков и выстрелов

    cout << "Вам предстоит сделать 5 выстрелов, вводя координаты каждого из них (например, 2.45 1.2)" << endl;

    int i;
    for (i = 1; i <= amount; i++) // В цикле перебираем каждый выстрел и считаем для него очки
    {
        double x, y;

        cout << "Координаты выстрела номер " << i << ": ";
        cin >> x; cin >> y; // Принимаем от пользователя координаты выстрела

        double circle = pow(((x + hindrance) - random_x), 2) + pow(((y + hindrance) - random_y), 2); // Подставляем x и y в уравнение окружности

        // Последовательно сравниваем с квадратами радиусов каждого сктора очков и прибавляем в общий результат соответствующую сумму очокв
        if (circle <= 1)
            total_points += 10;
        else if (circle <= 4)
            total_points += 5;
        else
            if (shoot_type == 2)
                if (circle <= 9)
                    total_points += 1;
    }

    cout << "Вы получили " << total_points << " очков" << endl;
    cout << "Ваше уровень - ";

    // Чтобы сказать пользователю его уровень стрельбы, проверяем общее количество очков на вхождение в соответствующие диапазоны (иначе новичек)
    if (total_points > 35)
    {
        cout << "снайпер";
    }
    else if (total_points > 20)
    {
        cout << "стрелок";
    }
    else
    {
        cout << "новичок";
    }

    cout << endl;

    return 0;
}
