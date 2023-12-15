#include <cstdarg>
#include <iostream>

using namespace std;

double mult(int n, ...) {
  double res = 1;
  va_list args;
  va_start(args, n);
  for (int i = 0; i < n; i++) {
    res *= va_arg(args, double);
  }
  va_end(args);
  return res;
}

int main() {
  double a[] = {1.0, 2.0, 3.0};
  double b[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
  double c[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

  double res = mult(3, a[0], a[1], a[2]);
  cout << "3 параметра: " << res << endl;

  res = mult(7, b[0], b[1], b[2], b[3], b[4], b[5], b[6]);
  cout << "7 параметрів: " << res << endl;

  res = mult(11, c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7], c[8], c[9]);
  cout << "11 параметрів: " << res << endl;

  return 0;
}
