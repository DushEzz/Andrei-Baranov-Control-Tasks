#include iostream

using namespace std;

void show_array(int Arr[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "mas[" << i << "]=";
		cin >> Arr[i];
	}

	int s = 0;
	for (int i = 0; i < N; i++)
	{
		s += Arr[i];
	}

	cout << "Сумма элементов массива: " << s << endl;
}

void sort_array(int Arr[], int N)
{
	cout << "Исходный массив: ";
	for (int i = 0; i < N; i++)
		cout << Arr[i] << '\t';
	cout << endl;

	int min = 0;
	int buf = 0;

	for (int i = 0; i < N; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
			min = (Arr[j] < Arr[min])  j : min;

		if (i != min)
		{
			buf = Arr[i];
			Arr[i] = Arr[min];
			Arr[min] = buf;
		}
	}
	
	cout << "Отсортированный массив: ";
	for (int i = 0; i < N; i++)
		cout << Arr[i] << '\t';
}

int main()
{
	system("chcp 1251");

	int N; cout << "Введите размер массива: "; cin >> N;
	int* myArray = new int[N];

	show_array(myArray, N);
	sort_array(myArray, N);

	return 0;
}
