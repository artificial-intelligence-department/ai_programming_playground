#include <iostream>
using namespace std;

int main()
{
	double m, n;
	cin >> m >> n;
	cout << (n++ * m) << endl;
	cout << (n++ < m) << endl;
	cout << (m-- > m) << endl;
	return 0;
}