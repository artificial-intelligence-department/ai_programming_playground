#include <iostream>
#include <unordered_set>
using namespace std;

void readArray(unordered_set<int>& arr) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        arr.insert(element);
    }
}

void compareArrays() {
    unordered_set<int> arr, arr1;
    
    readArray(arr);
    readArray(arr1);

    int similar = 0;
    for (int element : arr) {
        if (arr1.count(element)) {
            similar++;
        }
    }

    int totalUnique = arr.size() + arr1.size() - similar;

    cout << similar << endl << totalUnique << endl;
}

int main() {
    compareArrays();
    return 0;
}
