#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

const int PULL_REQUEST_NUMBER = 996;  // Вимога#4: В коді використана як мінімум одна цілочисельна константа

// Вимога#13: В коді використано рекурсивну функцію
// Вимога#3: В коді використана як мінімум одна дійсний з подвійною точністю змінна
double recursive_sqrt(double x, double guess = 1.0, double epsilon = 1e-6) {
    
    if (std::abs(guess * guess - x) < epsilon) {
        return guess;
    } else {
        double new_guess = 0.5 * (guess + x / guess);
        return recursive_sqrt(x, new_guess, epsilon);
    }
}

// Вимога#12: Перевантаження функції для використання дійсної з подвійною точністю
double math_function(double x) {  
    return sqrt(x);  // Вимога#2: В коді використана як мінімум одна дійсна змінна для обчислення квадратного кореня.
}

// Перевантаження функції для використання цілочисельного типу
double math_function(int x) {  
    return recursive_sqrt(x);  // Використовуємо іншу функцію для цілочисельних значень
}

// Вимога#5: Використані умовні оператори та розгалуження
// Вимога#8: В коді використано do while цикл
void sort_matrix(double matrix[10][10], double pull_request_value) {
    bool is_floating_point = std::abs(pull_request_value - int(pull_request_value)) > 1e-6;

    if (is_floating_point) {
        int i = 0;
        do {
            int j = 0;
            while (j < 10 - 1) {
                if (matrix[0][j] > matrix[0][j + 1]) {
                    int k = 0;
                    do {
                        std::swap(matrix[k][j], matrix[k][j + 1]);
                        ++k;
                    } while (k < 10);
                    break;  // Вимога#11: Використано оператор break для виходу з циклу при умові
                }
                ++j;
            }
            ++i;
        } while (i < 10);
    } else {
        int i = 0;
        do {
            int j = 0;
            while (j < 10 - 1) {
                if (matrix[i][0] < matrix[i + 1][0]) {
                    int k = 0;
                    do {
                        std::swap(matrix[i][k], matrix[i + 1][k]);
                        ++k;
                    } while (k < 10);
                    continue;  // Вимога#11: Використано оператор continue для переходу до наступної ітерації циклу
                }
                ++j;
            }
            ++i;
        } while (i < 10);
    }
}

// Вимога#8: В коді використано do while цикл
int* calculate_sums(double matrix[10][10]) {  
    int* sums_array = new int[10];  // Вимога#6: В коді використаний одновимірний масив 

    int i = 0;
    do {
        int column_sum = 0;
        int j = 0;
        while (j < std::min(4, 10)) {
            int random_row = rand() % 10;
            column_sum += matrix[random_row][i];
            ++j;
        }
        sums_array[i] = column_sum;
        ++i;
    } while (i < 10);

    return sums_array;
}

// Вимога#16: В коді використано оператор виведення даних
bool write_to_file(int* sums_array) {  
    std::ofstream file("result_file.txt");  // Вимога#14: В коді використано функції роботи з файлами, для того, щоб записати у файл
    if (file.is_open()) {
        int i = 0;
        do {
            file << sums_array[i] << "\n";
            ++i;
        } while (i < 10);
        file.close();
        return true;
    }
    return false;
}

// Вимога#18: В коді використано оператор введення даних
int calculate_product_from_file() {  
    int product = 1;
    std::ifstream file("result_file.txt");  // Вимога#17: В коді використано функції роботи з файлами, для того, щоб зчитати з файлу
    if (file.is_open()) {
        int value;
        while (file >> value) {
            product *= value;
        }
        file.close();
    }
    std::cout << "Product from file: " << product << std::endl;  // Вимога#18: В коді використано оператори виведення та введення даних
    return product;
}

// Вимога#18: В коді використано оператор виведення даних
void delete_file() {  
    if (remove("result_file.txt") == 0) {
        std::cout << "File deleted successfully." << std::endl;  
    } else {
        std::cout << "Error deleting the file." << std::endl;
    }
}

// Вимога#14: В коді використано параметри та аргументи функції
void process_matrix_operations() {  
    srand(time(0));  // Вимога#1: В коді використана як мінімум одна цілочисельна змінна

    double matrix[10][10];  // Вимога#7: В коді використаний двовимірний масив
    int i = 0;
    do {
        int j = 0;
        do {
            matrix[i][j] = math_function(PULL_REQUEST_NUMBER);
            ++j;
        } while (j < 10);
        ++i;
    } while (i < 10);

    double pull_request_value = PULL_REQUEST_NUMBER * math_function(rand());  // Вимога#3: Змінено на double
    sort_matrix(matrix, pull_request_value);

    int* sums_array = calculate_sums(matrix);//Вимога#15: в коді використано математичні операції та математичні функції


    if (write_to_file(sums_array)) { //Вимога#16: В коді використано функції роботи з файлами, для того, щоб зчитати з файлу
        calculate_product_from_file();
        delete_file();
    }

    delete[] sums_array;
}

int main() {
    process_matrix_operations();
    return 0;
}
