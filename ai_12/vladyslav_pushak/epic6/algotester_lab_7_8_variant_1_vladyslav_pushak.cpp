#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insert(int index, int N, vector<int>& values) {
        for (int i = 0; i < N; ++i) {
            Node* newNode = new Node(values[i]);

            if (size == 0) {
                head = tail = newNode;
            } else if (index == 0) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else if (index >= size) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } else {
                Node* current = head;
                for (int j = 0; j < index; ++j) {
                    current = current->next;
                }
                newNode->prev = current->prev;
                newNode->next = current;
                current->prev->next = newNode;
                current->prev = newNode;
            }

            ++size;
            ++index;
        }
    }

    void erase(int index, int n) {
        while (n > 0 && index < size) {
            Node* current = head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }

            Node* nextNode = current->next;

            if (current->prev) {
                current->prev->next = nextNode;
            } else {
                head = nextNode;
            }

            if (nextNode) {
                nextNode->prev = current->prev;
            } else {
                tail = current->prev;
            }

            delete current;
            --size;
            --n;
        }
    }

    void getSize() const {
        cout << size << endl;
    }

    void get(int index) const {
        if (index >= 0 && index < size) {
            Node* current = head;

            for (int i = 0; i < index; i++) {
                current = current->next;
            }

            cout << current->data << endl;
        } 
    }

    void set(int index, int value) {
        if (index >= 0 && index < size) {
            Node* current = head;

            for (int i = 0; i < index; i++) {
                current = current->next;
            }

            current->data = value;
        } 
    }

    friend ostream& operator<<(ostream& os, const DoublyLinkedList& list) {
        Node* current = list.head;

        while (current) {
            os << current->data << " ";
            current = current->next;
        }

        os << endl;
        return os;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        size = 0;
    }
};

int main() {
    int Q;
    cin >> Q;

    DoublyLinkedList list;

    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
            int index, N;
            cin >> index >> N;

            vector<int> values(N);
            for (int& value : values) {
                cin >> value;
            }

            list.insert(index, N, values);
        } else if (command == "erase") {
            int index, n;
            cin >> index >> n;
            list.erase(index, n);
        } else if (command == "print") {
            cout << list;
        } else if (command == "size") {
            list.getSize();
        } else if (command == "get") {
            int index;
            cin >> index;
            list.get(index);
        } else if (command == "set") {
            int index, value;
            cin >> index >> value;
            list.set(index, value);
        }
    }

    return 0;
}
