#include <iostream>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	bool task2 = ++m > --n;
	bool task3 = --n < ++m;

	cout << "\n\n1 = " << m - ++n << endl;
    if (task2)
        cout << "\n\n2 = True" << endl;
    else
        cout << "\n\n2 = False" << endl;
    if (task3)
        cout << "\n\n3 = True" << endl;
    else
        cout << "\n\n3 = False" << endl;
}