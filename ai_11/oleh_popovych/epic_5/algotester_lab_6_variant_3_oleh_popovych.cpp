//
// Created by olehio-p on 12/7/2023.
//
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

struct Pair{
    int x;
    int y;
};

std::set<int> getPossibleNumbers(const std::vector<std::vector<int>>&, int, int);

int main(int argc, char const *argv[])
{
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> grid(N, std::vector<int>(N));
    std::string line;
    std::cin.ignore();
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, line);
        for(int j = 0; j < N; j++) {
            grid[i][j] = line[j] - '0';
        }
    }

    int Q;
    std::cin >> Q;
    std::vector<Pair> coords;
    for(int i = 0; i < Q; i++) {
        int x, y;
        std::cin >> x >> y;
        --x;
        --y;
        coords.push_back({x, y});
    }

    for (int i = 0; i < Q; i++) {
        if (grid[coords[i].x][coords[i].y] == 0) {
            std::set<int> possibleNumbers = getPossibleNumbers(grid, coords[i].x, coords[i].y);

            std::cout << possibleNumbers.size() << std::endl;
            for (int number : possibleNumbers) {
                std::cout << number << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << 1 << std::endl;
            std::cout << grid[coords[i].x][coords[i].y] << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}

std::set<int> getPossibleNumbers(const std::vector<std::vector<int>>& grid, int x, int y) {
    std::set<int> possibleNumbers;


    for (int i = 1; i <= grid.size(); i++) {
        possibleNumbers.insert(i);
    }

    for (int i = 0; i < grid.size(); i++) {
        possibleNumbers.erase(grid[i][y]);
        possibleNumbers.erase(grid[x][i]);
    }

    return possibleNumbers;
}