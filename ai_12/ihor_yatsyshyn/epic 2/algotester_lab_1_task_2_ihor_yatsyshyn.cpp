#include <iostream>
#include <algorithm>

int main() {
    long long h1, h2, h3, h4, d1, d2, d3, d4;

    std::cin >> h1 >> h2 >> h3 >> h4;
    std::cin >> d1;
    std::cin >> d2;
    std::cin >> d3;
    std::cin >> d4;

    if (h1 < d1 || h2 < d2 || h3 < d3 || h4 < d4) {
        std::cout << "ERROR"<< std::endl;
    }else if (2 * std::min({h1-d1, h2, h3, h4}) <= std::max({h2, h3, h4})) {
        std::cout << "NO" << std::endl;
    }else if (2 * std::min({h2-d2, h3, h4}) <= std::max({h1-d1, h3, h4})) {
        std::cout << "NO" << std::endl;
    }else if(2 * std::min(h3-d3, h4) <= std::max({h1-d1, h2-d2, h4})) {
        std::cout << "NO" << std::endl;
    }else if(2 * (h4-d4) <= std::max({h1-d1, h2-d2, h3-d3})) {
        std::cout << "NO" << std::endl;
    }else if (h1-d1 == h2-d2 && h2-d2 == h3-d3 && h3-d3 == h4-d4 && std::min({h1-d1, h2-d2, h3-d3, h4-d4}) != 0){
        std::cout << "YES" << std::endl;
    }else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}