#include <iostream>
#include <cmath>

using namespace std;

double log_dec(int number){
    if(number <= 0){
        cout << "error" << endl;
        return 0;
    } else{
        return log10(number);
    }
}
double log_dec(double number){
    if(number <= 0){
        cout << "error" << endl;
        return 0;
    } else{
        return log10(number);
    }
}

double ln(int number){
    if(number <= 0){
        cout << "error" << endl;
        return 0;
    } else{
        return log(number);
    }
}
double ln(double number){
    if(number <= 0){
        cout << "error" << endl;
        return 0;
    } else{
        return log(number);
    }
}

int main(){
    int number1 = 100;
    double number2 = 56.525;
    double log10_int = log_dec(number1);
    double log10_double = log_dec(number2);
    double ln_int = ln(number1);
    double ln_double = ln(number2);
    cout << "log10(" << number1 << ") = " << log10_int << endl;
    cout << "log10(" << number2 << ") = " << log10_double << endl;
    cout << "log(" << number1 << ") = " << ln_int << endl;
    cout << "log(" << number2 << ") = " << ln_double << endl;
    return 0;
}