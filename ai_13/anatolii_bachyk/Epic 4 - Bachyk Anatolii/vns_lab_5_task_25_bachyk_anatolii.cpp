#include <iostream> 
#include <vector> 

using namespace std;

// Функція для відновлення двовимірного масиву з одновимірного
vector<vector<int>> restoreMatrix(vector<int>& arr, int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols)); // Створюємо двовимірний масив
    int index = 0; 

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = arr[index++]; // Копіюємо елементи з одновимірного масиву в двовимірний
        }
    }

    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            matrix[i][j] = arr[index++]; // Копіюємо елементи з одновимірного масиву в двовимірний
        }
    }

    return matrix; 
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // Одновимірний масив
    int rows = 3; 
    int cols = 4; 

    vector<vector<int>> matrix = restoreMatrix(arr, rows, cols); // Відновлюємо двовимірний масив

    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << ' '; 
        }
        cout << '\n'; 
    }

    return 0; 
}