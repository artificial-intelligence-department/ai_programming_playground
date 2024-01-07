#include <iostream>
#include <vector>
#include <cmath>

// Функція для обчислення скалярного добутку векторів
double dotProduct(const std::vector<double>& vec1, const std::vector<double>& vec2) {
    double result = 0.0;
    for (size_t i = 0; i < vec1.size(); ++i) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

// Функція для перевірки ортонормованості матриці
bool isOrthonormalMatrix(const std::vector<std::vector<double>>& matrix) {
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();

    // Перевірка розмірності та відмінності векторів
    if (rows != cols) {
        std::cerr << "Матриця не є квадратною. Вихід з функції." << std::endl;
        return false;
    }

    // Перевірка скалярних добутків
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = i + 1; j < rows; ++j) {
            if (dotProduct(matrix[i], matrix[j]) != 0.0) {
                std::cerr << "Скалярний добуток рядків " << i + 1 << " і " << j + 1 << " не дорівнює 0." << std::endl;
                return false;
            }
        }
    }

    // Перевірка скалярних добутків рядка на себе
    for (size_t i = 0; i < rows; ++i) {
        if (std::abs(dotProduct(matrix[i], matrix[i]) - 1.0) > 1e-10) {
            std::cerr << "Скалярний добуток рядка " << i + 1 << " на себе не дорівнює 1." << std::endl;
            return false;
        }
    }

    // Якщо всі перевірки пройдені, матриця є ортонормованою
    return true;
}

int main() {
    // Введення розмірності матриці
    std::cout << "Введіть розмірність квадратної матриці: ";
    size_t size;
    std::cin >> size;

    // Введення елементів матриці
    std::vector<std::vector<double>> inputMatrix(size, std::vector<double>(size, 0.0));
    std::cout << "Введіть елементи матриці:" << std::endl;
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            std::cout << "Елемент [" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> inputMatrix[i][j];
        }
    }

    // Перевірка ортонормованості матриці
    if (isOrthonormalMatrix(inputMatrix)) {
        std::cout << "Матриця є ортонормованою." << std::endl;
    } else {
        std::cout << "Матриця не є ортонормованою." << std::endl;
    }

    return 0;
}