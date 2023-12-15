#include <iostream>
#include <vector>
using namespace std;

// Функція для обчислення суми елементів нижче головної діагоналі
int fsum(const vector<vector<int>> &matrix) {
    int S = matrix.size();
    int sum = 0;
    for (int r = 1; r < S; r++) {
        for (int st = 0; st < r; st++) {
            sum += matrix[r][st];
        }
    }
    return sum;
}

 // Функція для знаходження максимальної суми елементів нижче головної діагоналі серед n матриць
int fmaxsum(const vector<vector<vector<int>>> &matrices) {
    int maxsum = 0;
    for (const auto &matrix : matrices) {   
        int currsum = fsum(matrix);
        if (currsum > maxsum) {
            maxsum = currsum;
        }
    }
    return maxsum;
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<vector<vector<int>>> matrices;
    for (int i = 0; i < n; i++) {
    int size;
    cout << "Enter the size of the square matrix " << i + 1 << ": ";
    cin >> size;

    vector<vector<int>> matrix(size, vector<int>(size));  
    cout << "Enter the matrix elements " << size << "x" << size << ":" << endl;
        for (int r = 0; r < size; r++) {
            for (int st = 0; st < size; st++) {
                cin >> matrix[r][st];                                      
            }
    }

    matrices.push_back(matrix);                                    
    }

    int maxsum = fmaxsum(matrices);
    cout << "The maximum sum of elements below the main diagonal in matrices: " << maxsum;

    return 0;
}
