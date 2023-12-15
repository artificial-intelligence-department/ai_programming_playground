#include <iostream>

using namespace std;

string toOctal(int n, int count) {
  string result = "";
  while (n > 0) {
    result = to_string(n % 8) + result;
    n /= 8;
  }
  if (count > result.length()) {
    result = string(count - result.length(), '0') + result;
  }
  return result;
}
int main() {
  cout << toOctal(123, 3) << endl; // 173
  cout << toOctal(12345, 5) << endl; // 30071
  cout << toOctal(1234567, 8) << endl; // 04553207
  return 0;
}
