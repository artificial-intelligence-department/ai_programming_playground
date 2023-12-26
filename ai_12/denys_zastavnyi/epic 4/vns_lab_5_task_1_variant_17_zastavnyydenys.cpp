#include <iostream>
#include <climits>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;


void findMaxSubarray(int array[MAX_N][MAX_M], int n, int m) {  // Функція для пошуку підмасиву 3x3 з максимальною сумою
    int maxSum = INT_MIN;
    int maxSubarrayRow = -1;
    int maxSubarrayCol = -1;

    for (int i = 0; i <= n - 3; ++i) { //всі можливі 3x3 підмасиви
        for (int j = 0; j <= m - 3; ++j) {
            int currentSum = 0;
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    currentSum += array[i + k][j + l];
                }
            }

            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxSubarrayRow = i;
                maxSubarrayCol = j;
            }
        }
    }

    cout << "Maximum sum of 3x3 subarray: " << maxSum << endl;
    cout << "Starting index of row: " << maxSubarrayRow << endl;
    cout << "Starting index of column: " << maxSubarrayCol << endl;
}

int main() {
    int n, m;

    cout << "Enter the dimensions of the array (N x M): ";
    cin >> n >> m;

    int array[MAX_N][MAX_M];

    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "element [" << i << "][" << j << "]: ";
            cin >> array[i][j];
        }
    }

   
    findMaxSubarray(array, n, m);

    return 0;
}
