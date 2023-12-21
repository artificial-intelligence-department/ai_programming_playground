#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n=1;
    double  sum=0;
    double epsilon = 0.0001;
    double an = 1; // n+1 член послідовності

    while (an >= epsilon)
    {
        
        sum += an;
        n++;
        an = an * (pow(n, n)) / (pow(1 + n, n));   
    }

    cout << sum << endl;
    return 0;
}
 