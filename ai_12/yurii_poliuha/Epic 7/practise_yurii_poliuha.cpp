#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Func();
void Func2(double array[][10], int Size);
int* calculateSums(double array[][10], int Size);

int main() {
    const int n = 1016;
    if (n % 2 == 0)
        Func();

    return 0;
}

void Func() {
    double a = 0.5, b = 3.1, x = 1.4;
    const int Size = 10;
    double array[Size][Size];
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            array[i][j] = 1 / pow(cos(pow(x, 3)), 2) - x / cbrt(pow(a, 2) + pow(b, 2));
            cout << fixed << setprecision(3) << array[i][j] << "\t";
            x += 0.5;
            b += 0.3;
            a += 0.5;
        }
        cout << endl;
    }

    Func2(array, Size);
}

void Func2(double array[][10], int Size) {
    for (int j = 0; j < Size; ++j) {
        for (int i = 0; i < Size - 1; ++i) {
            for (int k = 0; k < Size - i - 1; ++k) {
                if (array[k][j] > array[k + 1][j]) {
                    double temp = array[k][j];
                    array[k][j] = array[k + 1][j];
                    array[k + 1][j] = temp;
                }
            }
        }
    }
    cout << endl;
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            cout << fixed << setprecision(3) << array[i][j] << "\t";
        }
        cout << endl;
    }
}

int* calculateSums(double array[][10], int Size) {
    int* sumsArray = new int[Size];

    // Створення та встановлення генератора випадкових чисел
    srand(static_cast<unsigned>(time(0)));

    for (int j = 0; j < Size; ++j) {
        double sum = 0.0;
        // Вибір кількості елементів (3 або 4)
        int elementsCount = rand() % 2 + 3;

        for (int k = 0; k < elementsCount; ++k) {
            // Вибір рандомного рядка
            int randomRow = rand() % Size;
            sum += array[randomRow][j];
        }

        // Запис суми у масив (дробова частина відкидається)
        sumsArray[j] = static_cast<int>(sum);
    }

    return sumsArray;
}