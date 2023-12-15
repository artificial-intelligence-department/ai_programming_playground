#include <iostream>
#include <cmath>

using namespace std;

int main() {
  // Get the values of a and b from the image
  double a = 1000;
  double b = 0.0001;

  // Calculate the value of the expression
  double result = (a + b) * pow((a + b), 2) - a * pow(a, 2) / (3 * a * pow(b, 2) + b * pow(a, 3) + 3 * pow(a, 2) * b);


  cout << result << endl;

  return 0;
}
