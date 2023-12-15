#include <iostream>
#include <string>
#include <complex>

using namespace std;
int sum(int number1, int number2, int number3, int number4, int number5, int number6, int number7, int number8) {
    int result=number1*number2+number2*number3+number3*number4+number4*number5+number5*number6+number6*number7+number7*number8;
    return result;
}
int sum(int number1, int number2, int number3, int number4, int number5, int number6, int number7, int number8, int number9, int number10) {
    int result=number1*number2+number2*number3+number3*number4+number4*number5+number5*number6+number6*number7+number7*number8+number8*number9+number9*number10;
    return result;
}
int sum(int number1, int number2, int number3, int number4, int number5, int number6, int number7, int number8, int number9, int number10, int number11, int number12) {
    int result=number1*number2+number2*number3+number3*number4+number4*number5+number5*number6+number6*number7+number7*number8+number8*number9+number9*number10+number10*number11+number11*number12;
    return result;
}
int subtract(int a, int b) {
    return a - b;
}
complex<double> subtract(const complex<double>& a, const complex<double>& b) {
    return a - b;
}

int main() {
    cout << "Task 1:"<<endl;
    cout << "8 paramiters: " << sum(18, 1, 12, 2, 5, 7, 1, 3) << endl;
    cout << "10 paramiters: " << sum(5, 7, 8, 12, 16, 7, 5, 1, 3, 11) << endl;
    cout << "12 paramiters: " << sum(21, 2, 3, 9, 7, 5, 11, 13, 7, 5, 11, 12) << endl;
    cout << "Task 2:"<<endl;
    cout << "а) Result of subtract: " << subtract(10, 5) << endl;
    complex<double> complex1(4.0, 2.0);
    complex<double> complex2(1.5, 3.0);
    cout << "b) Result of complex subtract: " << subtract(complex1, complex2);
    return 0;
}
