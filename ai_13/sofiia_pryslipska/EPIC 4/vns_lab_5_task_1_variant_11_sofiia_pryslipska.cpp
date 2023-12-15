
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSorted(const vector<int>& row, bool ascending) {
    if (ascending) {
        return is_sorted(row.begin(), row.end());
    } else {
        return is_sorted(row.rbegin(), row.rend());
    }
}

void orderRows(vector<vector<int>>& array) {
    for (auto& row : array) {
        if (!isSorted(row, false)) {
            sort(row.begin(), row.end());
        }
    }
}

int main() {
    vector<vector<int>> array = {
        {9, 8, 7},
        {2, 4, 6},
        {12, 10, 11},
        {17, 16, 18},
        {25, 23, 24}
    };

    cout << "Initial array:" << endl; //початокивй масив
    for (const auto& row : array) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    orderRows(array);

    cout << "\n Array after sorting:" << endl;   //Масив після впорядкування
    for (const auto& row : array) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}

