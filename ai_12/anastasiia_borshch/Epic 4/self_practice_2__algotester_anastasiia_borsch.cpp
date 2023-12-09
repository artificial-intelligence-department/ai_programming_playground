#include <iostream>

int main() {
    int n, K = 0, V = 0, s[] = {0, 0};
    std::cin >> n;

    char c[n];

    for(int i = 0; i < n; i++) {
        std::cin >> c[i];

        if(c[i] == 'K') {
            s[0]++;
        } else {
            s[1]++;
        }
        if ((s[0] >= 11 || s[1] >= 11) && std::abs(s[0] - s[1]) >= 2) {
            if (s[0] > s[1]) {
                K++;
            } else {
                V++;
            }
            s[0] = s[1] = 0;
        }
    }
    std::cout << K << ":" << V << std::endl;

    if (s[0] > 0 || s[1] > 0) {
        std::cout << s[0] << ":" << s[1];
    }
    return 0;
}