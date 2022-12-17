#include <iostream>

using namespace std;

template<class T>

double average(T arr[], int size)
{
    T sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];
    double avrg = sum / size;
    
    return avrg;
}

int main()
{
    double arrd[] = { 2.1, 2.3, 1.7, 6.6, 5.3, 2.44, 3.1, 2.4, 1.2 };

    int k = sizeof(arrd) / sizeof(arrd[0]);

    double a = average(arrd, k);

    cout << a << endl;
}
