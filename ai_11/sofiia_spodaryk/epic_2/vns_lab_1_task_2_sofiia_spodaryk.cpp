#include <iostream>

using namespace std;
int main()
{
    int m, n;

    cout << "Початкові значення: m= ";
    cin >> m;
    cout << "n= ";
    cin >> n;

    int result1;
    result1 = m - ++n;
    cout << "Результат 1 = " << result1 << endl;

    int result2 = (++m > --n);
    cout << "Результат 2 = " << result2 << endl;

    int result3 = (--n < ++m);
    cout << "Результат 3 = " << result3 << endl;

    return 0;
}