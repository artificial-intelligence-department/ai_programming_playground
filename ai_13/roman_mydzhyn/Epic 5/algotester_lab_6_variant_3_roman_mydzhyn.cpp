#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int size, rows, cols;
	cin >> size;
	vector<vector<int>> matrix(size, vector<int>(size));

	for (rows = 0; rows < size; rows++)
	{
		string input;
		cin >> input;
		for (cols = 0; cols < size; cols++)
		{
			matrix[rows][cols] = input[cols] - '0';
		}
	}

	int queries, q, a;
	cin >> queries;

	for (q = 0; q < queries; q++) // цикл по запитах
	{
		vector<int> result; // створення вектора для зберігання результатів

		int r, c;
		cin >> r >> c;
		r--, c--;

		if (matrix[r][c] != 0)
		{
			cout << "1" << endl // вивід к-сті елементів
				  << matrix[r][c];
			cout << endl << endl;
		}

		if (matrix[r][c] == 0)
		{
			int i, i1, j;
			i = r, j = c;
			for (i1 = 1; i1 <= size; i1++) // цикл по можливим значенням
			{
				int count = 0;
				for (i = 0; i < size; i++) // цикл по елементам рядка та стовпця
				{
					if (matrix[i][c] == i1 || matrix[r][i] == i1) // якщо поточне значення вже є в рядку або стовпці
						count++;
				}
				if (count == 0)
					result.push_back(i1); // додаємо його до результату
			}

			cout << result.size() << endl;		// вивід к-сті елементів
			for (i = 0; i < result.size(); i++) // цикл по результатам
			{
				cout << result[i] << " ";
			}
			cout << endl << endl;
		}
	}
	return 0;
}
