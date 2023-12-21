#include <iostream>
using namespace std;

const int R = 100; 
const int S = 100; 

bool isPossible(int matrix[R][S], int r, int s, int column) {
    int leftSum = 0;
    int rightSum = 0;

    for (int i=0; i<r; ++i) {
        if (i != column) {
            leftSum+=matrix[i][column];
        }
    } // Обчислення суми для лівої частини

    for (int k=0; k<s; ++k) {
        if (k != column) {
            rightSum+=matrix[column][k];
        }
    }  // Обчислення суми для правої частини

    return leftSum>rightSum; //порівняння сум
}

bool doesColumnExist(int matrix[R][S], int r, int s) {
    for (int col = 0; col < s; ++col) {
        if (isPossible(matrix, r, s, col)) {
            return true;
        } else {
            return false;
        }
    }

}

int main() {
    int matrix[R][S] = {
        {7, 2, 3},
        {4, 1, 6, 8},
        {2, 2, 2, 2}
    };

    if (doesColumnExist(matrix, 4, 4)==true) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}


