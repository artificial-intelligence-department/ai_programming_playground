#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

    int m, n;
    cout << "Write your number n: " << endl;
    cin >> n;
    cout << "Write your number m: " << endl;
    cin >> m;

    cout << "\n Значення виразу n++*m = " << n++ * m << endl;

    if ((n++ < m) == 1)
    {
        cout << "\n Значення виразу n++<m = True" << endl;
    }
    else
    {
        cout << "\n Значення виразу n++<m = False" << endl;
    }

    int a = m;
    if (a-- > m == 1)
    {
        cout << "\n Значення виразу m-->m = True" << endl;
    }
    else
    {
        cout << "\n Значення виразу m-->m = False" << endl;
    }
    cout << '\n';
    return 0;
}