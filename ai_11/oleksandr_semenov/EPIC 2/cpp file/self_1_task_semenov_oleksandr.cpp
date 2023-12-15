#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> dp(n);
  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int max_len = 0;
  for (int i = 0; i < n; i++) {
    max_len = max(max_len, dp[i]);
  }

  cout << max_len << endl;

  return 0;
}
