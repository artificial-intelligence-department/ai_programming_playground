#include <iostream>
using namespace std;

int main()
{
    float a, a3, b, c, c3, d, b3, e, m, n, result;
    cout << "Enter a value of 'a': ";
    cin >> a;
    cout << "Enter a value of 'b': ";
    cin >> b;

    c = a + b;
    c3 = c*c*c;
    a3 = a*a*a;
    m = c3 - a3;
    d = 3*a*b*b;
    b3 = b*b*b;
    e = 3*a*a*b;
    n = d + b3 + e;
    result = m / n;

    cout << "The result is: " << result << endl;
    return 0;
}