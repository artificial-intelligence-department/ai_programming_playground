#include <iostream>
#include <vector>
using namespace std;
bool find_column(const vector<vector<int>>&);
int totalSum {0};



int main() {
    int rows, columns;
    cout << "How much rows?: ";
    cin >> rows;
    cout << "How much columns: ";
    cin >> columns;

    vector<vector<int>> matrix(rows, vector<int>(columns));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> matrix[i][j];
        }
    }

    if (find_column(matrix)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}

bool find_column(const vector<vector<int>> &matrix) {

    for (const auto& row : matrix) {
        for (int elem : row) {
            totalSum += elem;

        }
    }

    for (int col = 0; col < matrix[0].size(); ++col) {
        int sumBefore = 0;  
        for (int row = 0; row < matrix.size(); ++row) {
            sumBefore += matrix[row][col];
        }
        if (sumBefore > totalSum - sumBefore) {
            return true;
        }
    }
    return false;
}