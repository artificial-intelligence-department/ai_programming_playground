#include <iostream>
#include <math.h>

using namespace std;
// an=n!/3n^n
// an+1/an=(n/(n+1))^n
// an+1=an*(n/(n+1))^n
int main(){
    int n = 1;
    double a, f=1, s=0, e=0.0001;
    a = f/(3*pow(n,n));
    while (a >= e)
    {
       s += a;
       a = a*(pow(n,n)/pow(n+1,n));
       n++;
    }
    cout << "sum: " << s << endl; 
    
    return 0;
}