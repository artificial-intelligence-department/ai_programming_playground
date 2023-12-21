#include <iostream>

int main() {
    double a, b, n, m;
    std::cin >> a >> b;
    n = a, m = b;
    std::cout << "++n * ++m = " << (++n * ++m) << std::endl;
    n = a, m = b;
    std::cout << "m++ < n   = " << (m++ < n) << std::endl;
    n = a, m = b;
    std::cout << "n++ > m   = " << (n++ > m) << std::endl;
    return 0;
}