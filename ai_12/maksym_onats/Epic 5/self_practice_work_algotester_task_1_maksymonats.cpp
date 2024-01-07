#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void process(vector<vector<int>> &field, int x, int y) {
    if (field[x - 1][y - 1] == 0) {
        set<int> numbers;

        for (int i = 1; i <= field.size(); i++) {
            numbers.insert(i);
        }

        for (int i = 0; i < field.size(); i++) {
            numbers.erase(field[i][y - 1]);
            numbers.erase(field[x - 1][i]);
        }

        cout << numbers.size() << endl;
        for (int a : numbers) {
            cout << a << " ";
        }
    } else {
        cout << "1" << endl << field[x - 1][y - 1];
    }
    cout << endl;
}

int main() {
    int N, Q;
    cin >> N;
    const int rows = N;
    const int cols = N;

    vector<vector<int>> field;

    for (int i = 0; i < rows; ++i) {
        vector<int> rowOfField(cols);
        for (int j = 0; j < cols; ++j) {
            char number;
            cin >> number;
            rowOfField[j] = number - '0';
        }
        field.push_back(rowOfField);
    }

    cin >> Q;
    vector<pair<int, int>> coordinates;
    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        coordinates.emplace_back(x, y);
    }

    for (auto coordinate : coordinates) {
        process(field, coordinate.first, coordinate.second);
    }

    return 0;
}
