#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>

const int PR = 823;
const char FILE_NAME[] = "output.txt";


void generateMatrix(float matrix[10][10]) {
    const double e = 2.71828;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int x = i * 0.1 + j * 0.01;
            matrix[i][j] = cos(pow(x,2))*pow(e,-x);
        }
    }
}
void generateMatrix(int matrix[10][10]) {
    const double e = 2.71828;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int x = i * 0.1 + j * 0.01;
            matrix[i][j] = cos(pow(x,2))*pow(e,-x);
        }
    }
}

void generateIntegerMatrix(int matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = static_cast<int>(cos(pow(i * 0.1 + j * 0.01, 2)) * pow(exp(1), -(i * 0.1 + j * 0.01)));
        }
    }
}
void generateIntegerMatrix(float matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = static_cast<int>(cos(pow(i * 0.1 + j * 0.01, 2)) * pow(exp(1), -(i * 0.1 + j * 0.01)));
        }
    }
}

void printMatrix(float matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void printMatrix(int matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

template <typename T>
void bubbleSort(T matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9 - j; k++) {
                if (matrix[k][i] > matrix[k + 1][i]) {
                    std::swap(matrix[k][i], matrix[k + 1][i]);
                }
            }
        }
    }
}

int* calculateSums(float matrix[10][10], int seed) {
    srand(seed);
    static int sums[10] = {0};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            int randomIndex = rand() % 10;
            sums[i] += matrix[randomIndex][i];
        }
    }

    return sums;
}
int* calculateSums(int matrix[10][10], int seed) {
    srand(seed);
    static int sums[10] = {0};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            int randomIndex = rand() % 10;
            sums[i] += matrix[randomIndex][i];
        }
    }

    return sums;
}

bool writeToFile(int sums[10]) {
    std::ofstream file(FILE_NAME);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return false;
    }

    for (int i = 0; i < 10; i++) {
        file << sums[i] << " ";
    }

    file.close();
    return true;
}

int calculateProductFromFile() {
    std::ifstream file(FILE_NAME);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
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

void deleteFile() {
    if (remove(FILE_NAME) != 0) {
        std::cerr << "Error deleting file." << std::endl;
    } else {
        std::cout << "File deleted successfully." << std::endl;
    }
}

void bubbleSort(int arr[10][10], int n) 
{
    for(int q=0;q<10;q++)
    {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                // Swap if the element found is less than the next element
                if (arr[q][j] < arr[q][j + 1]) {
                    std::swap(arr[q][j], arr[q][j + 1]);
                }
            }
        }
    }
    
}
int sum(int matrix[10][10])
{
    
}
int main()
{
    const int PR = 823;

     if (PR % 2 == 0) {
        float matrix[10][10];
        generateMatrix(matrix);

        printMatrix(matrix);

        bubbleSort(matrix);

        std::cout << "\nSorted Matrix (Floating-point):" << std::endl;
        printMatrix(matrix);

        int seed;
        std::cout << "Enter a seed value: ";
        std::cin >> seed;

        int* sums = calculateSums(matrix, seed);

        if (writeToFile(sums)) {
            std::cout << "File written successfully." << std::endl;
        }

        int product = calculateProductFromFile();
        std::cout << "Product of values from file: " << product << std::endl;

        deleteFile();
    } else {
        int matrix[10][10];
        generateIntegerMatrix(matrix);

        printMatrix(matrix);

        bubbleSort(matrix);

        std::cout << "\nSorted Matrix (Integer):" << std::endl;
        printMatrix(matrix);

        int input;
        std::cout << "Enter a floating-point value: ";
        std::cin >> input;

        int product = PR * static_cast<int>(input);

        int* sums = calculateSums(matrix, product);

        if (writeToFile(sums)) {
            std::cout << "File written successfully." << std::endl;
        }

        product = calculateProductFromFile();
        std::cout << "Product of values from file: " << product << std::endl;

        deleteFile();
    }



    return 0;
}
