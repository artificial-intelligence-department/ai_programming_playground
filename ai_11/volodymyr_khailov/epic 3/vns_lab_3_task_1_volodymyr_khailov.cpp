#include <iostream>
#include <cmath>

using namespace std;

int factorial(int n) {
  if (n == 0) 
    return 1; 

  return n * factorial(n - 1);
}


int main() {
  double a = 0.1;
  double b = 1;

  double step = (b-a)/10;

  int n = 10;
  double epsilon = 0.0001;

  // Перший цикл  
  for (double x = a; x <= b; x+=step) {

    double s_n = 0, s_e = 0;

    int i = 0;
    double term = (pow(x,2*i) * (2*i + 1)) / factorial(i);

    // Розрахунок s_n та s_e в одному циклі while перевіряючи умову залежно від тояності або кількості членів ряду
    while (term > epsilon || i <= n){
      if (i != n)
        s_n += term;

      if (term > epsilon) 
        s_e += term;

      term = (pow(x,2*i) * (2*i + 1)) / factorial(i) ;
      i++;  
    }

    // Розрахунок точного значення функції
    double y = (1 + 2 * x * x) * exp(x * x);


    printf("X = %.2f\tSN = %.6f\tSE = %.6f\tY = %.6f\n", x, s_n, s_e, y);
  }

  return 0;
}
