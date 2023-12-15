#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x, y, z;
	double h = 0.5; // крок з яким змінюється x

	for (x = -2.5; x <= 2; x += h)
	{
		z = abs(x) + pow(x, 2);
		y = (pow(sin(2 + x), 2) / (2 + x)) * z;
		cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
	}

	return 0;
}
