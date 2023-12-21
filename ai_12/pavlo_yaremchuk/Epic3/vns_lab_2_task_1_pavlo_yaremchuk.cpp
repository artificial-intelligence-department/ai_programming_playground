#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    double eps = 0.0001, a, sum = 0.0, S;
    int n;
    cin >> n;
    for (a = 1; fabs(a) > eps; n++)
    {
        a = (pow (-1, n-1))/(pow (n, n)) * (-pow(n, n)/pow(n + 1, n + 1));
        sum += a;
    }
    S = 1 + sum;
    cout << "Сума ряду з точністю epsilon = 0.0001 дорівнює: " << S;
    return 0;
}