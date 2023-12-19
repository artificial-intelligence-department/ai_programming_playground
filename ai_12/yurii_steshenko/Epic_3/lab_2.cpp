#include<cmath>
#include <iostream>
using namespace std;
int main()
{
    double a=0;
    for (int n = 2; n <= 15; n++)
    {
        a+=pow(n,log(n))/pow(log(n),n);
    }
    cout<< a;
    return 0;
}