#include <iostream>
#include <cmath>

using namespace std;

int n = 35;
double sum=0, x, i;

int main()
{
    for (int i = 1; i <= n; i++)
    {
        x=0.02*i;
        sum+= pow(x, i) * cos(M_PI/3) / i;
    }
    cout << "a)Sum = " << sum << endl;

    cout << "b)Sum = " << round((sum)*10000)/10000 << endl;

    return 0;
}
