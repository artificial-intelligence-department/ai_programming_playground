#include <iostream>

const int rows = 3, columns = 3;


int columnProduct(const int matrix[rows][columns], int column){
    int product = 1;
    for (int i = 0; i<rows; i++){
        product *= matrix[i][column];
    }
    return product;
}

int main(){
    int matrix [rows][columns];

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            std::cin >> matrix[i][j];
        }
    }

    int product = 0;
    for (int j = 0; j < columns; j++){
        if (matrix[0][j] > matrix [j][j] && matrix[0][j] > matrix[2-j][j]){
            product = 1;
            product *= columnProduct(matrix, j);
        }
    }
    if (product > 0){
    std::cout << "Product of the selected columns: " << product;
    } else {
        std::cout << "No rows match the selected criteria";
    }
}