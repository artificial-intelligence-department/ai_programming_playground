#include <iostream>

using namespace std;

int main()
{
    int n, m, result;
    cout << "Enter n and m: ";
    cin >> n >> m;

    n++;
    result = m - n;
    cout << "result: " << result << endl;

    m++;
    n--;
    if (m > n)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    n--;
    m++;
    if (n < m)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}