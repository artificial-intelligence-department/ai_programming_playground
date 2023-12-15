#include <iostream>

int main() {
    long long H, M, deal, spend;
    bool win = true;
    std::cin >> H >> M;
    for (int a = 0; a < 3; ++a) {
        std::cin >> deal >> spend;
        H -= deal;
        M -= spend;
        win = (( (deal && spend) || (H < 1) || (M < 1) ) ? false : win);
        deal = 0, spend = 0;
    }
    std::cout << ( win ? "YES" : "NO");
    return 0;
}