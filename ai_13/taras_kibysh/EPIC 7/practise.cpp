#include <iostream>
#include <fstream>
#include <cmath>

const int group = 13;

int** matrix() {
    int** matrix = new int*[10];
    int x = 3;
    double E = 2.71828;

    for (int i = 0; i < 10; i++) {
        matrix[i] = new int[10];
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = group * static_cast<int>(cos(pow(x, 2)) * pow(E, -x));
        }
    }

    return matrix;
}

int** function(int** a, int b) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[i][j] > a[i][j + 1]) {
                int temp = a[i][j];
                a[i][j] = a[i][j + 1];
                a[i][j + 1] = temp;
            }
        }
    }

    return a;
}

double** function(int** a, double b) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[i][j] > a[i][j + 1]) {
                int temp = a[i][j];
                a[i][j] = a[i][j + 1];
                a[i][j + 1] = temp;
            }
        }
    }

    double** ans = new double*[10];
    for (int i = 0; i < 10; i++) {
        ans[i] = new double[10];
        for (int j = 0; j < 10; j++) {
            ans[i][j] = a[i][j];
        }
    }

    return ans;
}

int calculateColumnSum(int** a, int columnIndex) {
    int sum = 0;
    int count = 0;

    for (int i = 0; i < 4; ++i) {
        int row = rand() % 10;
        sum += a[row][columnIndex];
        ++count;
    }

    if (count == 4) {
        sum /= count;
    }

    return sum;
}

int* calculateSums(int** a) {
    static int sums[10];

    for (int i = 0; i < 10; ++i) {
        int columnSum = calculateColumnSum(a, i);
        sums[i] = static_cast<int>(columnSum);
    }

    return sums;
}

bool file(int* sum) {
    std::ofstream file("file.txt");

    if (!file.is_open()) {
        return false; // Якщо не вдалося відкрити файл
    }

    for (int i = 0; i < 10; i++) {
        file << "Sum: " << sum[i] << std::endl;
    }

    file.close();
    return true;
}

int main() {
    int** a = matrix();
    int** b = function(a, 2.5);
    int* massive = calculateSums(b);

    bool answear = file(massive);
    cout << answear
    // Вивільнення пам'яті
    for (int i = 0; i < 10; i++) {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;

    return 0;
}
