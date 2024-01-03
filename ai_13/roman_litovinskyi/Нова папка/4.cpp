#include <iostream>
#include <fstream> // Підключення бібліотеки для роботи з файлами
#include <cstdlib>
#include <ctime>

// Функція, яка обчислює суми елементів стовпців та записує їх у статичний масив
int* calculate_sums(int matrix[][10], const int rows, const int cols) {
    static int sums[10] = {0}; // Статичний цілочисельний масив для зберігання сум

    for (int col = 0; col < cols; ++col) {
        int sum = 0;
        int count = 0;
        
        // Визначення кількості елементів, які будуть взяті для обчислення суми
        int elements_to_sum = std::min(4, rows);

        // Цикл для обчислення суми 3-4 рандомних елементів у кожному стовпці
        for (int i = 0; i < elements_to_sum; ++i) {
            int random_row = rand() % rows;
            sum += matrix[random_row][col];
            count++;
        }

        // Перевірка на наявність дробової частини у сумі
        double sum_double = static_cast<double>(sum) / count;
        int int_sum = static_cast<int>(sum_double);

        // Запис суми у масив, якщо дробова частина відсутня
        sums[col] = int_sum;
    }

    return sums;
}

// Функція для запису масиву у файл
bool write_to_file(int sums[], const int size) {
    std::ofstream file("sums.txt"); // Створення файлу для запису сум

    if (file.is_open()) {
        for (int i = 0; i < size; ++i) {
            file << sums[i] << " "; // Запис кожного елемента масиву у файл
        }
        file.close(); // Закриття файлу
        return true; // Повернення true у випадку успішного запису у файл
    }

    return false; // Повернення false, якщо відбулася помилка при відкритті файлу
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    const int rows = 10;
    const int cols = 10;

    int matrix[rows][cols];

    // Заповнення матриці випадковими цілими числами від 1 до 100
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }

    std::cout << "Original Matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Обчислення сум та вивід їх на екран
    int* sums = calculate_sums(matrix, rows, cols);

    std::cout << "\nSums of columns:" << std::endl;
    for (int i = 0; i < cols; ++i) {
        std::cout << sums[i] << " ";
    }
    std::cout << std::endl;

    // Запис сум у файл та вивід результату на екран
    bool write_success = write_to_file(sums, cols);

    if (write_success) {
        std::cout << "Sums written to file 'sums.txt' successfully." << std::endl;
    } else {
        std::cout << "Failed to write sums to file." << std::endl;
    }

    return 0;
}
