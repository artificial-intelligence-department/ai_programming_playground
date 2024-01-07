#include <iostream>
#include <vector>

using namespace std;

void findNumbers(int x, int y, vector<string>& arr, int size, vector<int>& possibleNumbers) {
    char currentNumber = arr[x][y];

    if (currentNumber != '0') {
        cout << "1" << endl << currentNumber << endl << endl;
        return;
    }

    for (int num = 1; num <= size; ++num) {
        bool isValid = true;

        for (int j = 0; j < size; ++j) {
            if (arr[x][j] == num + '0') {
                isValid = false;
                break;
            }
        }

        for (int i = 0; i < size; ++i) {
            if (arr[i][y] == num +'0') {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            possibleNumbers.push_back(num);
        }
    }
    cout << possibleNumbers.size() << endl;
    for (int num : possibleNumbers) {
        cout << num << " ";
    }
    cout << endl << endl;
}

int main() {
    int N;
    cin >> N;
    vector<string> arr;
    for(int i = 0; i < N; i++)
    {
        string line;
        cin>> line;
        arr.push_back(line);
    }

    int Q;
    cin >> Q;
    vector<vector<int>> coordinates(Q, vector<int>(2));
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> coordinates[i][j];
        }
    }

    for (int i = 0; i < Q; i++) {
        int x = coordinates[i][0] - 1, y = coordinates[i][1] - 1;
        vector<int> possibleNumbers;
        findNumbers(x, y, arr, N, possibleNumbers);
    }
    
    return 0;
}