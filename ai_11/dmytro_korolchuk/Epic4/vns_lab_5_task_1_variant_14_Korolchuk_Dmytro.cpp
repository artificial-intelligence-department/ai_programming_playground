#include <iostream>
#include <vector>

using namespace std;

long long calculateProduct(int rows, int cols, int* matrix) {
    long long product = 1;

    for (int col = 0; col < cols; col++) {
        if (*(matrix + col) > *(matrix + col * cols + col) && *(matrix + col) > *(matrix + (cols - col - 1) * cols + col)) {
            for (int row = 0; row < rows; row++) {
                product *= *(matrix + row * cols + col);
            }
        }
    }

    return product;

    return product;
}

int main() {

    int rows, cols;
    cin>>rows;
    cin>>cols;

    int matrix[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << calculateProduct(rows, cols, &matrix[0][0]) << endl;

    return 0;
}
