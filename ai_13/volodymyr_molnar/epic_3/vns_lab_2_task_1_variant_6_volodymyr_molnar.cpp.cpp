#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n{1};
	cin >> n;
	double sum{};
	for (size_t i = 0; i < n; i++)
	{
		sum += 1 / pow(2,i) + 1 / pow(3, i);
	}
	cout << sum;
}