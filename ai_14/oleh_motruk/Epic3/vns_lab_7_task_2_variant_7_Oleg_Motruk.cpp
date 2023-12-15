#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;


double diff_div(double a , double b){
    return a / b;
}

void diff_div(double real1, double imag1 , double real2, double imag2 , double& result_real,double& result_imag){
    result_real = (real1 * real2 + imag1 * imag2)/(pow(real2, 2) + pow(imag2, 2));
    result_imag = (real2 * imag1 - real1 * imag2)/(pow(real2, 2) + pow(imag2, 2));

    if(result_imag < 0){
        cout << result_real << " - " << result_imag * -1 << "i" << endl;
    }
    else
        cout << result_real << " + " << result_imag << "i" << endl;
}

int main() {
    double resultreal , resultimag;
    double complex1_real = 2 , complex1_imag = 3;
    double complex2_real = 1 , complex2_imag = 2;


    cout << diff_div(10 , 4) << endl;

    diff_div(complex1_real, complex1_imag, complex2_real , complex2_imag, resultreal , resultimag);

    
    return 0;
}
