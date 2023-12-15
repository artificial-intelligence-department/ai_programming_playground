#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double x1, y1, z1;
	cin >> x1 >> y1 >> z1;
	double x2, y2, z2;
	cin >> x2 >> y2 >> z2;
	double x3, y3, z3;
	cin >> x3 >> y3 >> z3;

	double len_1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
	double len_2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2) + pow(z2 - z3, 2));
	double len_3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2) + pow(z1 - z3, 2));

	double p = (len_1 + len_2 + len_3) / 2;
	double square = sqrt(p * (p - len_1) * (p - len_2) * (p - len_3));

	cout << fixed << setprecision(6) << square << endl;

	return 0;
}
// у цьому коді я вирішив використати маніпулятор виводу fixed та setprecision() щоб вивести значення площі трикутника з фіксованою кількістю знаків після коми