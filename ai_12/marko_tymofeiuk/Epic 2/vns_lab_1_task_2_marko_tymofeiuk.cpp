#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter a random number n: \n";
    cin >> n;
    cout << "Enter a random number m: \n";
    cin >> m;
    int a = --m - ++n;
    cout << "--m-++n: " << a << endl;
    int b = m * n < n++;
    cout << "m*n<n++:  " << b << endl;
    int c = n--> m++;
    cout << "n-->m++: " << c << endl;

    return 0;
}