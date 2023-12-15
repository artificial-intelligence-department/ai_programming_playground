#include <iostream>

class Complex {
private:
double m_real;
double m_imagine;

public:
Complex(double r=0, double im=0): m_real(r), m_imagine(im) {}

double getReal() {return m_real;}
double getImagine() {return m_imagine;}
};

Complex minus(Complex first, Complex second) {
    return Complex(first.getReal() - second.getReal(), first.getImagine() - second.getImagine()); 
}

std::ostream& operator<<(std::ostream &out, Complex number) {
    out << "(" << number.getReal() << "," << number.getImagine() << ")";
    return out;
}

double minus(double first, double second) {return first - second;}

int main() {
    Complex a(5,6), b(1,1);
    std::cout << minus(4, 3) << '\n' << minus(a,b);
    return 0;
}
