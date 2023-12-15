#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cout << "Enter the number of minutes: ";
	cin >> a;
	b = a / 60; // к-сть хвилин
	c = a % 60; // залишок к-сті хвилин
	cout << a << " min - " << b << " hours " << c << " minutes" << endl;
	return 0;
}
