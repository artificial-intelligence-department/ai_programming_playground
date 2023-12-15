#include <iostream>
#include <vector>
#include <cstdlib> // Для функції rand()
#include <iomanip> // Для виводу чисел з плаваючою крапкою з фіксованою точністю

// Функція для створення та заповнення матриці
std::vector<std::vector<double>> createAndFillMatrix() {
    // Розмір матриці
    const int CONST = 1006; //Цільночисельна константа
    const int rows = 10; //Цільночисельна константа
    const int cols = 10; //Цільночисельна константа

    // Створення матриці
    std::vector<std::vector<double>> matrix(rows, std::vector<double>(cols));

    // Заповнення матриці числами з плаваючою крапкою
    for (int i = 0; i < rows; ++i) { // for цикл для заповнення рядків матриці
        for (int j = 0; j < cols; ++j) { // for цикл для заповнення стовпців матриці
            // Генерація випадкового числа з плаваючою крапкою у діапазоні від 0 до 1
            matrix[i][j] = static_cast<double>(rand()) / RAND_MAX;
        }
    }

    return matrix;
}
void processMatrix(const std::vector<std::vector<double>>&matrix) { 
    for (int i = 0; i < 10; ++i) { // циел 
        for (int j = 0; j < 10; ++j) {
            std::cout << std::fixed << std::setprecision(2) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
     int sums[10] = {0}; // Цілочисельний статичний масив для зберігання сум

    for (int j = 0; j < 10; ++j) {
        for (int k = 0; k < 10; ++k) { // Цикл for для рандому
            int randomRowCount = rand() % 2 + 3; // Вибір випадкової кількості елементів (3 або 4)
            
            for (int l = 0; l < randomRowCount; ++l) { // цикл for для вставлення значень в суму
                sums[j] += static_cast<int>(matrix[l][j]); // Додавання значень до суми
            }
        }
    }

    // Вивід сум на екран
    std::cout << "\nSums for 3 or 4 random elements in each column:" << std::endl;
    for (int i = 0; i < 10; ++i) {// цикл  for для сум
        std::cout << sums[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    // Виклик функції для створення та заповнення матриці
    std::vector<std::vector<double>> myMatrix = createAndFillMatrix();

    // Вивід матриці на екран
    for (int i = 0; i < 10; ++i) { // for цикл для виведення рядків матриці
        for (int j = 0; j < 10; ++j) { // for цикл для виведення стовпців матриці
            // Вивід чисел з фіксованою точністю до двох знаків після коми
            std::cout << std::fixed << std::setprecision(2) << myMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    processMatrix(myMatrix);

    return 0;
}
