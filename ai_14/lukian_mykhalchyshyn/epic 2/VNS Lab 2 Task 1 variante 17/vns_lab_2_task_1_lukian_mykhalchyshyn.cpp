#include <iostream>
#include <cmath>

using namespace std;
// умова an = 10^-n * (n-1)!

int main()
{
    int n;
    double an, sum = 0, factorial, e = 0.0001;

    cout << "Enter n \n";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        factorial = 1;
        for (int j = 1; j <= i; j++)
        {
            if (j != 1)
            {
                factorial *= j - 1;
            }
            else{ factorial=1;}
        }
        an = pow(10, -i) * factorial;
        if (an < e)
        {
            sum += an;
            cout << an << " ";
        }
    }
    cout << endl << sum << endl;

    return 0;
}