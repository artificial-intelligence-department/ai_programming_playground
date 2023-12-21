#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Функція для відновлення двовимірного масиву
vector<vector<int>> f_array(const vector<int>& value_array, int rows, int cols) 
{
    // Створюємо порожній двовимірний масив 
    vector<vector<int>> my_array(rows, vector<int>(cols, 0));

    // Заповнюємо масив елементами з одновимірного масиву
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            my_array[i][j] = value_array[i * cols + j];
        }
    }

    return my_array;
}

int main() {
    // Задаємо розмірність двовимірного масиву
    int rows, cols;
    cout << "enter number of rows: ";
    cin >> rows;
    cout << "enter number of cols: ";
    cin >> cols;

    // Створюємо та виводимо випадковий одновимірний масив
    vector<int> value_array(rows * cols);
    cout << "enter elements of one-dimensional maisv:" << endl;
    for (int i = 0; i < rows * cols; ++i) {
        cin >> value_array[i];
    }

    // Відновлюємо двовимірний масив
    vector<std::vector<int>> originalArray = f_array(value_array, rows, cols);

    // Виводимо відновлений двовимірний масив
    cout << "Recovered two-dimensional array:"<< endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << originalArray[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
