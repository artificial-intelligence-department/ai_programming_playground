#include <iostream>
#include <math.h>
using namespace std;
 
int main()
{
    float sum=0;
    for(int n = 1 ; n < 8; n++)
    {
        sum += n*n*exp(-sqrt(n));
        cout << sum << "\n";
    }
    return 0;
}
