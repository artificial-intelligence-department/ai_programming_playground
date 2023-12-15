#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>

const int pull_request_number = 1021;

// Функція для створення матриці з плаваючою крапкою
double** createFloatingMatrix() {
    double** matrix = new double*[10];
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new double[10];
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = sin(i) * cos(j);
        }
    }
    return matrix;
}

// Функція для створення матриці цілих чисел
int** createIntegerMatrix() {
    int** matrix = new int*[10];
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new int[10];
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = static_cast<int>(floor(exp(i) * sqrt(j)));
        }
    }
    return matrix;
}
// Константа для назви файлу
const std::string fileName = "output.txt";

// Шаблон функції для сортування стовпців матриці з числами з плаваючою крапкою
template <typename T>
void sortColumns(T** matrix, int rows, int cols) {
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows - 1; ++i) {
            for (int k = 0; k < rows - i - 1; ++k) {
                if (matrix[k][j] > matrix[k + 1][j]) {
                    std::swap(matrix[k][j], matrix[k + 1][j]);
                }
            }
        }
    }
}

// Шаблон функції для виведення матриці
template <typename T>
void printMatrix(T** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Функція для обчислення сум 3-х або 4-х рандомно взятих елементів у кожному стовпці
// та створення нового цілочисельного статичного масиву з 10 елементів
int* calculateColumnSums(double** matrix, int rows, int cols) {
    int* columnSums = new int[10];

    for (int j = 0; j < cols; ++j) {
        double sum = 0.0;

        // Вибір 3-х або 4-х рандомних елементів у стовпці
        int elementsToSum = (rand() % 2) + 3;

        for (int k = 0; k < elementsToSum; ++k) {
            sum += matrix[k][j];
        }

        // Додавання суми до масиву, відкидаючи дробову частину
        columnSums[j] = static_cast<int>(sum);
    }

    return columnSums;
}

// Функція для запису масиву у файл
bool writeArrayToFile(const int* array, int size, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < size; ++i) {
            file << array[i] << " ";
        }
        file.close();
        return true;
    }
    return false;
}

// Функція для відкриття файлу та розрахунку добутку його елементів
int calculateProductFromFile() {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 0;
    }

    int product = 1;
    int value;
    while (file >> value) {
        product *= value;
    }

    file.close();
    return product;
}

// Функція для видалення файлу
void deleteFile(const std::string& filename) {
    if (remove(filename.c_str()) == 0) {
        std::cout << "File deleted successfully." << std::endl;
    } else {
        std::cerr << "Failed to delete file." << std::endl;
    }
}

// Головна функція, яка викликає всі інші функції
void mainFunction() {
    const int rows = 10;
    const int cols = 10;

    // Створення матриці з числами з плаваючою крапкою
    double** floatingMatrix = createFloatingMatrix();

    // Виведення початкової матриці
    std::cout << "Original Floating Matrix:" << std::endl;
    printMatrix(floatingMatrix, rows, cols);

    // Виклик функції для сортування стовпців
    sortColumns(floatingMatrix, rows, cols);

    // Виведення відсортованої матриці
    std::cout << "Sorted Floating Matrix:" << std::endl;
    printMatrix(floatingMatrix, rows, cols);

    // Виклик функції для обчислення сум та створення нового масиву
    int* sumsArray = calculateColumnSums(floatingMatrix, rows, cols);

    // Виведення нового масиву сум
    std::cout << "Column Sums Array:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << sumsArray[i] << " ";
    }
    std::cout << std::endl;

    // Запис масиву у файл
    if (writeArrayToFile(sumsArray, 10, fileName)) {
        std::cout << "Array successfully written to file." << std::endl;
    } else {
        std::cout << "Failed to write array to file." << std::endl;
    }

    // Виклик функції для відкриття файлу та розрахунку добутку елементів
    int product = calculateProductFromFile();

    // Виведення добутку елементів у консоль
    std::cout << "Product of array elements in file: " << product << std::endl;

    // Виклик функції для видалення файлу
    deleteFile(fileName);

    // Видалення виділеної пам'яті для матриці та масиву сум
    for (int i = 0; i < rows; ++i) {
        delete[] floatingMatrix[i];
    }
    delete[] floatingMatrix;

    delete[] sumsArray;
}

int main() {
    // Виклик головної функції
    mainFunction();

    return 0;
}
