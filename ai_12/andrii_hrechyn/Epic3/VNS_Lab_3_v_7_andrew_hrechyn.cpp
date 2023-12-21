#include <iostream>
#include <cmath> 
using namespace std;

int main () {
    double x, a = 0.1, b = 1, k = 10, eps = 0.0001, n = 10, sn = 0, se = 0, zen, y = 0;

    for(x = 0.1; x <= 1; x += 0.09){
        sn = 1; 
        zen = 1;
        se = 0;

        for(int i = 1; i <= n; i++){
            zen *= -1 * (x * x) / (2 * i);
            sn += zen;
        }

        int n = 1;
        zen = 1;
        while(abs(zen) > eps){
            se += zen;
            zen *= -1 * (x * x) / (2 * n);
            n++;
        }

        y = cos(x);

        cout << "X = " << x << "  " << " SN = " << sn << "  " << " SE = " << se << "  " << " Y = " << y << endl;
    }

    return 0;
}
