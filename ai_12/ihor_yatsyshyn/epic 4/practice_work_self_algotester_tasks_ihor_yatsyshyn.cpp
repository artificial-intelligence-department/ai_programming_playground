#include <iostream>

int main() {
    int n, K, V, s[] = {0, 0};
    std::cin >> n;
    K = V = 0;

    char c[n];

    for(int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    for(int i = 0; i < n; i++) {
        if(c[i] == 'K') {
            s[0]++;
        }else {
            s[1]++;
        }

        if (s[0] >= 11 && s[0] - s[1] >= 2) {
            K++;
            s[0] = s[1] = 0;
        }else if (s[1] >= 11 && s[1] - s[0] >= 2) {
            V++;
            s[0] = s[1] = 0;
        }
    }

    std::cout << K << ":" << V << std::endl;
    if (s[0] > 0 || s[1] > 0) {
        std::cout << s[0] << ":" << s[1];
    }
    

    return 0;
}