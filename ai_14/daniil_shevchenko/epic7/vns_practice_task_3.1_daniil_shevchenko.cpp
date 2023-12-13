#include <iostream>
#include <cmath>
using namespace std;
const double pi = 3.1415926535;
//Використано функції, їх параметри та аргументи(для подальшого виклику набору команд автоматично через виклик функції, функція має тип повернення double)(вимога 16)
double area(int a, int b, int angle)
{
	double S;
	S = 0.5 * a * b * sin(angle * pi / 180); //в синусі відбувається конвертація в радіани
	return S;
}
double area(double a, double b, double angle) //здійснено перевантаження функції для дробових аргументів(2 сторін і кута між ними) (вимога 12)
{
	double S;
	S = 0.5 * a * b * sin(angle * pi / 180); //в синусі відбувається конвертація в радіани
	return S;
}

int main()
{
	double a, b;
	cout << "Enter the 2 sides: ";
	cin >> a >> b; //викорстано користувацький ввід(вимога 21)
	double angle;
	cout << "Enter the angle in degrees: ";
	cin >> angle;
	double S = area(a, b, angle);
	cout << "The area equals " << S;
}