#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

const string FILENAME = "sums.txt"; // Константа для назви файлу

// Функція для математичних обчислень
double mathFunction(int x, int y) {
    return x * x + y * y;
}

// Функція для створення матриці з плаваючою крапкою
void createMatrix(double matrix[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = mathFunction(i, j);
        }
    }
}

// Перевантаження функції для сортування стовпців матриці з плаваючою крапкою
void sortMatrix(double matrix[10][10], double) {
    // Сортування стовпців методом бульбашки
    for (int col = 0; col < 10; ++col) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9 - i; ++j) {
                if (matrix[j][col] > matrix[j + 1][col]) {
                    swap(matrix[j][col], matrix[j + 1][col]);
                }
            }
        }
    }
}

// Перевантаження функції для сортування рядків матриці з цілими числами
void sortMatrix(double matrix[10][10], int) {
    // Сортування рядків методом бульбашки
    for (int row = 0; row < 10; ++row) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9 - i; ++j) {
                if (matrix[row][j] < matrix[row][j + 1]) {
                    swap(matrix[row][j], matrix[row][j + 1]);
                }
            }
        }
    }
}

// Функція для обчислення суми 3 або 4 випадкових елементів у стовпцях
int* calculateSums(double matrix[10][10]) {
    static int sums[10];
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    for (int col = 0; col < 10; ++col) {
        double sum = 0;
        int elementsToSum = rand() % 2 + 3; // Вибір 3 або 4

        for (int i = 0; i < elementsToSum; ++i) {
            int randomIndex = rand() % 10;
            sum += matrix[randomIndex][col];
        }

        sums[col] = static_cast<int>(sum); // Відкидання дробової частини
    }

    return sums;
}

// Функція для запису масиву у файл
bool writeArrayToFile(const int array[], int size, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        return false; // Неможливо відкрити файл
    }

    for (int i = 0; i < size; ++i) {
        file << array[i] << endl;
    }

    file.close();
    return true; // Запис в файл успішно виконано
}

// Функція для обчислення добутку елементів з файлу
long long calculateProductFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return -1; // Повернути помилку, якщо файл не відкрився
    }

    long long product = 1;
    int value;
    while (file >> value) {
        product *= value;
    }

    file.close();
    return product;
}

// Функція для обробки і сортування матриці в залежності від типу pullRequestValue
void processAndSortMatrix(double matrix[10][10], const string& pullRequestValueStr) {
    if (pullRequestValueStr.find('.') != string::npos) {
        double pullRequestValueDouble = stod(pullRequestValueStr);
        sortMatrix(matrix, pullRequestValueDouble);
    } else {
        int pullRequestValueInt = stoi(pullRequestValueStr);
        sortMatrix(matrix, pullRequestValueInt);
    }
}

// Функція для видалення файлу
void deleteFile(const string& filename) {
    if (remove(filename.c_str()) != 0) {
        perror("Error deleting file");
    } else {
        cout << "Файл " << filename << " успішно видалино." << endl;
    }
}

int main() {
    double matrix[10][10];
    createMatrix(matrix);

    // Зчитування pullRequestValue як рядка
    cout << "Enter pull request value (integer or double): ";
    string pullRequestValueStr;
    cin >> pullRequestValueStr;

    // Перевірка, чи введене значення містить десяткову крапку
    processAndSortMatrix(matrix, pullRequestValueStr);

    // Виведення відсортованої матриці
    cout << "Sorted matrix:" << endl;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Обчислення сум і створення нового масиву
    int* sums = calculateSums(matrix);
    writeArrayToFile(sums, 10, FILENAME);

    // Виведення сум
    cout << "сумма випадкових елементів:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << sums[i] << " ";
    }
    cout << endl;

    // Запис масиву у файл
    string filename = "sums.txt";
    bool result = writeArrayToFile(sums, 10, filename);

    if (result) {
        cout << "Array was successfully written to " << filename << endl;
    } else {
        cout << "Failed to write array to file." << endl;
    }

    long long product = calculateProductFromFile(FILENAME);
    if (product != -1) {
        cout << "Product of elements from file: " << product << endl;
    }

    deleteFile(FILENAME);

    return 0;
}
