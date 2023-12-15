#include <iostream>
#include <vector>

int main() {
    short n, m;
    std::cin >> n >> m;
    if (!n || !m) {std::cout << "0";}
    else {
        std::vector<short> number, max; 
        max.resize(m), number.resize(m);
        max = {0};
        for (short a = 0; a<n; a++) {
            for (short i = 0; i<m; i++) { 
                std::cin >> number[i]; 
                if (max[i] < number[i]) max[i] = number[i]; }
        }
        int sum = 0;
        for (short i = 0; i < m; i++) {sum += max[i];}
        std::cout << sum;
    }
    return 0;
}