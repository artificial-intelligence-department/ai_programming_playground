#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double n=1;
    double epsilon = 0.0001;
    double a = 0.1;
    double sum=a;
    while (a>epsilon)
    {
        a=a*(n/10);
        sum+=a;
        n++;
    }
     cout << sum << endl;

    return 0;
}