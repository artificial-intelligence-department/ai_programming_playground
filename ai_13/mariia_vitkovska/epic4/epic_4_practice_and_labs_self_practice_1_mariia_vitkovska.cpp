#include <iostream>

using namespace std;
int main() {
    const int size = 3; // розмір масиву
    int matrix[size][size];

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << "Enter a value for the element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

     int selectedRowIndex, selectedColIndex;
    cout << "Enter the row index of the selected element of the main diagonal (from 0 to " << size - 1 << "): ";
    cin >> selectedRowIndex;

    // Перевірка коректності введеного індексу рядка
    if (selectedRowIndex < 0 || selectedRowIndex >= size) {
        cerr << "Incorrect index of the row" << endl;
        return 1;
    }

    // Вибір індексу стовпця обраного елемента головної діагоналі
    selectedColIndex = selectedRowIndex;

    // Вибір обраного елемента для порівняння
    int selectedElement = matrix[selectedRowIndex][selectedColIndex];


    // Підрахунок кількості елементів більших вибраного елемента
    int count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            // Порівнюємо вибраний елемент з іншими елементами у масиві
            if (matrix[i][j] > selectedElement) {
                count++;
            }
        }
    }

    // Виведення результату
    std::cout << "Number of elements that are bigger than choosen element: " << count << std::endl;

    return 0;
}