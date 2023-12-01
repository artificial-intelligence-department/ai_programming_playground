#include <iostream>
#include <stdio.h>
using namespace std;
// варіант 4
int main()
{
    int m,n;

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    cout << "The result of n++*m is: " << (n+1)*m << endl;

    int a = n++<m;
    cout << a << endl;

    int b = m-->m;
    cout << b;

    return 0;
}
