#include <iostream>
#include <vector>
#include <algorithm>

const int row = 3;
const int column = 3;

void MaxAndRotate(int massive[row][column], int c) {
    int max = massive[c][0];
    for (int i = 0; i < column; i++) {
        if (max < massive[c][i])
            max = massive[c][i];
    }

    for (int j = 0; j < row; j++) {
        int temp[column];
        for (int k = 0; k < column; k++) {
            temp[(k + max) % column] = massive[j][k];
        }
        for (int k = 0; k < column; k++) {
            massive[j][k] = temp[k];
        }
    }

    // Print the array after rotation
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            std::cout << massive[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    using namespace std;
    int answer;
    int massive[row][column] = {
        {1, 2, 3},
        {4, 5, 5},
        {7, 8, 9}
    };
    

    cout << "Which row do you wanna take?: ";
    cin >> answer;

    if (answer >= 0 && answer < row) {
        MaxAndRotate(massive, answer);
    } 

    return 0;
}
