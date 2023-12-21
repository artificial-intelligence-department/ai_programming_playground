#include <iostream>

using namespace std;

struct complex {
    double real;
    double imaginary;
};

int Multiply(int a, int b) {
    return a * b;
}

complex Multiply(complex a, complex b) {
    complex result{};
    result.real = a.real * b.real - a.imaginary * b.imaginary;
    result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return result;
}

int main() {
    cout << Multiply(5, 6) << endl;
    complex complRes = Multiply(complex{2, 6}, complex{1, 3});
    cout << "Real: " << complRes.real << "; Imaginary: " << complRes.imaginary;
    return 0;
}
