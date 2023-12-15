#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a = 2.4;

    for (double x = -3; x <= 3; x += 0.5){
        double z = pow(a, x) * log(abs(x + pow(2, 3)));
        cout << "z(" << x << ") = " << z << endl;
    }

return 0;
}