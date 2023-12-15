#include <iostream>
#include <cmath>
using namespace std;

int main(){

    const double epsilon = 0.0001;
    double n = 1;

    // a(1) = (1/10^1) * 0! = 0.1
    double a = 0.1;
    double sum = a;


    while (a>epsilon){
        a = a * (n/10);
        sum += a;
        n++;
    }
    cout << sum << endl;

    return 0;
}