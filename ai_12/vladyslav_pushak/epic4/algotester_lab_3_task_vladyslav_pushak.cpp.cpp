#include <iostream>
#include <vector>

using namespace std;

void sortArray(vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int size1, size2;
    cin >> size1;
    vector<int> vec1(size1);
    for (int i = 0; i < size1; ++i) {
        cin >> vec1[i];
    }

    cin >> size2;
    vector<int> vec2(size2);
    for (int i = 0; i < size2; ++i) {
        cin >> vec2[i];
    }
    sortArray(vec1);
    sortArray(vec2);

    int commonElements = 0;
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (vec1[i] == vec2[j]) {
            ++commonElements;
            ++i;
            ++j;
        } else if (vec1[i] < vec2[j]) {
            ++i;
        } else {
            ++j;
        }
    }
    int uniqueElements = size1 + size2 - commonElements;

    cout << commonElements << endl;
    cout << uniqueElements << endl;

    return 0;
}
