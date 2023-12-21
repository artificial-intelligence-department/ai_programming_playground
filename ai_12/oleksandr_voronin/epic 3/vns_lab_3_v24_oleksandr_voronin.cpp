#include <iostream>
#include <cmath>

using namespace std;


double Y(double x)
{
    return log(1 / (2 + 2 * x + pow(x, 2)));
}

double SN(double x, double n) {
    
    double formul = pow(-1,n) * pow(1+x,2 * n)/n;
    double sum =0;

    for (int n = 1; n <= 40; n++) 
    {
        formul = pow(-1,n) * pow(1+x,2 * n)/n;
        sum += formul;
    }

    return sum;
}

double SE(double x, double epsilon = 0.0001) 
    {
    double n_n=1;
    double n1 = pow(-1,n_n) * pow(1+x,2 * n_n)/n_n;
    double sum = n1;

   
    for (int n = 1; fabs(n1) >= epsilon; ++n) {
        n1 = pow(-1,n) * pow(1+x,2 * n)/n;
        sum += n1;
    }
    return sum;
    }   
int main() {
    int n;
    double a = -2.0;
    double b = -0.1;
    double step = -0.19;
    double eps = 0.0001;
    double x = -2.0;
    while (x <= b) {
        cout << "  X = " << x << "   SN = " << SN(x,n) << "  SE = " << SE(x,eps) << "  Y = " << Y(x) << endl;
        x += step;
    }
    
}