#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double custom_function(double x)
{
	// Ввів підінтегральний вираз, тому що якщо робити довільний підінтегральний вираз, треба підключати зовнішню(нестандартну бібліотеку) бібліотеку, або застосовувати лямбда функції
	if (x == 0)
	{
		return 1;
	}
	else
	{
		return sin(x) / x;
	}
}

double imetrap(double a, double b, double epsilon, double (*func)(double))
{
	int n = 2;
	double h = (b - a) / n;
	double s1 = 0, s2 = 0;
	cout << "Intermediate values of the integral" << endl;
	do
	{
		s1 = s2;
		s2 = 0;
		for (int i = 1; i < n; i++)
		{
			s2 += func(a + i * h);
		}
		s2 = (s2 + func(a) / 2 + func(b) / 2) * h;
		cout << fixed << setprecision(7) << s2 << ", n=" << n << endl;
		n = 2 * n;
		h = (b - a) / n;
	} while (abs(s2 - s1) >= epsilon);
	return s2;
}

int main()
{
	double a, b, epsilon;

	cout << "Enter the lower limit of integration (a): ";
	cin >> a;

	cout << "Enter the upper limit of integration (b): ";
	cin >> b;

	cout << "Enter the desired accuracy (epsilon): ";
	cin >> epsilon;

	double s = imetrap(a, b, epsilon, custom_function);
	cout << "Integral = " << fixed << setprecision(7) << s << " with accuracy " << fixed << setprecision(4) << epsilon << endl;
	return 0;
} // у цьому коді я вирішив використати маніпулятор виводу fixed та setprecision() щоб вивести значення інтеграла та точність з фіксованою кількістю знаків після коми