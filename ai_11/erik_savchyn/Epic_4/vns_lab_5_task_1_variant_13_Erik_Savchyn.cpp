#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int rows = 9;
const int cols = 9;

void fillArrayRandom(int arr[][cols]) {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 10;
        }
    }
}

void printArray(int arr[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool findSplitColumn(int arr[][cols]) {
    for (int j = 1; j < cols - 1; j++) {
        int leftSum = 0;
        int rightSum = 0;

        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < cols; k++) {
                if (i < j) {
                    leftSum += arr[k][i];
                } else if (i > j) {
                    rightSum += arr[k][i];
                }
            }
        }

        if (leftSum > rightSum) {
            cout << "Стовпець " << j+1 << " розбиває масив з більшою сумою у першій частині.\n";
            cout << "L = " << leftSum << endl;
            cout << "R = " << rightSum << endl;
            return true;
        }
    }

    cout << "Не знайдено стовпця, що розбиває масив на дві частини з більшою сумою у першій.\n";
    return false;
}

int main() {
    int array[rows][cols];

    fillArrayRandom(array);

    cout << "Заповнений масив випадковими числами:\n";
    printArray(array);

    findSplitColumn(array);

    return 0;
}
