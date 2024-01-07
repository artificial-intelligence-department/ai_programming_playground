#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

float** generateFloatMatrix() {
    float** matrix = new float*[10];
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new float[10];
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        }
    }
    return matrix;
}

int** generateIntMatrix() {
    int** matrix = new int*[10];
    for (int i = 0; i < 10; ++i) {
        matrix[i] = new int[10];
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}

int* calculateColumnSums(void* matrix, bool isFloat) {
    int* sums = new int[10];
    for (int j = 0; j < 10; ++j) {
        float columnSum = 0.0;
        for (int i = 0; i < 10; ++i) {
            if (isFloat) {
                float** floatMatrix = reinterpret_cast<float**>(matrix);
                columnSum += floatMatrix[i][j];
            } else {
                int** intMatrix = reinterpret_cast<int**>(matrix);
                columnSum += intMatrix[i][j];
            }
        }
        // Генеруємо 3-4 рандомні числа для обчислення суми, якщо кількість елементів в стовпці більше 4
        for (int k = 0; k < 10; ++k) {
            int randomIndex = rand() % 10;
            if (isFloat) {
                float** floatMatrix = reinterpret_cast<float**>(matrix);
                columnSum += floatMatrix[randomIndex][j];
            } else {
                int** intMatrix = reinterpret_cast<int**>(matrix);
                columnSum += intMatrix[randomIndex][j];
            }
        }
        sums[j] = static_cast<int>(columnSum); // Записуємо цілочисельне значення суми у масив
    }
    return sums;
}

bool writeArrayToFile(int* array) {
    const std::string fileName = "array_values.txt"; // Константа з іменем файлу

    std::ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        outputFile << array[i] << " ";
    }

    outputFile.close();
    return true;
}

int calculateProductFromFile() {
    const std::string fileName = "array_values.txt"; // Константа з іменем файлу

    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return 0;
    }

    int product = 1;
    int num;
    while (inputFile >> num) {
        product *= num;
    }

    inputFile.close();
    return product;
}

void deleteFile() {
    const std::string fileName = "array_values.txt"; // Константа з іменем файлу

    if (std::remove(fileName.c_str()) != 0) {
        std::cerr << "Error deleting the file." << std::endl;
    } else {
        std::cout << "File deleted successfully." << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int pullRequestNumber = 1019; // Приклад значення номеру пул-реквесту (змініть на потрібне)

    float** floatMatrix = generateFloatMatrix();
    int** intMatrix = generateIntMatrix();

    float floatingValue;
    std::cout << "Enter a floating-point value: ";
    std::cin >> floatingValue;

    bool isFloatMatrix = (pullRequestNumber % 2 == 0);
    void* matrix = (isFloatMatrix) ? static_cast<void*>(floatMatrix) : static_cast<void*>(intMatrix);

    int* resultArray = calculateColumnSums(matrix, isFloatMatrix);

    if (writeArrayToFile(resultArray)) {
        std::cout << "Array values successfully written to the file." << std::endl;
    } else {
        std::cout << "Failed to write array values to the file." << std::endl;
    }

    int product = calculateProductFromFile(); // Обчислення добутку чисел з файлу
    std::cout << "Product of numbers from file: " << product << std::endl;

    deleteFile(); // Видалення файлу

    // Очищення пам'яті
    for (int i = 0; i < 10; ++i) {
        delete[] floatMatrix[i];
        delete[] intMatrix[i];
    }
    delete[] floatMatrix;
    delete[] intMatrix;
    delete[] resultArray;

    return 0;
}
