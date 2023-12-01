#include <iostream>
#include <cmath>

using namespace std;

int main() {
   int b=1;
   double a=0.1, x, epsilon=0.0001, y;

    for ( x = a; x < b ; x+=(b-a)/10) {
        double  a_n=0, s_n=0, s_n1=0;
        y = atan(x);
        //для заданого значення n:
        for (int n = 0; n <= 40; n++) {
            a_n = pow(-1, n) * (pow(x, (2 * n + 1))) / (2 * n + 1);
            s_n += a_n;
        }
        // для заданої точності epsilon:
        a_n=1;
        for(int n=0; abs(a_n)> epsilon; n++){
            a_n = pow(-1, n) * (pow(x, (2 * n + 1))) / (2 * n + 1);
            s_n1 += a_n;
        }
        cout << "x=" << x << "  s_n=" << s_n << "  s_n1=" << s_n1 << "  y=" << y<<endl;
    }

    return 0;
}




