#include <iostream>

using namespace std;

int main() {
    int n, m;
    int* arr;
    int** matrix;

    cout << "Введіть кількість рядків: ";
    cin >> n;
    cout << "Введіть кількість стовпців: ";
    cin >> m;


    arr = new int[n * m];


    for (int i = 0; i < n * m; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }


    matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }


    int j = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            matrix[i][k] = arr[j++];
        }
    }


    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cout << matrix[i][k] << " ";
        }
        cout << endl;
    }


    delete[] arr;
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
