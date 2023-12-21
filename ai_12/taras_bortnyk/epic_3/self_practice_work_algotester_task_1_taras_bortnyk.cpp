#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int  SIZE = 5;

void fillAndShowArray(int[][SIZE], const int size);
int findMinElement(int[][SIZE], const int size);
int findMaxElement(int[][SIZE], const int size);

int main()
{
	setlocale(LC_ALL, "rus");

	int matrix[SIZE][SIZE] = {};

	fillAndShowArray(matrix, SIZE); //заповняємо і показуємо масив

	cout << endl;
	cout << "min: " << findMinElement(matrix, SIZE) << endl;
	cout << "max: " << findMaxElement(matrix, SIZE) << endl;

	return 0;
}

void fillAndShowArray(int arr[][SIZE], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "| ";
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = 30 + rand() % 31;

			cout << arr[i][j] << " ";
		}
		cout << " |" << endl;
	}
}

int findMinElement(int arr[][SIZE], const int size)
{
	int min = arr[0][0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] < min)
				min = arr[i][j];
		}
	}
	return min;
}

int findMaxElement(int arr[][SIZE], const int  size)
{
	int max = arr[0][0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] > max)
				max = arr[i][j];
		}
	}
	return max;
}