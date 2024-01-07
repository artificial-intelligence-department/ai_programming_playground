#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

// Визначення функцій
void floatmatrix(double y);
void intmatrix(int zround);
void sortMatrix(double arr[][10]);  // Оголошення нової функції для сортування матриці типу double
void sortMatrix(int arr[][10]);  // Оголошення нової функції для сортування матриці типу int
int* calculateColumnSums(double arr[][10]);  // Оголошення нової функції для розрахунку сум стовпців матриці типу double

// Константа
const int nomer = 933;

// Масиви
double masuv[10][10];
int matrix[10][10];

// Змінні
double h = 0.5;
double x = -2.5;
double z = 0;
double y = 0;
int zround = 0;

int main() {
    int count = 0;
    for(x; x <= 2; x += h) {
        z = fabs(x) + pow(x, 2);
        y = z * (sin(pow((2 + x), 2))) / (2 + x);
        zround = round(y);

        if(nomer % 2 == 0) {
            floatmatrix(y);
        } else {
            intmatrix(zround);
        }
        count++;
        if(count == 10) break;
    }

    // Виклик функції для сортування матриці типу double
    sortMatrix(masuv);

    // Виклик функції для сортування матриці типу int
    sortMatrix(matrix);

    // Виклик функції для розрахунку сум стовпців матриці типу double
    int* columnSums = calculateColumnSums(masuv);

    // Очистка виділеної пам'яті
    delete[] columnSums;

    return 0;
}

// Функція для створення матриці з числами з плаваючою крапкою
void floatmatrix(double y) {
    static int row = 0;
    for(int j = 0; j < 10; j++) {
        masuv[row][j] = y;
    }

    row++;
    if(row == 10) {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                cout << masuv[i][j] << " ";
            }
            cout << endl;
        }
    }
}

// Функція для створення матриці з цілими числами
void intmatrix(int zround) {
    static int row = 0;
    for(int j = 0; j < 10; j++) {
        matrix[row][j] = zround;
    }

    row++;
    if(row == 10) {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}

// Функція для сортування матриці типу double
void sortMatrix(double arr[][10]) {
    for (int col = 0; col < 10; col++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9 - i; j++) {
                if (arr[j][col] > arr[j + 1][col]) {
                    double temp = arr[j][col];
                    arr[j][col] = arr[j + 1][col];
                    arr[j + 1][col] = temp;
                }
            }
        }
    }

    // Виведення відсортованої матриці
    cout << "Sorted matrix:" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Функція для сортування матриці типу int
void sortMatrix(int arr[][10]) {
    for (int row = 0; row < 10; row++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9 - i; j++) {
                if (arr[row][j] < arr[row][j + 1]) {
                    int temp = arr[row][j];
                    arr[row][j] = arr[row][j + 1];
                    arr[row][j + 1] = temp;
                }
            }
        }
    }

    // Виведення відсортованої матриці
    cout << "Sorted matrix:" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Функція для розрахунку сум стовпців матриці типу double
int* calculateColumnSums(double arr[][10]) {
    static int columnSums[10];
    for (int col = 0; col < 10; col++) {
        double sum = 0;
        for (int row = 0; row < 10; row++) {
            sum += arr[row][col];
        }
        columnSums[col] = static_cast<int>(sum);  // Перетворення суми в ціле число
    }

    // Виведення сум стовпців
    cout << "Sum of columns:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << columnSums[i] << " ";
    }
    cout << endl;

    return columnSums;
}
