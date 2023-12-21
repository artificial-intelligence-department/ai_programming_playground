#include <iostream>

using namespace std;

int main() {
  long long h, m;
  cin >> h >> m;

  long long hi[3], mi[3];
  for (int i = 0; i < 3; i++) {
    cin >> hi[i] >> mi[i];

    if (hi[i] > 0 && mi[i] > 0) {
      cout << "NO" << endl;
      return 0;
    }

    h -= hi[i];
    m -= mi[i];

    if (h <= 0 || m <= 0) {
      cout << "NO" << endl;
      return 0;
    }
  }


  cout << "YES" << endl;
  return 0;
}
