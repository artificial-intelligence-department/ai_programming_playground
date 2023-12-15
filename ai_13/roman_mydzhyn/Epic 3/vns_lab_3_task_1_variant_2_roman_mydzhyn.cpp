#include <iostream>
#include <cmath>
#include <cstdio>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif
using namespace std;

int main()
{
	int N = 40;
	
	double E = 0.0001;
	double X, SN, SE, s, Y;

	for (double i = 0.2 * M_PI; i <= 1.8 * M_PI; i += 0.16 * M_PI) // calculate x
	{
		SN = 0;
		X = i;
		for (int n = 1; n < N + 1; n++) // calculate sum of series n
		{
			SN += cos(n * X) / n; // general term
		}

		int m = 1;
		SE = 0;
		double t;
		do
		{
			t = cos(m * X) / m;
			SE += t;
			m++;
		} while (t < E); //

		Y = -1 * log(abs(2 * sin(X / 2)));
		printf(" x= %lf  SN = %lf  SE = %lf  Y = %lf\n", X, SN, SE, Y);
	}

	return 0;
}