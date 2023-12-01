#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n=1;
    double an=(2*n-1)/pow(2,n), S;
    do
    {
    an *= (2*n+1)/(4*n-2);
    S+=an;
    n++;
    }
    while  (an>=0.0001);

    cout<<S;

return 0;
}
