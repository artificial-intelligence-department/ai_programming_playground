#include <iostream>
using namespace std;

int main()
{
    int m, n, c, a, b;
    cin >> m;
    cin >> n;
    c= ++n*++m;
    a=m++<n;
    b=n++>m;
    cout << c << " " << a << " " << b << endl;
    return 0;
}