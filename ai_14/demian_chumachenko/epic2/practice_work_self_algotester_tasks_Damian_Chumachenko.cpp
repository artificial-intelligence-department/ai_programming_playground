#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, a;

    cin >> n;

    vector<int> array;
    vector<int> sequences(n, 1);

    for(int i = 0; i < n; i++){
        cin >> a;
        array.push_back(a);
    }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (array[i] > array[j]) {
                    sequences[i] = max(sequences[i], sequences[j] + 1);
                }
            }
        }

    int result = *max_element(sequences.begin(), sequences.end());

    cout << result << endl;
    return 0;
}
