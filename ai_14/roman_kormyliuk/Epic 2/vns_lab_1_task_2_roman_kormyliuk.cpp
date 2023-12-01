#include <iostream>
using namespace std;

int main() {
    int n, m, result;
    cout << "Enter values for n and m: ";
    cin >> n >> m;

    n++;
    m++;
    result = n * m;
    cout << "result: " << result << endl;

    m--;
    if (n < m)
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