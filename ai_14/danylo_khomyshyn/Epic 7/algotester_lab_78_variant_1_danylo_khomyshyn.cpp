#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
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

    void insert(int index, int listSize, T* elements) {
        if (index < 0 || index > size) {
            return;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;

        for (int i = 0; i < index; ++i) {
            previous = current;
            current = current->next;
        }

        for (int i = 0; i < listSize; ++i) {
            Node<T>* newNode = new Node<T>(elements[i]);

            if (!previous) {
                head = newNode;
            } else {
                previous->next = newNode;
                newNode->prev = previous;
            }

            newNode->next = current;
            if (current) {
                current->prev = newNode;
            } else {
                tail = newNode;
            }

            previous = newNode;
            ++size;
        }
    }

    void erase(int index, int count) {
        if (index < 0 || index >= size || count <= 0) {
            return;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;

        for (int i = 0; i < index; ++i) {
            previous = current;
            current = current->next;
        }

        for (int i = 0; i < count && current; ++i) {
            Node<T>* nextNode = current->next;

            if (previous) {
                previous->next = nextNode;
            } else {
                head = nextNode;
            }

            if (nextNode) {
                nextNode->prev = previous;
            } else {
                tail = previous;
            }

            delete current;
            current = nextNode;
            --size;
        }
    }

    void print() const {
        Node<T>* current = head;

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void setSize() const {
        cout << size << endl;
    }

    T getElement(int index) const {
        if (index < 0 || index >= size) {
            return T();
        }

        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        return current->data;
    }

    void setElement(int index, T value) {
        if (index < 0 || index >= size) {
            return;
        }

        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        current->data = value;
    }

    void clear() {
        Node<T>* current = head;
        Node<T>* next;

        while (current) {
            next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }
};

int main() {
    int Q;
    cin >> Q;

    DoublyLinkedList<int> list;

    while (Q--) {
        string command;
        cin >> command;

        if (command == "insert") {
            int index, listSize;
            cin >> index >> listSize;

            int* elements = new int[listSize];
            for (int i = 0; i < listSize; ++i) {
                cin >> elements[i];
            }

            list.insert(index, listSize, elements);

            delete[] elements;
        } else if (command == "erase") {
            int index, count;
            cin >> index >> count;

            list.erase(index, count);
        } else if (command == "print") {
            list.print();
        } else if (command == "size") {
            list.setSize();
        } else if (command == "get") {
            int index;
            cin >> index;

            cout << list.getElement(index) << endl;
        } else if (command == "set") {
            int index, value;
            cin >> index >> value;

            list.setElement(index, value);
        }
    }

    return 0;
}
