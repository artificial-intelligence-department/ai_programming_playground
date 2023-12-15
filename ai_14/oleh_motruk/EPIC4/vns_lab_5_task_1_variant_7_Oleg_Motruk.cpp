#include <iostream>
#include <vector>

using namespace std;

void swapRowAndColumn(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][0] == matrix[0][j]) {
                for (int k = 0; k < rows; k++) {
                    swap(matrix[k][j], matrix[i][k]);
                }
            }
        }
    }
}


int main() {
    vector<vector<int>> array = {
        {1 , 4 , 3},
        {2 , 3 , 1},
        {4 , 5 , 6},
    };
    int rows = array.size();
    int cols = array[0].size();

    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols ; j++){
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }

    swapRowAndColumn(array);

    cout << "\nThe matrix after exchange:\n";

    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols ; j++){
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
