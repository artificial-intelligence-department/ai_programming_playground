#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input;
    cout << "Enter the string: ";
    getline(cin, input);  // Змінено на getline для зчитування всього рядка

    int length = input.length();
    int N;

    for (N = 1; N * N <= length; ++N) {
        if (length % N == 0) {
            break;
        }
    }

    if (N * N > length) {
        cout << "Error bad string" << endl;
        return 0;
    }

    vector<vector<char>> result(N, vector<char>(N, '0'));

    sort(input.begin(), input.end());

    int index = 0;
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            result[row][col] = input[index++];
        }
    }

   for (int row = 0; row < N; ++row) {
    for (int col = 0; col < N; ++col) {
        cout << result[row][col] - '0' << " ";
    }
    cout << endl;
    }

    return 0;
}