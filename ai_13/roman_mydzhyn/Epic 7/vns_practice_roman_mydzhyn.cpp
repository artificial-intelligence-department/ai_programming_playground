#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// вимога 4 - константа
const int CONST_VALUE = 1025;
const char *F2 = "F1.txt"; // Вимога 18

class Matrix // Власна додаткова умова
{
public:
	int size;
	double **elements; // вимога - 3 змінна з подвійною точністю; вимога 7 - двовимірний масив

	Matrix(int size) : size(size)
	{
		elements = new double *[size];
		for (int i = 0; i < size; i++)
		{
			elements[i] = new double[size];
		}
	}

	Matrix() // вимога 14 - застосував у методі класу Matrix
	{
		for (int i = 0; i < size; i++)
		{
			delete[] elements[i];
		} // вимога 10 - цикл for
		delete[] elements;
	}

	void populateMatrix(double (*func)(int, int))
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				elements[i][j] = func(i, j);
			}
		}
	}

	void sortCol()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size - j - 1; k++)
				{
					if (elements[k][i] > elements[k + 1][i])
					{
						double temp = elements[k][i];
						elements[k][i] = elements[k + 1][i];
						elements[k + 1][i] = temp;
					}
				}
			}
		}
	}

	void sortRows()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size - j - 1; k++)
				{
					if (elements[i][k] < elements[i][k + 1])
					{
						double temp = elements[i][k];
						elements[i][k] = elements[i][k + 1];
						elements[i][k + 1] = temp;
					}
				}
			}
		}
	}
};

double func1(int i, int j) // вимога 15 - Математичні операції та функції
{
	return sin(i * j);
}

double func2(int i, int j)
{
	return i * j;
}

int *numCalculate(Matrix &matrix)
{
	srand(time(0));
	int *sumArr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			int index = rand() % 10;
			sum += matrix.elements[index][i];
		}
		sumArr[i] = sum;
	}
	return sumArr;
}

bool Write_file(int *array) // вимога 16 write_file
{
	ofstream file(F2);
	if (!file)
	{
		return false;
	}
	for (int i = 0; i < 10; i++)
	{
		file << array[i] << " ";
	}
	file.close();
	return true;
}

int main()
{
	Matrix matrix(10);
	if (CONST_VALUE % 2 == 0)
	{
		matrix.populateMatrix(func1);
		matrix.sortCol();
	}
	else
	{
		matrix.populateMatrix(func2);
		matrix.sortRows();
	} // вимога 5 - умовні оператори та розгалуження

	int *sumArr = numCalculate(matrix); // вимога 6 - одновимірний масив
	if (Write_file(sumArr))
	{
		cout << "File saved successfully." << endl; // Вимога 18 - оператор виводу
	}
	else
	{
		cout << "Error writing file." << endl;
	}

	return 0;
}