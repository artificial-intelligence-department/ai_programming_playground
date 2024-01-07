#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cout << ((n*m)%2 == 0 ? "Dragon" : "Imp");
    return 0;
}