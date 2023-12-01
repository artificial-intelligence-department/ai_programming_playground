#include <iostream>

using namespace std;

int main() {
    long long H, M, hi, mi;
  

    bool Victory = true;

    std::cin >> H >> M;

    for (int i = 0; i < 3; ++i) {
        std::cin >> hi >> mi;

        H -= hi;

        M -= mi;

        Victory = (( (hi && mi) || (H < 1) || (M < 1) ) ? false : Victory);
        hi = 0, mi = 0;

    }

    std::cout << ( Victory ? "YES" : "NO");

    return 0;
}
