#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> r(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> r[i];
    }

    if (N == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::sort(r.begin(), r.end());

    int minFatigue = std::min(r[N-2] - r[0], r[N-1] - r[1]);

    std::cout << minFatigue << std::endl;

    return 0;
}