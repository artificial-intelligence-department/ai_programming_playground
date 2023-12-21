#include <iostream>
#include <cmath>

int main() {
    size_t n, m;
    std::cin >> n >> m;
    size_t x, y, distance = 0;
    std::cin >> x >> y;
    size_t mountain[n][m];

    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m; j++){
            size_t tempdist = abs(x-1-i) + abs(y-1-j);
            mountain[i][j] = tempdist;

            if (tempdist > distance){
                distance = tempdist;
            }
        }
    }

    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m; j++){
            std::cout << distance - mountain[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}