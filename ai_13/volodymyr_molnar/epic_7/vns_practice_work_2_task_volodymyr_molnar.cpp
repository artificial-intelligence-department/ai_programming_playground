#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double result{},x;
	cout << "enter: ";
	cin >> x;
	for (size_t i = 1; i < 10; i++)
	{
		result += pow(x, i) / i;
	}
	cout << result;
    return 0; 
}