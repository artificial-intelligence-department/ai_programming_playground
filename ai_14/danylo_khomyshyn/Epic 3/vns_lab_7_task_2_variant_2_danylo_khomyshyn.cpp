#include <iostream>

using namespace std;

//diysna chastyna
double add(double x, double y) {
  return x + y;
}


struct Complex {
  double x;
  double y;

  Complex(double x, double y) : x(x), y(y) {}

  Complex operator+(const Complex& other) const {
    return Complex(x + other.x, y + other.y);
  }
};


Complex add(Complex x, Complex y) {
  return x + y;
}

int main() {
  double a = 2.5;
  double b = 3.8;

  //diysna chastyna
  double resD = add(a, b);
  cout << "a + b = " << resD << endl;

  Complex c(1.2, 5.5);
  Complex d(3.3, 6.9);

  //uyavna chastyna
  Complex resU = add(c, d);
  cout << "c + d = " << resU.x << " + " << resU.y << "i" << endl;

  return 0;
}
