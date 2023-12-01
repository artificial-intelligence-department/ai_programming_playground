#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* r = new int[n];
    vector<int> numsToDelete(3);

    for (int i = 0; i < n; i++)
        cin >> r[i];

    for (int& numToDelete: numsToDelete)
        cin >> numToDelete;

    vector<int> filteredArray;

    // Iterate over the array r and check if each element is present in numsToDelete.
    for (int i = 0; i < n; i++)
        if (find(numsToDelete.begin(), numsToDelete.end(), r[i])
            == numsToDelete.end())
            filteredArray.push_back(r[i]);

    if (filteredArray.empty()) {
        cout << 0;
        return 0;
    }

    vector<int> arrayOfSums(filteredArray.size() - 1);
    cout << arrayOfSums.size() << "\n";
    if (arrayOfSums.empty()) return 0;

    for (int i = 0; i < arrayOfSums.size(); ++i) {
        arrayOfSums[i] = filteredArray[i] + filteredArray[i + 1];
        cout << arrayOfSums[i] << " ";
    }

    return 0;
}