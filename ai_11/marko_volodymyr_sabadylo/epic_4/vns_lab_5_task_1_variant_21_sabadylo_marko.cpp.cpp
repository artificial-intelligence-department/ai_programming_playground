#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функція для пошуку максимального повторюваного елемента
int findMaxDuplicate(const vector<vector<int>>& matrix) {
    unordered_map<int, int> countMap;
    int maxDuplicate = INT_MIN;

    // кількость повторюваних елементів
    for (const auto& row : matrix) {
        for (int element : row) {
            countMap[element]++;
            if (countMap[element] > 1 && element > maxDuplicate) {
                maxDuplicate = element;
            }
        }
    }

    return maxDuplicate;
}

// Функція для рандомного заповнення масиву
void fillMatrixRandomly(vector<vector<int>>& matrix) {
    srand(time(NULL));
    for (auto& row : matrix) {
        for (int& element : row) {
            element = rand() % 10 + 1; // Рандомні значення від 1 до 10
        }
    }
}

//виведення масиву
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {

    const int rows = 4;
    const int cols = 4;

  //заповнення масиву
    vector<vector<int>> matrix(rows, vector<int>(cols));
    fillMatrixRandomly(matrix);


    cout << "Randomly filled matrix:" << endl;
    printMatrix(matrix);

    // Знаходження та виведення максимального повторюваного елемента
    int result = findMaxDuplicate(matrix);
    if (result != INT_MIN) {
        cout << "\nMax Duplicate Element: " << result << endl;
    } else {
        cout << "\nNo duplicates found." << endl;
    }

    return 0;
}