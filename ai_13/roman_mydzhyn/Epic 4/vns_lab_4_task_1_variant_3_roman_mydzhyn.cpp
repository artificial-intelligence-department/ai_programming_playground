#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr))); // для того, щоб кожен раз виводило нові значення

	const int arSIZE = 10;
	int randAr[arSIZE];

	for (int i = 0; i < arSIZE; ++i)
	{
		randAr[i] = rand() % 10;
	}

	cout << "Початковий масив цілих чисел:" << endl;
	for (int i = 0; i < arSIZE; ++i)
	{
		cout << randAr[i] << " ";
	}
	cout << endl;

	// Знищити перший елемент, який дорівнює 0.
	int newSize = arSIZE;
	for (int i = 0; i < newSize; ++i)
	{
		if (randAr[i] == 0)
		{
			for (int j = i; j < newSize - 1; ++j)
			{
				randAr[j] = randAr[j + 1];
			}
			--newSize;
			break;
		}
	}

	// M[I-1]+2.
	for (int i = 0; i < newSize; ++i)
	{
		if (randAr[i] % 2 == 0 && newSize < arSIZE)
		{
			for (int j = newSize; j > i + 1; --j)
			{
				randAr[j] = randAr[j - 1];
			}
			randAr[i + 1] = randAr[i - 1] + 2;
			++newSize;
			++i; // Пропускаю наступний елемент, тому що додав новий елемент
		}
	}

	cout << "Масив після додавання елемента:" << endl;
	for (int i = 0; i < newSize; ++i)
	{
		cout << randAr[i] << " ";
	}
	cout << endl;

	return 0;
}
