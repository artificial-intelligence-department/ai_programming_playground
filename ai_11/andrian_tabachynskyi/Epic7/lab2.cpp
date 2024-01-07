#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a = 1;
    int b = 2;
    double z;

    
    for (double y = 1.0; y <= 2; y += 0.2) {
        for (double x = 1.0; x <= 2; x += 0.1) {
            if (x + y <= 1) {
                z = pow(a, x) + pow(b, y);
                cout << z << endl;
            }
            else {
                z = a * pow(x, 2) + log(b * x * y);
                cout << z << " ";          
            }
            
        }
        cout << endl;
    }

}