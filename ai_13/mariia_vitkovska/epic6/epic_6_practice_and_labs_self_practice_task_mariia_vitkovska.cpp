#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    void insert(int index, const T* values, int N) {
        if (index < 0 || index > size) {
            return;
        }

        Node<T>* current = getNode(index - 1);

        for (int i = 0; i < N; ++i) {
            Node<T>* newNode = new Node<T>(values[i]);

            if (current == nullptr) {
                newNode->next = head;
                if (head != nullptr) {
                    head->prev = newNode;
                }
                head = newNode;
                if (tail == nullptr) {
                    tail = newNode;
                }
            } else {
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next != nullptr) {
                    current->next->prev = newNode;
                } else {
                    tail = newNode;
                }
                current->next = newNode;
            }

            ++size;
            current = newNode;
        }
    }

    void erase(int index, int n) {
        if (index < 0 || index >= size || n <= 0) {
            return;
        }

        Node<T>* current = getNode(index);

        for (int i = 0; i < n && current != nullptr; ++i) {
            Node<T>* temp = current;
            current = current->next;

            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            }

            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            } else {
                tail = temp->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
            }

            delete temp;
            --size;
        }
    }

    int Size() const {
        return size;
    }

    T get(int index) const {
        Node<T>* node = getNode(index);
        if (node != nullptr) {
            return node->data;
        } else {
            // Return a default value or handle the error as needed
            return T();
        }
    }

    void set(int index, const T& value) {
        Node<T>* node = getNode(index);
        if (node != nullptr) {
            node->data = value;
        }
    }

    void print(ostream& os) const {
        Node<T>* current = head;
        while (current != nullptr) {
            os << current->data << ' ';
            current = current->next;
        }
    }

    void clear() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
    }

private:
    Node<T>* getNode(int index) const {
        if (index < 0 || index >= size) {
            return nullptr;
        }

        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        return current;
    }
};

// Overload the << operator for easy printing
template <typename T>
ostream& operator<<(ostream& os, const DoublyLinkedList<T>& list) {
    list.print(os);
    return os;
}

int main() {
    DoublyLinkedList<int> list;

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        string command;
        cin >> command;

        if (command == "insert") {
            int index, N;
            cin >> index >> N;

            int* values = new int[N];
            for (int j = 0; j < N; ++j) {
                cin >> values[j];
            }

            list.insert(index, values, N);
            delete[] values;
        } else if (command == "erase") {
            int index, n;
            cin >> index >> n;
            list.erase(index, n);
        } else if (command == "size") {
            cout << list.Size() << endl;
        } else if (command == "get") {
            int index;
            cin >> index;
            cout << list.get(index) << endl;
        } else if (command == "set") {
            int index, value;
            cin >> index >> value;
            list.set(index, value);
        } else if (command == "print") {
            list.print(cout);
            cout << endl;
        }
    }

    list.clear();

    return 0;
}
