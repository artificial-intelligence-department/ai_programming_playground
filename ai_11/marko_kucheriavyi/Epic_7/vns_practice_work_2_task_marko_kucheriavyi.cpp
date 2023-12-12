#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double x = 1, y, a = 2, b = 3, c = 7;
    if (x < 2){
        y = pow(a, b-x) + c;
    }
    else if (x >= 2 && x <= 4){
        y = pow(b, c-x) + a;
    }
    else if (x > 4){
        y = pow(c, a-x) + b;
    }
    cout << "y = " << y;
    return 0;
}