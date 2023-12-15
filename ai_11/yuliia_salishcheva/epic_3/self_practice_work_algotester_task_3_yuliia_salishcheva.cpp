//Завдання 3. Написати функцію, яка ділить суму всіх елементів
//переданого їй масиву дійсних чисел на максимальний
//елемент масиву.

#include <iostream>
using namespace std;

void array_input(double ar[], double length)
{

	for (size_t i = 0; i < length; i++)
	{
		cout << "[" << i + 1 << "]= ";
		cin >> ar[i];
	}
}

double array_ms(double ar[], double length)
{
	double sum = 0;
	double max = ar[0];
	for (size_t i = 0; i < length; i++)
	{
		if (ar[i] >= max)
		{
			max = ar[i];
		}
		sum += ar[i];
	}
	return sum / max;
}


int main()
{
	const int SIZE = 4;
	double array[SIZE];
	array_input(array, SIZE);
	array_ms(array, SIZE);
	cout << "\nResult: " <<array_ms(array, SIZE) << endl;
	cout << endl;
	return 0;
}

