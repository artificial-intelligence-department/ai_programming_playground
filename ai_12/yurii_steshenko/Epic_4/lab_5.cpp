#include <iostream>
#include <vector>
using namespace std;

double sum(vector<int> row) {
    double sum = 0;

    for (int cell : row) 
        sum += cell;

    return sum;
}

int main() {
    int n, m;
    cout << "Enter count of rows and columns of matrix: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix elements: ";
    for (vector<int>& row : matrix) 
        for (int& cell : row)
            cin >> cell;

    double average;
    int bigger_than_average;
    for (int i = 0; i < n - 1; i++) {
        bigger_than_average = 0;
        average = sum(matrix[i]) / m;
        
        for (int& cell : matrix[i+1])
            if (cell > average) bigger_than_average++;

        cout << "Elements of " << i + 2 << " row bigger "
            "than average of " << i + 1 << "row (" << average << "): "
            << bigger_than_average << endl; 
    }

    return 0;
}