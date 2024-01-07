#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int myPullRequestNumber = 71;

float** matrix() {
    float** matrica = new float* [10];

    for (size_t i = 0; i < 10; i++) {
        matrica[i] = new float[10];
        float a{ 0.5 };
        for (size_t j = 0; j < 10; j++) {
            matrica[i][j] = pow(i, a) / a;
            a += 0.5;
        }
    }
    return matrica;
}

int** matrixA() {
    int** matrica = new int* [10];

    int a{ 1 };

    for (size_t i = 0; i < 10; i++) {
        matrica[i] = new int[10];

        int j{ 0 };
        do {
            matrica[i][j] = pow(i + 1, a) / a;
            a += 1;
            j++;
        } while (j < 10);
    }
    return matrica;
}

void task2(float** matrica, int rows, int cols, float input) {
    for (size_t col = 0; col < cols; col++) {
        for (size_t i = 0; i < rows - 1; i++) {
            for (size_t j = 0; j < rows - i - 1; j++) {
                if (matrica[j][col] < matrica[j + 1][col]) {
                    swap(matrica[j], matrica[j + 1]);
                }
            }
        }
    }
}

void task2(int** matrica, int rows, int cols, int input) {
    for (size_t col = 0; col < cols; col++) {
        for (size_t i = 0; i < rows - 1; i++) {
            for (size_t j = 0; j < rows - i - 1; j++) {
                if (matrica[j][col] < matrica[j + 1][col]) {
                    swap(matrica[j], matrica[j + 1]);
                }
            }
        }
    }
}

template <typename T>
void output(T** matrix, int rows, int cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << setw(10)<<matrix[i][j] << " ";
        }
        cout << endl;
    }
}
template<typename T>
int* calculateSums(T** matrica, int rows, int cols) {
    int* sums = new int[10];

    srand(time(0));

    for (size_t col = 0; col < cols; col++) {
        int sum = 0;
        for (int k = 0; k < 4; k++) {
            int randomRow = rand() % rows;
            sum += floor(matrica[randomRow][col]);
        }
        sums[col] = sum;
    }

    return sums;
}

int main() {
    const int num = 1023;
    int task2inputInt{};
    float task2inputFloat{};

    if (num % 2 != 0) {
        float** matrica = matrix();
        output(matrica, 10, 10);
        cout << "Enter value int: ";
        cin >> task2inputInt;
        task2(matrica, 10, 10, task2inputInt);
        cout << "\n\n";
        output(matrica, 10, 10);

        int* columnSums = calculateSums(matrica, 10, 10);
        cout << "\nColumn Sums:\n";
        for (int i = 0; i < 10; i++) {
            cout << setw(5)<< columnSums[i] << " ";
        }
        delete[] columnSums;
    }
    else {
        int** matricaA = matrixA();
        output(matricaA, 10, 10);
        cout << "Enter value float: ";
        cin >> task2inputFloat;
        task2(matricaA, 10, 10, task2inputFloat);
        cout << "\n\n";
        output(matricaA, 10, 10);

        int* columnSums = calculateSums(matricaA, 10, 10);
        cout << "\nColumn Sums:\n";
        for (int i = 0; i < 10; i++) {
            cout << columnSums[i] << " ";
        }
        delete[] columnSums;
    }

    return 0;
}
