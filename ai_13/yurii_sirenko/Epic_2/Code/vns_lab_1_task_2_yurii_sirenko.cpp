#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int m, n;
    cout << "enter m value: ";
    cin >> m;
    cout << "enter n value: ";
    cin >> n;
    int c = --m - ++n;
    bool d = m*n < n++;
    bool e = n-- > m++;

    cout << c;
    cout << "\n------\n";
    cout << d;
    cout << "\n------\n";
    cout << e;
}
