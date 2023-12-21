#include <iostream>

int main() {
    size_t n, m;
    std::cin >> n >> m;

    char cave[n][m];

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            std::cin >> cave[i][j];
        }
    }

for (size_t k = 0; k < n; k++){
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < m; j++) {
            if (cave[i][j] == 'S' && cave[i + 1][j] == 'O') {
                cave[i + 1][j] = 'S';
                cave[i][j] = 'O';
            }
        }
        size_t count = n + m;
        
    }
}
    

    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < m; j++) {
            if (cave[i][j] == 'S' && cave[i + 1][j] == 'O') {
                cave[i + 1][j] = 'S';
                cave[i][j] = 'O';
            }
        }
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            std::cout << cave[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
