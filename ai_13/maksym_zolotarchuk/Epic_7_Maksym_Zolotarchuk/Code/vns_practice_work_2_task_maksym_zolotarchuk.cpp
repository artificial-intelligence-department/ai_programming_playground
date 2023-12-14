#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x, a;
	double h_x = 0.5;
	double h_a = 1;
	double y;

	for (double x = 1; x <= 8; x += h_x)
	{
		for (double a = 2; a <= 10; a += h_a)
		{

			if (a > x)
			{
				y = pow(a, 2) + x;
			}
			else if (a = x)
			{
				y = pow(a, 2);
			}
			else if (a < x)
			{
				y = pow(a, 2) - x;
			}


			cout << "y = " << y << endl;
		}
	}


	return 0;

}