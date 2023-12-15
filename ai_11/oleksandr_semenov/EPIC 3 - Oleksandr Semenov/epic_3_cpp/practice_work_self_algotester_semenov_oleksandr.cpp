#include <iostream>

using namespace std;

int solve(int a, int b, int k) {
  int total = a;
  for (int i = 0; i < k; i++) {
    total += b;
  }
  return total;
}

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  cout << solve(a, b, k) << endl;
  return 0;
}
