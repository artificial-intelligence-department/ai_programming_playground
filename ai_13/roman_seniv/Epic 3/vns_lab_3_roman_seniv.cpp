#include <iostream>
#include <cmath>
using namespace std;

int Factorial(int n){
    return n == 0 ? 1 : n*Factorial(n-1);
}

int main() {
    double e = M_E;
    double step=0.1;
    double sn, se, y;
    double accuracy = 0.0001;
for (double x=1; x<=2; x+=step){
    int n=15;
    sn=0.0;
     for (int i = 0; i <= n; i++) {
            sn += pow(x, i) / Factorial(i);
        }
        y= pow(e, x);
        int i=0;
        do {
            se =0.0;
            se =+ pow(x, i) / Factorial(i);
            i++;
        } while ( accuracy< pow(x, i) / Factorial(i));
        
        
        cout << "X:\t " << x << " SN:\t " << sn << " SE:\t " << se << " Y:\t " << y << "\n";
        
        }
        return 0;
       
        
}
