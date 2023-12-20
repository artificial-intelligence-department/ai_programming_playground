#include <iostream>
#include <vector>

int findColumnSum(const std::vector<std::vector<int>>& matrix, int column, int excludeLast) {
    int sum = 0;
    for (int i = 0; i < matrix.size() - excludeLast; ++i) {
        sum += matrix[i][column];
    }
    return sum;
}

int findMaxColumnSum(const std::vector<std::vector<int>>& matrix) {
    int maxSum = 0;
    for (int i = 0; i < matrix[0].size() - 1; ++i) {
        int sum = findColumnSum(matrix, i, i);
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    return maxSum;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int maxSum = findMaxColumnSum(matrix);

    std::cout << "Максимальна сума: " << maxSum << std::endl;

    return 0;
}
