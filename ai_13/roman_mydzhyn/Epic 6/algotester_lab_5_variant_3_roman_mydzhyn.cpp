#include <iostream>
#include <iomanip>
using namespace std;

void paint(int **matrix, int y, int x, int power, int N, int M);
void paintPositiveX(int **matrix, int y, int x, int power, int N, int M);
void paintNegativeX(int **matrix, int y, int x, int power, int N, int M);
void paintPositiveY(int **matrix, int y, int x, int power, int N, int M);
void paintNegativeY(int **matrix, int y, int x, int power, int N, int M);

void paint(int **matrix, int y, int x, int power, int N, int M)
{
	paintPositiveX(matrix, y - 1, x - 1, power, N, M);
	paintNegativeX(matrix, y - 1, x - 2, power - 1, N, M);
}

void paintPositiveX(int **matrix, int y, int x, int power, int N, int M)
{
	if (x >= 0 && x < M)
	{
		paintPositiveY(matrix, y, x, power, N, M);
		paintNegativeY(matrix, y - 1, x, power - 1, N, M);
		paintPositiveX(matrix, y, x + 1, power - 1, N, M); // рекурсивно розмальовую праворуч
	}
}

void paintNegativeX(int **matrix, int y, int x, int power, int N, int M)
{
	if (x >= 0 && x < M)
	{
		paintPositiveY(matrix, y, x, power, N, M);
		paintNegativeY(matrix, y - 1, x, power - 1, N, M);
		paintNegativeX(matrix, y, x - 1, power - 1, N, M);
	}
}

void paintPositiveY(int **matrix, int y, int x, int power, int N, int M)
{
	if (y >= 0 && y < N)
	{
		matrix[y][x] = power; // задаю значення в матриці
		if (power > 0)
		{
			power--;
		}
		paintPositiveY(matrix, y + 1, x, power, N, M);
	}
}

void paintNegativeY(int **matrix, int y, int x, int power, int N, int M)
{
	if (y >= 0 && y < N)
	{
		matrix[y][x] = power; // задання значення в матриці
		if (power > 0)
		{
			power--;
		}
		paintNegativeY(matrix, y - 1, x, power, N, M);
	}
}

int main()
{
	int N, M, x, y;
	cin >> N;
	cin >> M;
	cin >> y;
	cin >> x;

	int biggest = N + M;
	int **matrix = new int *[N];
	int i = 0;
	while (i < N)
	{
		matrix[i] = new int[M]; // виділення пам'яті для матриці
		i = i + 1;
	}

	paint(matrix, y, x, biggest, N, M);
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < M; k++)
		{
			setw(biggest); // встановлення ширини виведення
		}
	}

	int min = matrix[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (matrix[i][j] < min)
				min = matrix[i][j]; // пошук мінімального значення в матриці
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << matrix[i][j] - min << " "; // вивід матриці з обчисленням мінімального значення
		}
		cout << endl;
	}

	i = 0;
	while (i < N)
	{
		delete[] matrix[i]; // звільнення пам'яті для кожного рядка матриці
		i = i + 1;
	}
	delete[] matrix; // звільнення пам'яті для pointer'ів на рядки

	return 0;
}
