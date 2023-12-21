#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	float a = (float)1000;
	float b = 0.0001;
	float x = pow(a + b, 3);
	float y = pow(a, 3);
	float z = x - y;
	float m = 3 * a * pow(b, 2);
	float n = pow(b, 3);
	float p = 3 * pow(a, 2) * b;
	float zz = m +
	float final = z / zz;
	cout << final << endl;
    	
    double a1 = (double)1000;
	double b1 = 0.0001;
	double x1 = pow(a1 + b1, 3);
	double y1 = pow(a1, 3);
	double z1 = x1 - y1;
	double m1 = 3 * a1 * pow(b1, 2);
	double n1 = pow(b1, 3);
	double p1 = 3 * pow(a1, 2) * b1;
	double zz1 = m1 + n1 + p1;
	double final1 = z1 / zz1;
	cout << final1;
}