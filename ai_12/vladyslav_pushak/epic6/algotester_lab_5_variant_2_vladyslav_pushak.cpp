#include <iostream>
#include <vector>
#include <algorithm>

void processCave(int N, int M, std::vector<std::string>& cave) {
    for (int j = 0; j < M; ++j) {
        int lastRock = N;
        for (int i = N-1; i >= 0; --i) {
            if (cave[i][j] == 'X') {
                lastRock = i;
            } else if (cave[i][j] == 'S') {
                int k = i;
                while (k+1 < lastRock && cave[k+1][j] == 'O') {
                    std::swap(cave[k][j], cave[k+1][j]);
                    ++k;
                }
            }
        }
    }
}

void printCave(const std::vector<std::string>& cave) {
    for (const auto& row : cave) {
        std::cout << row << std::endl;
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::string> cave(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> cave[i];
    }

    processCave(N, M, cave);
    printCave(cave);

    return 0;
}
