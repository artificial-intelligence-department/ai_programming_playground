#include <iostream>

using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    void insert(int index, int N, T* values) {
    if (index < 0 || index > size) {
        return; // Invalid index
    }

    Node* newNode = nullptr;
    Node* current = nullptr;

    for (int i = 0; i < N; ++i) {
        newNode = new Node(values[i]);

        if (index == 0) {
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;

            if (!tail) {
                tail = newNode; 
            }
        } else if (index == size) {
            newNode->prev = tail;
            if (tail) {
                tail->next = newNode;
            }
            tail = newNode;

            if (!head) {
                head = newNode;
            }
        } else {
            current = head;
            for (int j = 0; j < index - 1; ++j) {
                current = current->next;
            }

            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }

        ++size;
        ++index;
    }
}

    void erase(int index, int n) {
        if (index < 0 || index >= size || n <= 0) {
            return;
        }

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        for (int i = 0; i < n; ++i) {
            Node* toDelete = current;

            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }

            current = current->next;

            delete toDelete;
            --size;
        }
    }

    int getSize() const {
        return size;
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            return T(); 
        }

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        return current->data;
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= size) {
            return; // Invalid index
        }

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        current->data = value;
    }

    void print() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void clear() {
        Node* current = head;
        Node* nextNode = nullptr;

        while (current) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }
};

/*template <typename T>
void printDoublyLinkedList(ostream& os, const DoublyLinkedList<T>& list) {
    list.print();
}*/


int main() {
    int Q;
    cin >> Q;

    DoublyLinkedList<int> list;
    for (int q = 0; q < Q; ++q) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int index, N;
            cin >> index >> N;

            int* values = new int[N];
            for (int i = 0; i < N; ++i) {
                cin >> values[i];
            }

            list.insert(index, N, values);

            delete[] values;
        } else if (operation == "erase") {
            int index, n;
            cin >> index >> n;
            list.erase(index, n);
        } else if (operation == "size") {
            cout << list.getSize() << endl;
        } else if (operation == "get") {
            int index;
            cin >> index;
            cout << list.get(index) << endl;
        } else if (operation == "print") {
            list.print();
        } else if (operation == "set") {
            int index, value;
            cin >> index >> value;
            list.set(index, value);
        }
    }

    return 0;
}
