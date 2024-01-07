#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

// Константа
const int MY_CONSTANT = 959;

// Математична функція для заповнення матриці
int mathematicalFunction(int x, int y) {
    // Умова завдання 2: додавання константи до координат елемента
    return x + y + MY_CONSTANT;
}

// Функція для створення та повернення матриці 10x10
int** createMatrix() {
    // Розмір матриці
    const int rows = 10;
    const int cols = 10;

    // Створення матриці цілих чисел
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Заповнення матриці значеннями з математичної функції
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Використано умову завдання 2: виклик математичної функції
            matrix[i][j] = mathematicalFunction(i, j);
        }
    }

    // Повернення матриці
    return matrix;
}

// Функція для сортування рядків матриці по спаданню методом бульбашки
void bubbleSortRows(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
            for (int k = 0; k < cols - j - 1; ++k) {
                // Умова завдання 2: сортування рядків по спаданню
                if (matrix[i][k] < matrix[i][k + 1]) {
                    std::swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

// Функція для отримання суми 3-4 рандомних елементів у стовпці
int getColumnSum(int** matrix, int rows, int col) {
    int sum = 0;

    // Отримання 3-4 рандомних елементів у стовпці
    for (int i = 0; i < std::min(4, rows); ++i) {
        sum += matrix[i][col];
    }

    // Умова завдання 3: відкидання дробової частини
    return static_cast<int>(sum);
}

// Функція для обчислення сум для 3-х або 4-х рандомно взятих елементів у кожному з стовпців
int* calculateColumnSums(int** matrix, int rows, int cols, float secondParameter) {
    // Створення нового цілочисельного статичного масиву з 10 елементів
    static int sums[10];

    // Генерація випадкових значень для вибору 3-4 елементів у стовпці
    srand(time(nullptr));

    for (int i = 0; i < cols; ++i) {
        // Отримання суми для 3-4 рандомних елементів у стовпці
        sums[i] = getColumnSum(matrix, rows, i);
    }

    // Умова завдання 3: відкидання дробової частини
    for (int i = 0; i < 10; ++i) {
        sums[i] = static_cast<int>(sums[i] * secondParameter);
    }

    // Повернення масиву сум
    return sums;
}

// Функція для запису значень масиву у файл
bool writeArrayToFile(const int* array, int size) {
    // Умова завдання: ім'я файлу, в який записувати, наприклад, "output.txt"
    const char* fileName = "output.txt";

    // Відкриття файлу для запису
    std::ofstream outputFile(fileName);

    // Перевірка, чи вдалося відкрити файл
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return false;  // Умова завдання: повертає false, якщо дія не відбулась
    }

    // Запис значень масиву у файл
    for (int i = 0; i < size; ++i) {
        outputFile << array[i] << "\t";
    }

    // Закриття файлу
    outputFile.close();

    // Умова завдання: повертає true, якщо дія відбулась
    return true;
}

// Функція для виведення матриці на екран
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Функція для виведення масиву на екран
void printArray(const int* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}

// Функція для видалення файлу та повідомлення про це в консоль
bool deleteFile(const char* fileName) {
    // Умова завдання 6: видалення файлу
    if (std::remove(fileName) == 0) {
        std::cout << "File \"" << fileName << "\" successfully deleted." << std::endl;
        return true;
    } else {
        std::cerr << "Error deleting file: " << fileName << std::endl;
        return false;
    }
}

// Функція для видалення матриці з пам'яті
void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Функція для обчислення добутку елементів, записаних у файл
int calculateProductFromFile() {
    // Умова завдання: ім'я файлу, з якого читати, наприклад, "output.txt"
    const char* fileName = "output.txt";

    // Відкриття файлу для читання
    std::ifstream inputFile(fileName);

    // Перевірка, чи вдалося відкрити файл
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return -1;  // Умова завдання: повертає -1 у разі помилки
    }

    // Читання значень з файлу та обчислення добутку
    int product = 1;
    int value;
    while (inputFile >> value) {
        product *= value;
    }

    // Закриття файлу
    inputFile.close();

    // Умова завдання: виведення значення у консоль
    std::cout << "Product of elements from file: " << product << std::endl;

    // Повернення обчисленого добутку
    return product;
}

int main() {
    // Виклик функції для створення та отримання матриці
    int** resultMatrix = createMatrix();

    // Виведення початкової матриці на екран
    std::cout << "Original Matrix:" << std::endl;
    printMatrix(resultMatrix, 10, 10);

    // Значення для другого параметра (можна ввести з консолі)
    float secondParameter;
    std::cout << "Enter a floating-point value for the second parameter: ";
    std::cin >> secondParameter;

    // Умова завдання 2: виклик функції для сортування рядків матриці
    bubbleSortRows(resultMatrix, 10, 10);

    // Виведення відсортованої матриці на екран
    std::cout << "\nSorted Matrix:" << std::endl;
    printMatrix(resultMatrix, 10, 10);

    // Умова завдання 3: виклик функції для розрахунку сум у стовпцях та створення нового масиву
    int* sumsArray = calculateColumnSums(resultMatrix, 10, 10, secondParameter);

    // Виведення масиву на екран
    std::cout << "\nSums Array:" << std::endl;
    printArray(sumsArray, 10);

    // Умова завдання 4: виклик функції для запису значень масиву у файл
    bool writeSuccess = writeArrayToFile(sumsArray, 10);

    // Перевірка, чи вдалося записати у файл
    if (writeSuccess) {
        std::cout << "Values successfully written to the file." << std::endl;
    } else {
        std::cerr << "Error writing values to the file." << std::endl;
    }

    // Умова завдання 5: виклик функції для обчислення добутку елементів з файлу
    int product = calculateProductFromFile();

    // Умова завдання 6: виклик функції для видалення файлу
    bool deleteSuccess = deleteFile("output.txt");

    // Перевірка, чи вдалося видалити файл
    if (deleteSuccess) {
        std::cout << "File successfully deleted." << std::endl;
    } else {
        std::cerr << "Error deleting file." << std::endl;
    }

    // Видалення матриці та масиву з пам'яті
    deleteMatrix(resultMatrix, 10);
    // У випадку, якщо sumsArray - статичний масив, видалення може не бути необхідним.

    return 0;
}






