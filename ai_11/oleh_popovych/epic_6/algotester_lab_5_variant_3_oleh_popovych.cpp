//
// Created by olehio-h on 12/7/2023.
//
#include <iostream>
#include <string>
#include <vector>


void paintMountain(std::vector<std::vector<int>>&, int, int);

int main() {
    int N, M;
    std::cin >> N >> M;

    int x, y;
    std::cin >> x >> y;
    --x;
    --y;

    std::vector<std::vector<int>> map(N, std::vector<int>(M));

    paintMountain(map, x, y);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

void paintMountain(std::vector<std::vector<int>>& map, int x, int y) {
    if (x < 0 || x > map.size() || y < 0 || y > map[0].size()) {
        return;
    }

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            map[i][j] = abs(i - (x)) + abs(j - (y));
        }
    }

    int maxHeight = 0;
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            if (maxHeight < map[i][j])
                maxHeight = map[i][j];
        }
    }

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            map[i][j] = abs(map[i][j] - maxHeight);
        }
    }
}
