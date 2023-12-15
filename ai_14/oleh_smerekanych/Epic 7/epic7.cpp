#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int PR_NUMBER = 1029; 
const std::string FILE_NAME = "output.txt";

std::vector<std::vector<float>> generateMatrix() {
    std::vector<std::vector<float>> matrix(10, std::vector<float>(10));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = (PR_NUMBER % 2 == 0) ? static_cast<float>(i * j) : static_cast<int>(i * j);
        }
    }
    return matrix;
}

void sortMatrix(std::vector<std::vector<float>> &matrix, float value) {
    if (static_cast<int>(value) == value) { // Сортування рядків
        for (auto &row : matrix) {
            for (int i = 0; i < row.size(); ++i) {
                for (int j = 0; j < row.size() - i - 1; ++j) {
                    if (row[j] < row[j + 1]) {
                        std::swap(row[j], row[j + 1]);
                    }
                }
            }
        }
    } else { // Сортування стовпців
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10 - j - 1; ++k) {
                    if (matrix[k][i] > matrix[k + 1][i]) {
                        std::swap(matrix[k][i], matrix[k + 1][i]);
                    }
                }
            }
        }
    }
}

std::vector<int> calculateSums(const std::vector<std::vector<float>> &matrix) {
    std::vector<int> sums(10, 0);
    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        int sum = 0;
        for (int j = 0; j < 4; ++j) {
            sum += matrix[rand() % 10][i];
        }
        sums[i] = sum;
    }
    return sums;
}

bool writeToFile(const std::vector<int> &data) {
    std::ofstream file(FILE_NAME);
    if (!file.is_open()) {
        return false;
    }
    for (int num : data) {
        file << num << "\n";
    }
    file.close();
    return true;
}

int readFile() {
    std::ifstream file(FILE_NAME);
    if (!file.is_open()) {
        return -1;
    }
    int product = 1, num;
    while (file >> num) {
        product *= num;
    }
    file.close();
    return product;
}

void deleteFile() {
    if (remove(FILE_NAME.c_str()) == 0) {
        std::cout << "File deleted successfully\n";
    } else {
        std::cout << "Error deleting file\n";
    }
}

int main() {
    std::vector<std::vector<float>> matrix = generateMatrix();
    sortMatrix(matrix, static_cast<float>(PR_NUMBER));
    std::vector<int> sums = calculateSums(matrix);
    if (writeToFile(sums)) {
        std::cout << "Product: " << readFile() << std::endl;
    }
    deleteFile();
    return 0;
}
