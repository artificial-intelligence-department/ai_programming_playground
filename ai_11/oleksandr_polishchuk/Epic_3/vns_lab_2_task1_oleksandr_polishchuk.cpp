#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    int n=1;
    double a=1.0, s=0.0, factorial=1.0;
    while (a>0.0001)
    {   
        a=pow(10, (-n))*factorial;
        s+=a;
        n++;
        factorial*=(n-1);
    }
    cout << s;
    return 0;
}
