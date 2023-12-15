//селфпрак використовує рекурсію та перевантаження функції для обчислення одновимірного та двовимірного масиву
#include <iostream>
#include <vector>

using namespace std;

int arsum(const vector<int>& arr, int n) { // Рекурсивна функція для обчислення суми елементів одновимірного масиву
    if (n <= 0)
        return 0;
    else
        return (arsum(arr, n - 1) + arr[n - 1]);
}

int arsum(const vector<vector<int>>& arr) { // Перевантажена функція для обчислення суми елементів двовимірного масиву
    int totalsum = 0;
    for (const auto& row : arr) {
        totalsum += arsum(row, row.size());
    }
    return totalsum;
}

int main() {
    int cho;
    cout << "enter 1 for one-dimensional array and 2 for two-dimensional" << endl;
    cin >> cho;

    if (cho == 1) {
        vector<int> arr; 
        int size;
        cout << "size of one-dimensional array" << endl;
        cin >> size;
        cout << "enter values" << endl;
        for (int i = 0; i < size; ++i) {
            int value;
            cin >> value;
            arr.push_back(value);
        }
        cout << "sum: " << arsum(arr, arr.size()) << endl;

    } else if (cho == 2) {
        int size;
        cout << "size of two-dimensional array" << endl;
        cin >> size;
        vector<vector<int>> arr(size, vector<int>(size));
        cout << "enter values" << endl;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cin >> arr[i][j];
            }
        }
        cout << "sum: " << arsum(arr) << endl;
    }

    return 0;
}
