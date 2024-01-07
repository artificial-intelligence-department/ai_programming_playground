#include <iostream>

int main() {
    long a, b;
    std::cin >> a >> b;
    if (a > b) {
        long c = a;
        a = b;
        b = c;
    }

    if (a+1 == b) std::cout << "-1";
    else std::cout << (b-1);
    return 0;
}