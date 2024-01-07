#include <iostream>
#include <limits>

using namespace std;

int foundelement(int matrix[4][4]) {
    bool numbers[101] = {false};  
    int minelement = numeric_limits<int>::max();

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int element = matrix[i][j];
            
            if (!numbers[element]) {
                numbers[element] = true;

                if (element < minelement) {
                    minelement = element;
                }
            }
        }
    }

    return minelement;
}

int main() {
    int matrix[4][4] = {
        {3, 2, 4, 5},
        {1, 2, 3, 6},
        {5, 6, 7, 8},
        {9, 9, 7, 8}
    };

    int result = foundelement(matrix);

    cout << "Мінімальний неповторюваний елемент: " << result << endl;

    return 0;
}

