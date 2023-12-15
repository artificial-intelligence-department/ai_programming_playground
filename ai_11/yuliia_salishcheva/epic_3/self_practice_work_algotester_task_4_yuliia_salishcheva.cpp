//Завдання 4. Написати перевантажені функції і протестувати їх в основній програмі :
//■ Знаходження площі прямокутника;
//■ Знаходження площі трикутника;
//■ Знаходження площі круга;

#include <iostream>
using namespace std;

int square(int a, int b)
{
	return a * b;
}

double square(int a, int b, int c)
{
	double p, s;
	p = (a + b + c) / 2;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
}
double square(double a)
{
	const double p = 3.14;
	double s;
	s = a * p * p;
	return s;
}

int main()
{
	cout <<"Rectangle square = " << square(2, 10) << endl;
	cout << "Triangle square = " << square(2, 6, 6) << endl;
	cout << "Circle square = " << square(4.5) << endl;
}
