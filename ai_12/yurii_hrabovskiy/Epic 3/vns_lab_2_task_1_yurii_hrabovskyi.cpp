#include <iostream>
#include <math.h>
using namespace std;

int main()
{   int n=2;
    float sum=0;
    float a=1;
    
    while (a>=0.0001){
        a=n/(pow(n-1,2));
        sum+=a;
        n++;
    }

    cout<<sum<<endl;
    
    return 0;
}
