#include <iostream>
#include <vector>

using namespace std;

void insert(vector<int>& arr, int index, int N, vector<int>& elements) {
    for (int i = 0; i < N; ++i) {
        arr.insert(arr.begin() + index + i, elements[i]);
    }
}

void erase(vector<int>& arr, int index, int n) {
    arr.erase(arr.begin() + index, arr.begin() + index + n);
}

int getSize(const vector<int>& arr) {
    return arr.size();
}

int get(const vector<int>& arr, int index) {
    return arr[index];
}

void set(vector<int>& arr, int index, int newValue) {
    arr[index] = newValue;
}

void print(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int Q;
    cin >> Q;

    vector<int> List;

    for (int i = 0; i < Q; ++i) {
        string input;
        cin >> input;

        if (input == "insert") {
            int index, N;
            cin >> index >> N;
            vector<int> elements(N);
            for (int j = 0; j < N; ++j) {
                cin >> elements[j];
            }
            insert(List, index, N, elements);
        } else if (input == "erase") {
            int index, n;
            cin >> index >> n;
            erase(List, index, n);
        } else if (input == "size") {
            cout << getSize(List) << endl;
        } else if (input == "get") {
            int index;
            cin >> index;
            cout << get(List, index) << endl;
        } else if (input == "set") {
            int index, newValue;
            cin >> index >> newValue;
            set(List, index, newValue);
        } else if (input == "print") {
            print(List);
        }
    }

    return 0;
}
