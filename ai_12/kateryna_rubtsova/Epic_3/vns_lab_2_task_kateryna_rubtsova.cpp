#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;

int main()
{
    double epsilon = 0.0001;
    double sum; 
    double an = 1.0; 
    int n;
    
    cin >> n;

    while (an <= epsilon){
        sum += an; 
        an = -an * ((pow(n+1, n+1))/pow(n, 2)); 
    }

    cout << "Сума ряду з точністю e = 0.0001 дорівнює " << sum << endl;

 

    return 0;

}