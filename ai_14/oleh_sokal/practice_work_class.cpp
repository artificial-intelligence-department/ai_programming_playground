#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int rows = 10;
const int cols = 10;

void bubbleSort(float arr[rows][cols]) {
    for (int j = 0; j < cols; ++j) {
        for (int k = 0; k < rows; ++k) {
            for (int i = 0; i < rows - 1; ++i) {
                if (arr[i][j] > arr[i + 1][j]) {
                    float temp = arr[i][j];
                    arr[i][j] = arr[i + 1][j];
                    arr[i + 1][j] = temp;
                }
            }
        }
    }
}

void bubbleSort(int arr[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int k = 0; k < cols; ++k) {
            for (int j = 0; j < cols - 1; ++j) {
                if (arr[i][j] < arr[i][j + 1]) {
                    int temp = arr[i][j];
                    arr[i][j] = arr[i][j + 1];
                    arr[i][j + 1] = temp;
                }
            }
        }
    }
}

void generateMatrix(int arr[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int arr[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << '\t';
        }
        cout << '\n';
    }
}

int* calculateColumnSums(float arr[rows][cols]) {
    static int sums[10];
    for (int j = 0; j < 10; ++j) {
        float sum = 0;
        for (int k = 0; k < 4; ++k) {
            int randomIndex = rand() % 10;
            sum += arr[randomIndex][j];
        }
        sums[j] = static_cast<int>(sum);
    }
    return sums;
}

int* calculateColumnSums(int arr[rows][cols]) {
    static int sums[10];
    for (int j = 0; j < 10; ++j) {
        int sum = 0;
        for (int k = 0; k < 4; ++k) {
            int randomIndex = rand() % 10;
            sum += arr[randomIndex][j];
        }
        sums[j] = sum;
    }
    return sums;
}

bool writeArrayToFile(const int array[10], const std::string& fileName) {
    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return false;
    }

    for (int i = 0; i < 10; ++i) {
        file << array[i] << '\n';
    }

    file.close();
    return true;
}

int calculateProductFromFile(const std::string& fileName) {
    int product = 1;
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        return 0;
    }

    int value;
    while (file >> value) {
        product *= value;
    }

    file.close();
    return product;
}

void deleteFile(const std::string& fileName) {
    if (remove(fileName.c_str()) != 0) {
        cerr << "Error deleting file: " << fileName << endl;
    } else {
        cout << "File deleted: " << fileName << endl;
    }
}

void mainFunction() {
    int resultMatrix[rows][cols];
    generateMatrix(resultMatrix);

    cout << "Original matrix:\n";
    printMatrix(resultMatrix);


    bubbleSort(resultMatrix);

    cout << "\nSorted matrix:\n";
    printMatrix(resultMatrix);


    cout << "Enter the filename: ";
    std::string userFileName;
    getline(cin, userFileName);


    int* sums = calculateColumnSums(resultMatrix);

    cout << "\nColumn Sums:\n";
    for (int i = 0; i < 10; ++i) {
        cout << sums[i] << '\t';
    }


    if (writeArrayToFile(sums, userFileName)) {
        cout << "\nArray successfully written to file.\n";
    } else {
        cerr << "Failed to write array to file.\n";
    }


    int product = calculateProductFromFile(userFileName);
    cout << "\nProduct of elements from file: " << product << endl;

    deleteFile(userFileName);
}

int main() {
    mainFunction();
    return 0;
}
