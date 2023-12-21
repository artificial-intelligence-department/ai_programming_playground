#include <iostream>

int main() {
    int n, k = 15;
    char c;
    std::cin >> n;
    for (int i = 0;i<n;i++) {
        std::cin >> c;
        switch (c) {
        case 'k':
            if (k > 0) {k-=1;}
            break;
        case 'p':
            if (k != 0) {k=15;}
            break;
        case 'z':
            if (k > 0) {k=0;}
            else {k = 15;}
            break;
        }
    }
    std::cout << k;
}