#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double factorial=1;
    double n=1;
    double a10=0;
    double n_number=0;

    for (int i=0;i<10;i++)
    {
        n_number=factorial/pow(n,sqrt(n));
        a10+=n_number;
        n++;
        factorial*=n;
    }

    cout<<"Result is: "<<a10;

    return 0;
}
