//
// Created by olehio-p on 12/15/2023.
//
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <filesystem>


double** create_double_matrix();
int** create_int_matrix();
void printMatrix(int**);
void printMatrix(double**);
void sort_matrix(double**);
void sort_matrix(int**);
int* sum(int**);
int* sum(double**);
bool writeToFile(const std::string&, int*);
int readFromFile(const std::string&);
void deleteFile(const std::string&);


int main(int argc, char const *argv[])
{
    const int pull_request = 789;
    const std::string filename = "file.txt";
    int* arrayOfSum;
    std::cout << "Task 1" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    if(pull_request % 2 == 0) {
        auto matrix = create_double_matrix();
        printMatrix(matrix);
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "Task 2" << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        sort_matrix(matrix);
        printMatrix(matrix);
        arrayOfSum = sum(matrix);
    } else {
        auto matrix = create_int_matrix();
        printMatrix(matrix);
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << "Task 2" << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        sort_matrix(matrix);
        printMatrix(matrix);
        arrayOfSum = sum(matrix);
    }
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "Task 3" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    for(int i = 0; i < 10; i++) {
        std::cout << arrayOfSum[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "Task 4" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    bool status = writeToFile(filename, arrayOfSum);
    if(status) {
        std::cout << "The writing into file was successful" << std::endl;
    } else {
        std::cout << "Error occurred while writing into file" << std::endl;
    }
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "Task 5" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    readFromFile(filename);
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "Task 6" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    deleteFile(filename);
    return 0;
}

double** create_double_matrix() {
    auto **matrix = new double*[10];
    for(int i = 0; i < 10; i++) {
        matrix[i] = new double[10];
        for(int j = 0; j < 10; j++) {
            matrix[i][j] = sin(i + j);
        }
    }
    return matrix;
}

int** create_int_matrix() {
    auto** matrix = new int*[10];
    for(int i = 0; i < 10; i++) {
        matrix[i] = new int[10];
        for(int j = 0; j < 10; j++) {
            matrix[i][j] = pow(i + j, 2);
        }
    }
    return matrix;
}

void printMatrix(int** matrix) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printMatrix(double** matrix) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%6.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void sort_matrix(int** matrix) {
    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                if (matrix[i][j] < matrix[i][j + 1]) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][j + 1];
                    matrix[i][j + 1] = temp;
                }
            }
        }
    }
}

void sort_matrix(double** matrix) {
    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                if (matrix[j][i] > matrix[j + 1][i]) {
                    double temp = matrix[j][i];
                    matrix[j][i] = matrix[j + 1][i];
                    matrix[j + 1][i] = temp;
                }
            }
        }
    }
}


int* sum(int** matrix) {
    int sum;
    int* array = new int[10];

    srand(time(nullptr));

    for(int i = 0; i < 10; i++) {
        sum = 0;
        for(int j = 0; j < 10; j++) {
            sum += matrix[rand() % 10][i];
        }
        array[i] = sum;
    }
    return array;
}

int* sum(double** matrix) {
    double sum;
    int* array = new int[10];

    srand(time(nullptr));

    for(int i = 0; i < 10; i++) {
        sum = 0;
        for(int j = 0; j < 10; j++) {
            sum += matrix[rand() % 10][i];
        }
        array[i] = (int) sum;
    }
    return array;
}

bool writeToFile(const std::string& filename, int* array) {
     std::ofstream dest(filename);

     if(dest.is_open()) {
         for (int i = 0; i < 10; i++) {
             dest << array[i] << " ";
         }
     } else {
         return false;
     }
     dest.close();
     return true;
}

int readFromFile(const std::string& filename) {
    std::ifstream src(filename);
    int product = 1;
    int temp;

    if(src.is_open()) {
        for(int i = 0; i < 10; i++) {
            src >> temp;
            product *= temp;
        }
    } else {
        std::cout << "Error occurred while reading from file" << std::endl;
        return -1;
    }
    std::cout << "The product of the array is: " << product << std::endl;
    src.close();
    return product;
}

void deleteFile(const std::string& filename) {
    std::filesystem::path path(filename);
    bool status = false;

    if (std::filesystem::exists(path)) {
        status = std::filesystem::remove(path);
    }
    if(status) {
        std::cout << "The file was successfully deleted" << std::endl;
    } else {
        std::cout << "Couldn't delete file" << std::endl;
    }
}