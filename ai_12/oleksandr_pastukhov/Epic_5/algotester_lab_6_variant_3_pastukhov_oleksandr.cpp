#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> getAvailableValues(const std::vector<std::vector<int>>& board, int row, int col) {
    int boardSize = board.size();
    std::vector<int> result;

    for (int i = 1; i <= boardSize; i++) {
        result.push_back(i);
    }

    for (int i = 0; i < boardSize; i++) {
        auto it = find(result.begin(), result.end(), board[i][col]);
        if (it != result.end()) {
            result.erase(it);
        }
    }

    for (int i = 0; i < boardSize; i++) {
        auto it = find(result.begin(), result.end(), board[row][i]);
        if (it != result.end()) {
            result.erase(it);
        }
    }

    return result;
}

int main() {
    using namespace std;

    int boardSize;
    cin >> boardSize;
    vector<vector<int>> board;

    for (int i = 0; i < boardSize; i++) {
        vector<int> currentRow;
        string line;
        cin >> line;

        for (int j = 0; j < line.size(); j++) {
            int currentNumber = line[j] - '0';
            currentRow.emplace_back(currentNumber);
        }

        board.emplace_back(currentRow);
    }

    int coordinatesCount;
    cin >> coordinatesCount;
    vector<pair<int, int>> coordinates;

    for (int i = 0; i < coordinatesCount; i++) {
        int x, y;
        cin >> x >> y;
        coordinates.emplace_back(x - 1, y - 1);
    }

    for (auto coord : coordinates) {
        if (board[coord.first][coord.second] != 0) {
            cout << "1" << endl << board[coord.first][coord.second] << "\n\n";
        } else {
            vector<int> availableValues = getAvailableValues(board, coord.first, coord.second);

            cout << availableValues.size() << endl;
            
            for (int value : availableValues) {
                cout << value << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

