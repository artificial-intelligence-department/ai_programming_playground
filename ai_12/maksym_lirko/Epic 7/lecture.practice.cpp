#include <iostream>
#include <cmath>
using namespace std;

double FUNC(double x) {
    return ((-2.4 * x) + (5 * x) - 3);
}

void MATRIX1(int matrix[10][10], double element) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = abs((i + 1) * (j + 1) - static_cast<int>(element));
        }
    }
}

int main() {
    const int number_of_variant = 941;
    int matrix[10][10];

    if (number_of_variant % 2 == 0) {
        double element = FUNC(number_of_variant); // Використовуємо тип double
        MATRIX1(matrix, element);

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    } else {
        cout << "Const is not % 2 == 0" << endl;
    }

    return 0;
}
