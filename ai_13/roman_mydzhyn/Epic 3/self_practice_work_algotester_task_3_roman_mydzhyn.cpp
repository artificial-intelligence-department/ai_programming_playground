#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long long int n[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
	long long int c;
	int result = 0;
	cin >> c;
	for (int i = 0; i < 9; i++)
	{
		result += c / n[i];
		c = c % n[i];
	}
	cout << result << endl;

	return 0;
}