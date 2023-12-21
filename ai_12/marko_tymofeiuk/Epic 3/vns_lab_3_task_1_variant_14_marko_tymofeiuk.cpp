#include <iostream>
#include <cmath>

double a = M_PI/5, b = M_PI;
int k = 10;
double step = (b-a)/k;
const double epsilon = 0.0001;

int main(){
    for (double x = a; x <=b; x += step){
        double sn = 0.0, se = 0.0;
        double y = 0.25 * (pow(x, 2) - (pow(M_PI, 2)/3));

        for (int n = 1; n <= 20; n++){
            double an = pow (-1, n) * (cos(n*x)/pow(n, 2));
            sn += an;
        }
        int n = 1;
        double en = pow (-1, n) * (cos(n*x)/pow(n, 2));
        while (fabs(en) >= epsilon){
            se += en;
            n++;
            en = pow (-1, n) * (cos(n*x)/pow(n, 2));
        }
        std::cout << "X: " << x << "; SN = " << sn << "; SE = " << se << "; Y = " << y << std::endl;
    } 
    return 0;
}