#include <iostream>
#include <vector>
using namespace std;

void T_matrix(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void A_matrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool T_symmetric_A (const vector<vector<int>>& matrix) {
    int n = matrix.size();

    vector<vector<int>> ted_matrix = matrix;
    T_matrix(ted_matrix);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != ted_matrix [i][j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter the size of matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements of matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Transposed matrix:" << endl;
    T_matrix(matrix);
    A_matrix(matrix);

    if (T_symmetric_A (matrix)) {
        cout << "This matrix is symmetrical." << endl;
    } else {
        cout << "This matrix is not symmetrical." << endl;
    }

    return 0;
}
