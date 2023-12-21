#include <iostream>
#include <cmath>
using namespace std;
int fl(int l){
    if (l == 0 || l == 1) {
        return 1;
    } else {
        return l * fl(l - 1);
    }
}
int main(){
    double a = 0.1, b = 1;
    int k = 10;
    double c = (b - a) / k;
    for (double x = a; x <= b; x += c){
        double y = sin(x);
        double sumN = x;
        double termN = 1;
        for (int n = 1; n <= 10; n++){
            termN *= pow(-1, n) * pow(x, 2*n + 1)/fl(2*n + 1);
            sumN += termN;
        }
        double sumE = x;
        double termE = 1;
        for (int n = 1; fabs(termE) >= 0.0001; n++){
            termE *= pow(-1, n) * pow(x, 2*n + 1)/fl(2*n + 1);
            sumE += termE;
        }
        cout << "x = " << x << "  ";
        cout << "sn = " << sumN << " ";
        cout << "se = " << sumE << " ";
        cout << "y = " << y;
        cout << endl;
    }
    return 0;
}