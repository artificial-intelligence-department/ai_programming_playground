#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 9;

void printSudoku(const vector<vector <int> > & sudoku) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << sudoku[i][j] << " ";
            if ((j + 1) % 3 == 0 && j < N - 1) {
                cout << "| ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i < N - 1) {
            cout << "---------------------" << endl;
        }
    }
}

bool isSafe(const vector<vector <int> > & sudoku, int x, int y, int num) {

    for (int i = 0; i < N; ++i) {
        if (sudoku[x][i] == num || sudoku[i][y] == num) {
            return false;
        }
    }

    int startRow = x - x % 3;
    int startCol = y - y % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (sudoku[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

void generateSudoku(vector<vector <int> > & sudoku) {
    srand(time(0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            sudoku[i][j] = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (rand() % 3 == 0) {
                int num = rand() % 9 + 1;
                if (isSafe(sudoku, i, j, num)) {
                    sudoku[i][j] = num;
                }
            }
        }
    }
}

int main() {

    vector<vector <int> > sudoku(N, vector <int> (N, 0));

    generateSudoku(sudoku);

    cout << "Початкове судоку:" << endl;
    printSudoku(sudoku);
    cout << endl;

    cout << "Розв'язати судоку. Введіть числа від 1 до 9 у форматі рядок, стовпець, число (наприклад, 3 4 6):" << endl;

    while (true) {
        int row, col, num;
        cout << "Введіть координати та число (або -1 для завершення): ";
        cin >> row;
        if (row == -1) {
            break;
        }
        cin >> col >> num;

        if (row < 1 || row > N || col < 1 || col > N || num < 1 || num > 9) {
            cout << "Неправильний ввід. Спробуйте ще раз." << endl;
            continue;
        }

        if (sudoku[row - 1][col - 1] == 0 && isSafe(sudoku, row - 1, col - 1, num)) {
            sudoku[row - 1][col - 1] = num;
            cout << "Додано число " << num << " в клітинку (" << row << ", " << col << ")." << endl;
        } else {
            cout << "Неправильний хід. Спробуйте ще раз." << endl;
        }

        cout << "Поточний стан судоку:" << endl;
        printSudoku(sudoku);
        cout << endl;
    }

    return 0;
}
