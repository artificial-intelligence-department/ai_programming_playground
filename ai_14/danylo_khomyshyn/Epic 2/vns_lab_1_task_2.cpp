#include <iostream>

using namespace std;

int main()
{
    int n, m, result;
    cout << "Enter n and m: ";
    cin >> n >> m;

    m--;
    result = n-m;
    cout << "result: " << result << endl;

    m--;
    if (m < n)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    n++;
    if (n > m)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}