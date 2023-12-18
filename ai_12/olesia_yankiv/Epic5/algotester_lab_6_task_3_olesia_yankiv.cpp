#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char * argv[])
{
  int32_t N;
  cin >> N;
  vector<string> A(N);
  for (auto & row : A) cin >> row;
  int32_t Q;
  cin >> Q;
  for (size_t q = 0; q < Q; ++q)
  {
    int32_t x, y;
    cin >> x >> y;
    --x;
    --y;
    if (A[x][y] != '0') {
      cout << "1\n" << A[x][y] << "\n";
    } else {
      int32_t msk = 0;
      for (size_t i = 0; i < N; ++i) {
        msk |= (1 << (A[x][i] - '0'));
        msk |= (1 << (A[i][y] - '0'));
      }
      vector<int32_t> result;
      for (size_t i = 1; i <= N; ++i) {
        if (!(msk & (1 << i))) result.push_back(i);
      }
      cout << result.size() << "\n";
      for (const auto x : result) cout << x << " ";
      cout << "\n";
    }
  }
  return 0;
}
