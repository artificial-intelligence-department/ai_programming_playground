#include <iostream>
#include <cmath>

using namespace std;

int factorial(int n){
    long factorial = 1.0;
    for(int i = 1; i <= n; i++){
        factorial *= i;
    }
    return factorial;
}


double calculate(double num, double x, double n){

    double sum;

    sum = num*(2*x/factorial(n));

       

    return sum;
}

const double e = exp(1.0);
int main(){
    double g;
    for(double x = 0.1; x < 1; x+=0.09){
        double n = 1;
        double sum = 0;
        g = calculate(1,x,n);
        do{
            g = calculate(g,x,n);
            sum += g;
            n++;
        }while(abs(g)>e);
        g = calculate(1,x,n);
        n = 1; 
        double sum2 = 0;
        for(int n = 1; n < 20; n++){
            g = calculate(g,x,n);
            sum2 += g;
            n++;
        }
        double sum3 = pow(e, 2*x);

        cout << "X=" << x << "  ";
        cout << "SN=" << sum2 << "  ";
        cout << "SE=" << sum << "  ";
        cout << "Y=" << sum3 << endl;
        
    }

    return 0;
}