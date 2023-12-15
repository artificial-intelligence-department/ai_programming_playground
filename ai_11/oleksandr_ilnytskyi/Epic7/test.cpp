#include <iostream>
#include <cmath>
#include <random>

using namespace std;

int generateNum(float x, float y) { // Task 2v1 function
    const float b = 1.19;
    const float c = -2.5;

    float result = b * pow(x, 2) + c * sin(2 * x);

    return result;
}

int generateNum(int x, int y) { // Task 2v2 function
    const int a = 1;
    const int b = 2;

    return pow(a, x) + pow(b, y);
}

auto createMatrixOdd() {
    auto matrix = new int[10 * 10];
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            matrix[x*10 + y] = generateNum(x, y);
        }
    }

    return matrix;
}

auto createMatrixEven() {
    auto matrix = new float[10 * 10];
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            matrix[x*10 + y] = generateNum(x, y);
        }
    }

    return matrix;
}

void sortMatrix (float* matrix, int pullNum) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            float y1 = matrix[x * 10 + y];
            float y2 = matrix[x * 10 + y + 1];
            if (y1 < y2) {
                matrix[x * 10 + y] = y2;
                matrix[x * 10 + y + 1] = y1;
                --y;
            }
        }
    }
}

void sortMatrix(int* matrix, int pullNum) {
    for (int row = 0; row < 10; row++) {
        for (int i = row * 10; i < (row + 1) * 10 - 1; i++) {
            for (int j = row * 10; j < (row + 1) * 10 - i + row * 10 - 1; j++) {
                if (matrix[j] < matrix[j + 1]) {
                    int temp = matrix[j];
                    matrix[j] = matrix[j + 1];
                    matrix[j + 1] = temp;
                }
            }
        }
    }
}


void printMatrix (int* matrix) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            cout << matrix[x * 10 + y] << " ";
        }
        cout << endl;
    }
}

void printMatrix (float* matrix) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            cout << matrix[x * 10 + y] << " ";
        }
        cout << endl;
    }
}

void setRandom(int* matrix) {
        // Seed the random number generator
        int* result = new int[10];
        std::random_device rd;
        std::mt19937 gen(rd());

        // Define the range for the random number
        int lower_bound = 0;  // Change this to set the lower bound
        int upper_bound = 9;  // Change this to set the upper bound
        std::uniform_int_distribution<> dist(lower_bound, upper_bound);

        // Generate a random integer
        int random_num = dist(gen);
        for (int i = 0; i < 10; i++) {
            int randomx = dist(gen);
            int randomy = dist(gen);
            result[i] = matrix[randomx * 10 + randomy];
        }

        matrix = result;
}


int main() {
    const int pullNum = 955;
    if (pullNum % 2 == 1) {
        auto m1 = createMatrixOdd();
        printMatrix(m1);
        sortMatrix(m1 , pullNum);
        printMatrix(m1);
        setRandom(m1);
        printMatrix(m1);
    }
    else {
        auto m2 = createMatrixEven();
        printMatrix(m2);
    }

    return 0;
}
