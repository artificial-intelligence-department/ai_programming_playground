#include <iostream>
#include <vector>

int main() {
    
    int N;
    std::cin >> N;

    std::vector<int> r(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> r[i];
    }

    
    int a, b, c;
    std::cin >> a >> b >> c;

    
    for (int i = 0; i < N; ++i) {
        if (r[i] == a || r[i] == b || r[i] == c) {
            r.erase(r.begin() + i);
            --N; 
            --i; 
        }
    }

    
    std::vector<int> sums;
    for (int i = 0; i < N - 1; ++i) {
        sums.push_back(r[i] + r[i + 1]);
    }

    
    if (N > 1) {
        std::cout << N - 1 << std::endl;
        for (int i = 0; i < N - 1; ++i) {
            std::cout << sums[i] << " ";
        }
    } else {
        std::cout << "0" << std::endl;
    }

    return 0;
}
