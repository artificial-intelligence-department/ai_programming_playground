#include <iostream>
#include <cmath>
using namespace std;

int main()
{
 
	double x = 1.2;
	double y = 0.8;

	double s, z;

	s = 1 + x + (pow(x, 2)) / 2 + (pow(x, 3)) / 3 + (pow(x, 4)) / 4;
	
	z = sin(pow(x, 3)) + pow(cos(y), 2);

	cout << "Z = " << z << endl;
	cout << "S = " << s << endl;

	return 0;

}