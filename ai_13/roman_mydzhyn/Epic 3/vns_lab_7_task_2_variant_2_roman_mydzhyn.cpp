#include <iostream>
#include <complex>

using namespace std;

// Функція для додавання дійсних чисел чисел (float)
void Add(float x, float y)
{
	cout << "Функція для додавання дійсних чисел (float)" << endl;
	cout << x << " + " << y << " = " << (x + y) << endl;
}

// Функція для додавання комплексних чисел (float)
void Add(float x1, float xi1, float x2, float xi2)
{
	cout << "Функція для додавання комплексних чисел (float)" << endl;
	cout << "(" << x1 << " + " << xi1 << "i) + (" << x2 << " + " << xi2 << "i) = " << x1 + x2 << " + " << xi1 + xi2 << "i" << endl;
}

int main()
{
	float x = 5.5, y = 7.8;
	Add(x, y); // Викликаємо функцію для додавання дійсних чисел (float)

	Add(2.0, 2.5, 3.0, 0.1); // Викликаємо функцю для додавання комплексних чисел (float)

	return 0;
}
