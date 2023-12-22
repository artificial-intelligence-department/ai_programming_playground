#include <iostream>
#include <vector>
#include <algorithm>

struct Coordinate {
    int x;
    int y;
};

std::vector<int> getPossibleValues(const std::vector<std::vector<int>>& sudoku, int row, int col) {
    int N = sudoku.size();

    std::vector<int> possible;

    for (int value = 1; value <= N; ++value) {
        possible.push_back(value);
    }

    for (int j = 0; j < N; ++j) {
        auto it = std::find(possible.begin(), possible.end(), sudoku[row][j]);
        if (it != possible.end()) {
            possible.erase(it);
        }
    }

    for (int i = 0; i < N; ++i) {
        auto it = std::find(possible.begin(), possible.end(), sudoku[i][col]);
        if (it != possible.end()) {
            possible.erase(it);
        }
    }

    return possible;
}

int main() {
    int size;
    int queries;

    std::cin >> size;

    std::vector<std::vector<int>> sudoku(size, std::vector<int>(size, 0));
    std::vector<int> numbers;
    std::vector<Coordinate> coordinates;

    for (int i = 0; i < size; ++i) {
        int a;
        std::cin >> a;
        numbers.push_back(a);
    }

    std::cin >> queries;

    for (int i = 0; i < queries; i++) {
        int x, y;
        std::cin >> x >> y;
        coordinates.push_back({ x, y });
    }

    for (int i = 0; i < numbers.size(); ++i) {
        int number = numbers[i];
        for (int j = size - 1; j >= 0; --j) {
            sudoku[i][j] = number % 10;
            number /= 10;
        }
    }

    for (int i = 0; i < queries; i++) {
        if (sudoku[coordinates[i].x - 1][coordinates[i].y - 1] != 0) {
            std::cout << 1 << '\n';
            std::cout << sudoku[coordinates[i].x - 1][coordinates[i].y - 1] << '\n' << '\n';
        } else {
            std::vector<int> possibleValues = getPossibleValues(sudoku, coordinates[i].x - 1, coordinates[i].y - 1);

            std::cout << possibleValues.size() << '\n';

            for (int j = 0; j < possibleValues.size(); j++) {
                std::cout << possibleValues[j] << " ";
            }
            std::cout << '\n' << '\n';
        }
    }

    return 0;
}