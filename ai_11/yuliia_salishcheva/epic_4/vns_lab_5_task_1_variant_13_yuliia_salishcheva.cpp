#include <iostream>
#include <vector>

using namespace std;

int searchColumn(const vector<vector<int>>& matrix) {

    int rows = matrix.size();
    int columns = matrix[0].size();

    for (int column = 0; column < columns - 1; ++column) {

        int SumLeft = 0;
        for (int rowleft = 0; rowleft < rows; ++rowleft) {
            SumLeft += matrix[rowleft][column];
        }

        int SumRight = 0;
        for (int rowright = 0; rowright < rows; ++rowright) {
            SumRight += matrix[rowright][column + 1];
        }

        if (SumLeft > SumRight) {
            return column;
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 3, 0},
        {5, 1, 0, 0},
        {9, 2, 1, 2}
    };

    int result = searchColumn(matrix);

    if (result != -1) {
        cout << "Column " << result + 1 << " divides into greater and smaller sum\n";
    }
    else {
        cout << "There is no such column\n";
    }
}
