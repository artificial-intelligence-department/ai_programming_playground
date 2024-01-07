#include <iostream>
#include <set>

using namespace std;

int main() {
    int rows, colums;
    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> colums;

    int** array = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[colums];
    }

    cout << "Введіть елементи двовимірного масиву:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colums; ++j) {
            cout << "Елемент [" << i << "][" << j << "]: ";
            cin >> array[i][j];
        }
    }

    set<int> uniqueElements;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colums; ++j) {
            uniqueElements.insert(array[i][j]);
        }
    }

    int minElement = *uniqueElements.begin();

    cout << "Мінімальний з неповторюваних елементів: " << minElement << endl;

    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}