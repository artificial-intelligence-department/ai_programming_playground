#include <cmath>
#include <iostream>

using namespace std;



int main() {
  double a = 0.5;
  double b = 2.9;
  double x = 0.3;

  double alpha_result =(pow(a,x) + pow(b,-x) * sin(a - b)) / sqrt(abs(a - b));
  double beta_result = a * exp(-sqrt(a)) * cos(b * x / a);

  cout << "alpha = " << alpha_result << endl;
  cout << "beta = " << beta_result << endl;

  return 0;
}