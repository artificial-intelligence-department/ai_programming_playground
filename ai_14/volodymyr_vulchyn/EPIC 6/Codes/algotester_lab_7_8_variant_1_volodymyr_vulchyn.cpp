#include <iostream>
#include <list>

using namespace std;

class DoublyLinkedList {
private:
    list<int> dll;

public:
    void insert(int index, int size, const list<int>& values) {
        auto it = dll.begin();
        advance(it, index);
        dll.insert(it, values.begin(), values.end());
    }

    void erase(int index, int n) {
        auto it = dll.begin();
        advance(it, index);
        dll.erase(it, next(it, n));
    }

    int size() const {
        return dll.size();
    }

    int get(int index) const {
        auto it = dll.begin();
        advance(it, index);
        return *it;
    }

    void set(int index, int value) {
        auto it = dll.begin();
        advance(it, index);
        *it = value;
    }

    friend ostream& operator<<(ostream& os, const DoublyLinkedList& dll) {
        for (const auto& val : dll.dll) {
            os << val << " ";
        }
        return os;
    }
};

int main() {
    int Q;
    cin >> Q;

    DoublyLinkedList dll;

    for (int i = 0; i < Q; i++) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int index, size;
            cin >> index >> size;
            list<int> values(size);
            for (auto& val : values) {
                cin >> val;
            }
            dll.insert(index, size, values);
        } else if (operation == "erase") {
            int index, n;
            cin >> index >> n;
            dll.erase(index, n);
        } else if (operation == "size") {
            cout << dll.size() << endl;
        } else if (operation == "get") {
            int index;
            cin >> index;
            cout << dll.get(index) << endl;
        } else if (operation == "set") {
            int index, value;
            cin >> index >> value;
            dll.set(index, value);
        } else if (operation == "print") {
            cout << dll << endl;
        }
    }

    return 0;
}
