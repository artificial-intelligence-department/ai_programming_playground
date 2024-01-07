#include <iostream>
#include <vector>

using namespace std;

void moveMaxToDiagonal(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = n - 1; i > 0; --i) {
        int maxVal = matrix[i][i];
        int maxRow = i;
        int maxCol = i;
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < i; ++k) {
                if (matrix[j][k] > maxVal) {
                    maxVal = matrix[j][k];
                    maxRow = j;
                    maxCol = k;
                }
            }
        }
        swap(matrix[i][i], matrix[maxRow][i]);
        swap(matrix[i][i], matrix[i][maxCol]);
    }
}

bool hasDescendingDiagonal(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n - 1; ++i) {
        if (matrix[i][i] < matrix[i + 1][i + 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Enter value of element[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "Your Array:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    moveMaxToDiagonal(matrix);

    cout << "Modified Array:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    if (hasDescendingDiagonal(matrix)) {
        cout << "Sequence is descending." << endl;
    } else {
        cout << "Sequence is not descending." << endl;
    }

    return 0;
}
