#include <iostream>
#include <cmath>

using namespace std;

// global
double epsilon = 0.0001;

int factorial(int n) {
  if (n == 0) 
    return 1; 

  return n * factorial(n - 1);
}

double sum_elemets(int n) {
  double term = factorial(n) / pow(n, n);

  if (term < epsilon) 
    return term;

  return term + sum_elemets(n + 1);
}


int main() {
  double sum = sum_elemets(1);

  cout << "S: " << sum << endl;

  return 0;
}
