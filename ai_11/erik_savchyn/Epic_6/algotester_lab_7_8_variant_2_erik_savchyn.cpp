#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class dynamic_list {
private:
    Node<T>* head;
    int length;
    int capacity;

public:
    dynamic_list() : head(nullptr), length(0), capacity(1) {}

    ~dynamic_list() {
        Node<T>* current = head;
        Node<T>* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void get(int index) {
        if (index < 0 || index >= length) {
            return;
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            cout << current->data << endl;
        }
    }

    void size() {
        cout << length << endl;
    }

    void get_capacity() {
        cout << capacity << endl;
    }

    void set(int index, T number) {
        if (index < 0 || index >= length) {
            exit(0);
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->data = number;
        }
    }

    void insert(int index, T* numbers, int size_of_array) {
        if (index < 0) {
            exit(0);
        }

        while (length + size_of_array >= capacity) {
            capacity *= 2;
        }

        if (index == 0) {
            for (int i = size_of_array - 1; i >= 0; i--) {
                Node<T>* newNode = new Node<T>(numbers[i]);
                newNode->next = head;
                head = newNode;
            }
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }

            for (int i = size_of_array - 1; i >= 0; i--) {
                Node<T>* newNode = new Node<T>(numbers[i]);
                newNode->next = current->next;
                current->next = newNode;
            }
        }

        length += size_of_array;
    }

    void erase(int index, int number) {
        if (index < 0 || index >= length || number < 0) {
            exit(0);
        }

        if (index == 0) {
            for (int i = 0; i < number && head != nullptr; i++) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }

            Node<T>* temp = current->next;
            for (int i = 0; i < number && temp != nullptr; i++) {
                current->next = temp->next;
                delete temp;
                temp = current->next;
            }
        }

        length -= number;
    }

    void print() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    string operat;

    dynamic_list<int> linkedList;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> operat;

        if (operat == "insert") {
            int index;
            int size_of_array;
            cin >> index >> size_of_array;
            int* numbers = new int[size_of_array];
            for (int i = 0; i < size_of_array; i++) {
                cin >> numbers[i];
            }
            linkedList.insert(index, numbers, size_of_array);
            delete[] numbers;
        } else if (operat == "get") {
            int index;
            cin >> index;
            linkedList.get(index);
        } else if (operat == "size") {
            linkedList.size();
        } else if (operat == "set") {
            int index;
            int number;
            cin >> index >> number;
            linkedList.set(index, number);
        } else if (operat == "erase") {
            int index;
            int amount_of_elements;
            cin >> index >> amount_of_elements;
            linkedList.erase(index, amount_of_elements);
        } else if (operat == "print") {
            linkedList.print();
        } else if (operat == "capacity") {
            linkedList.get_capacity();
        }
    }

    return 0;
}
