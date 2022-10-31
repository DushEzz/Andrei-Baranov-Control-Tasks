#include <iostream>

using namespace std;

int search_element(int* a, int element, int size) 
{
    int index = -1;

    for (int i = 0; i < size; i++) 
    {
        if (a[i] == element) 
        {
            index = i;

            if (index == 0) 
                break;
            else
                swap(a[i], a[i - 1]);
        }
    }

    return index;
}

int main() 
{
    system("chcp 1251");

    int arr[] = { 7, 2, 6, 8, 43, 4, 76, 10, 23, 15 };

    for (int i = 0; i < 10; i++) 
    {
        int index = search_element(arr, 9, 10);

        if (index >= 0)
            cout << "Число 9 имеет идекс " << index << "\n";
        else
        {
            cout << "Число 9 не найдено" << "\n";

            break;
        }
    }

    return 0;
}
