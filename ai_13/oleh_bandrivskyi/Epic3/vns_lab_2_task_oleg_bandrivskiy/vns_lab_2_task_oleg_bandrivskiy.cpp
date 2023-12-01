#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a;
    double n = 2;
    double sum = 0;
    const double e = 0.0001;



    do{
        a = n/pow((n-1), 2);
        sum += a;
        n++;
    }while(a > e);

    cout << "Sum:" << sum;
    

    return 0;
}