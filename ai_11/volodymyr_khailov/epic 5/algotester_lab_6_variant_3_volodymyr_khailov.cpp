#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void request(const vector<string>& arr, int x, int y) {
    if (arr[x][y] != '0') {
        cout << "1\n" << arr[x][y] << "\n\n";
        return;
    }

    vector<char> possibleDigits(arr.size() + 1, '0');
    for (char i : arr[x]) {
        if (i != '0') {
            possibleDigits[i - '0'] = '1';
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i][y] != '0') {
            possibleDigits[arr[i][y] - '0'] = '1';
        }
    }

    cout << count(possibleDigits.begin(), possibleDigits.end(), '0') - 1 << "\n";
    for (int i = 1; i < possibleDigits.size(); i++) {
        if (possibleDigits[i] == '0') {
            cout << i << " ";
        }
    }
    cout << "\n\n";
}

int main() {
    int n;
    cin >> n;

    vector<string> arr;
    for (int i = 0; i < n; i++) {
        string value;
        cin >> value;
        arr.push_back(value);
    }

    int q;
    cin >> q;
    for (int j = 0; j < q; j++) {
        int x, y;
        cin >> x >> y;
        request(arr, x - 1, y - 1);
    }
    return 0;
}
