#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a = 0.1;
    double y = 0;
    for (double x = 0.5; x <= 3.1; x+=0.2)
    {
        if (x<=2)
        {
            y += tan(abs(x-2*a));
        }
        else if (x > 2){
            y += cos(a*x+2);
        }
        a+=0.3;
    }
    cout << y;
    return 0;
}