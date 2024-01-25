#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> r(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> r[i];
    }

    int a, b, c;
    std::cin >> a >> b >> c;

    r.erase(std::remove_if(r.begin(), r.end(), [a, b, c](int x) {
        return x == a || x == b || x == c;
    }), r.end());

    if (r.size() < 2) {
        std::cout << "0" << std::endl;
        return 0;
    }

    std::vector<int> sum_array;
    for (int i = 0; i < r.size() - 1; ++i) {
        sum_array.push_back(r[i] + r[i + 1]);
    }

    int M = sum_array.size();
    std::cout << M << std::endl;
    for (int i = 0; i < M; ++i) {
        std::cout << sum_array[i] << " ";
    }

    return 0;
}

