#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>

const int PR = 823;
const char FILE_NAME[] = "output.txt";

// Function to generate a matrix of floating-point numbers
void generateMatrix(float matrix[10][10]) {
    // Constants
    const double e = 2.71828;

    // Nested loops to fill the matrix with values from a mathematical function
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int x = i * 0.1 + j * 0.01;
            matrix[i][j] = cos(pow(x,2))*pow(e,-x);
        }
    }
}

// Function to generate a matrix of integers
void generateMatrix(int matrix[10][10]) {
    // Constants
    const double e = 2.71828;

    // Nested loops to fill the matrix with values from a mathematical function
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int x = i * 0.1 + j * 0.01;
            matrix[i][j] = cos(pow(x,2))*pow(e,-x);
        }
    }
}

// Function to generate a matrix of integers
void generateIntegerMatrix(int matrix[10][10]) {
    // Nested loops to fill the matrix with integer values from a mathematical function
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = static_cast<int>(cos(pow(i * 0.1 + j * 0.01, 2)) * pow(exp(1), -(i * 0.1 + j * 0.01)));
        }
    }
}

// Function to generate a matrix of floating-point numbers and cast to integers
void generateIntegerMatrix(float matrix[10][10]) {
    // Nested loops to fill the matrix with integer values from a mathematical function
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = static_cast<int>(cos(pow(i * 0.1 + j * 0.01, 2)) * pow(exp(1), -(i * 0.1 + j * 0.01)));
        }
    }
}

// Function to print a matrix of floating-point numbers
void printMatrix(float matrix[10][10]) {
    // Nested loops to print each element of the matrix
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Function to print a matrix of integers
void printMatrix(int matrix[10][10]) {
    // Nested loops to print each element of the matrix
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Template function for bubble sort on a 2D array
template <typename T>
void bubbleSort(T matrix[10][10]) {
    // Triple nested loops for bubble sort on each column
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9 - j; k++) {
                // Swap if the element found is less than the next element
                if (matrix[k][i] > matrix[k + 1][i]) {
                    std::swap(matrix[k][i], matrix[k + 1][i]);
                }
            }
        }
    }
}

// Function to calculate sums of random elements in columns for floats
int* calculateSums(float matrix[10][10], int seed) {
    // Seed the random number generator
    srand(seed);
    static int sums[10] = {0};

    // Double nested loops to calculate sums of random elements in columns
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            int randomIndex = rand() % 10;
            sums[i] += matrix[randomIndex][i];
        }
    }

    return sums;
}

// Function to calculate sums of random elements in columns for integers
int* calculateSums(int matrix[10][10], int seed) {
    // Seed the random number generator
    srand(seed);
    static int sums[10] = {0};

    // Double nested loops to calculate sums of random elements in columns
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            int randomIndex = rand() % 10;
            sums[i] += matrix[randomIndex][i];
        }
    }

    return sums;
}

// Function to write sums to a file
bool writeToFile(int sums[10]) {
    // Open the file for writing
    std::ofstream file(FILE_NAME);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return false;
    }

    // Write sums to the file
    for (int i = 0; i < 10; i++) {
        file << sums[i] << " ";
    }

    // Close the file
    file.close();
    return true;
}

// Function to calculate the product of values from a file
int calculateProductFromFile() {
    // Open the file for reading
    std::ifstream file(FILE_NAME);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 0;
    }

    int product = 1;
    int value;

    // Read values from the file and calculate the product
    while (file >> value) {
        product *= value;
    }

    // Close the file
    file.close();
    return product;
}

// Function to delete the file
void deleteFile() {
    // Attempt to delete the file
    if (remove(FILE_NAME) != 0) {
        std::cerr << "Error deleting file." << std::endl;
    } else {
        std::cout << "File deleted successfully." << std::endl;
    }
}

// Function to perform bubble sort on a 2D array of integers
void bubbleSort(int arr[10][10], int n) {
    // Triple nested loops for bubble sort on each column
    for(int q=0;q<10;q++) {
        for (int i = 0; i < n - 1; i++){
 for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is less than the next element
            if (arr[q][j] < arr[q][j + 1]) {
                std::swap(arr[q][j], arr[q][j + 1]);
            }
        }
    }
}

// Function to calculate the sum of elements in a matrix
int sum(int matrix[10][10]) {
    // To be implemented
    // Add the necessary logic to calculate the sum of elements in the matrix
}

int main() {
    const int PR = 823;

    // Check if PR is even or odd
    if (PR % 2 == 0) {
        float matrix[10][10];
        generateMatrix(matrix);

        std::cout << "Original Matrix (Floating-point):" << std::endl;
        printMatrix(matrix);

        // Perform bubble sort on the matrix
        bubbleSort(matrix);

        std::cout << "\nSorted Matrix (Floating-point):" << std::endl;
        printMatrix(matrix);

        // Get a seed value from the user
        int seed;
        std::cout << "\nEnter a seed value: ";
        std::cin >> seed;

        // Calculate sums, write to file, and perform additional operations
        int* sums = calculateSums(matrix, seed);

        if (writeToFile(sums)) {
            std::cout << "\nFile written successfully." << std::endl;
        }

        int product = calculateProductFromFile();
        std::cout << "Product of values from file: " << product << std::endl;

        deleteFile();
    } else {
        int matrix[10][10];
        generateIntegerMatrix(matrix);

        std::cout << "Original Matrix (Integer):" << std::endl;
        printMatrix(matrix);

        // Perform bubble sort on the matrix
        bubbleSort(matrix);

        std::cout << "\nSorted Matrix (Integer):" << std::endl;
        printMatrix(matrix);

        // Get a floating-point input from the user
        int input;
        std::cout << "\nEnter a floating-point value: ";
        std::cin >> input;

        int product = PR * static_cast<int>(input);

        int* sums = calculateSums(matrix, product);

        if (writeToFile(sums)) {
            std::cout << "\nFile written successfully." << std::endl;
        }

        product = calculateProductFromFile();
        std::cout << "Product of values from file: " << product << std::endl;

        deleteFile();
    }

    return 0;
}


