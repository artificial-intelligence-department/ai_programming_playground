#include <iostream>
#include <vector>

using namespace std;

class List {
private:
    vector<int> dll;

public:
    void Insert(int index, int size, const vector<int>& values) {
        dll.insert(dll.begin() + index, values.begin(), values.end());
    }

    void Erase(int index, int n) {
        dll.erase(dll.begin() + index, dll.begin() + index + n);
    }

    int Size() const {
        return dll.size();
    }

    int Get(int index) const {
        return dll[index];
    }

    void Set(int index, int value) {
        dll[index] = value;
    }

    friend ostream& operator<<(ostream& peregruz, const List& dll) {
        for (const auto& val : dll.dll) {
            peregruz << val << " ";
        }
        return peregruz;
    }
};

int main() {
    int k;
    cin >> k;

    List dll;

    for (int i = 0; i < k; i++) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int index, size;
            cin >> index >> size;
            vector<int> values(size);
            for (auto& val : values) {
                cin >> val;
            }
            dll.Insert(index, size, values);
        } else if (operation == "erase") {
            int index, n;
            cin >> index >> n;
            dll.Erase(index, n);
        } else if (operation == "size") {
            cout << dll.Size() << endl;
        } else if (operation == "get") {
            int index;
            cin >> index;
            cout << dll.Get(index) << endl;
        } else if (operation == "set") {
            int index, value;
            cin >> index >> value;
            dll.Set(index, value);
        } else if (operation == "print") {
            cout << dll << endl;
        }
    }

    return 0;
}