#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double n=1,sum=0,ntuj,factorial=1,e=0.0001;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
        ntuj = ((pow(factorial, 2))/(pow(2,pow(n,2))));
        sum += ntuj;
        if (ntuj < e)
        {
            cout<<"Точність досягнута, сума дорівнює:"<<sum;
            return 0;
        }
    }
    cout<<"Точність не досягнута, сума дорівнює:"<<sum; 
    return 0;
}