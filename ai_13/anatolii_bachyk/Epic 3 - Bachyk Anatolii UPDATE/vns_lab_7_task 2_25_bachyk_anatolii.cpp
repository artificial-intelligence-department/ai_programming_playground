#include <iostream>
#include <vector>

using namespace std;

void process(vector<vector<int>>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            arr.erase(arr.begin() + i);
            i--;  // Зменшуємо ітератор, оскільки видалили рядок
        }
    }
}

void process(vector<int>& numbs) {
    bool foundFirstZero = false;
    size_t start = 0;
    for (size_t i = 0; i < numbs.size(); i++) {
        if (numbs[i] == 0) {
            if (!foundFirstZero) {
                foundFirstZero = true;
                start = i;
            } else {
                size_t end = i;
                numbs.erase(numbs.begin() + start + 1, numbs.begin() + end);
                foundFirstZero = false;
                i = start;  // Починаємо знову з першого нуля
            }
        }
    }
}

int main() {
    vector<vector<int>> arr {{1, 2}, {1, 2}, {1, 3}};
    vector<int> numbs {1, 0, 1, 2, 3, 4, 0, 5};

    process(arr);
    for (size_t i = 0; i < arr.size(); i++) {
        cout << "{";
        for (size_t j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j];
        }
        cout << "}";
    }
    cout << endl;

    process(numbs);
    for (size_t i = 0; i < numbs.size(); i++) {
        cout << numbs[i] << " ";
    }
    cout << endl;

    return 0;
}