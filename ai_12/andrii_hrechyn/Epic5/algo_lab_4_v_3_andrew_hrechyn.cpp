#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int* array = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    vector<vector<int>> masive(3);

    for (int i = 0; i < N; i++) {
        int remainder = array[i] % 3;
        masive[remainder].push_back(array[i]);
    }

    sort(masive[0].begin(), masive[0].end());
    sort(masive[1].begin(), masive[1].end(), greater<int>());
    sort(masive[2].begin(), masive[2].end());

    vector<int> fin_array;

    for (const auto& masive : masive) {
        for (int num : masive) {
            if (find(fin_array.begin(), fin_array.end(), num) == fin_array.end()) {
                fin_array.push_back(num);
            }
        }
    }

    cout << fin_array.size() << endl;

    for (int num : fin_array) {
        cout << num << " ";
    }

    delete[] array;
    return 0;
}
