#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    const int n = 40;
    double a, step, Sum, E, an;
    double X, Y, SE, SN;
    int k, b;   
    k = 10;     
    E = 0.0001;
    a = 0.1;
    b = 1;
    an = 0;
    step = (b - a) / k;
    
    for(X = a; X <= b; X += step){

        //знаходження суми для заданого n

        SN = 0;
        for (int i = 0; i <= n; i++){
            SN += pow(-1, i) * pow(X, 2 * i + 1) / (2 * i + 1);
        }

        //знаходження суми для заданої точності ε (ε=0.0001)
        
        SE = 0;
        int j = 0;
        do{
            an = pow(-1, j) * pow(X, 2 * j + 1) / (2 * j + 1);
            SE += an;
            j++;
        }while(fabs(an) > E);

        //знаходження значення функції

        Y = atan(X);

        cout << "X - " << fixed << setprecision(2) << X;
        cout << "\t\tSN - " << setprecision(5) << SN;
        cout << "\t\tSE - " << setprecision(5) << SE;
        cout << "\t\tY - " << setprecision(5) << Y << endl;
    }
    return 0;
}