#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insert(int index, int N, const T* values) {
        if (index < 0 || index > size) {
            return;
        }

        Node<T>* newNode = nullptr;

        for (int i = 0; i < N; ++i) {
            newNode = new Node<T>(values[i]);

            if (head == nullptr) {
                head = tail = newNode;
            } else if (index == 0) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else if (index == size) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } else {
                Node<T>* current = head;
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

        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        while (n > 0 && current != nullptr) {
            Node<T>* nextNode = current->next;

            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }

            delete current;
            current = nextNode;

            --size;
            --n;
        }
    }

    int getSize() const {
        return size;
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            return T();
        }

        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        return current->data;
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= size) {
            return;
        }

        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        current->data = value;
    }

    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& list) {
        Node<T>* current = list.head;
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }
};

int main() {
    int Q;
    std::cin >> Q;

    DoublyLinkedList<int> list;

    for (int i = 0; i < Q; ++i) {
        std::string operation;
        std::cin >> operation;

        if (operation == "insert") {
            int index, N;
            std::cin >> index >> N;
            int* values = new int[N];
            for (int j = 0; j < N; ++j) {
                std::cin >> values[j];
            }
            list.insert(index, N, values);
            delete[] values;
        } else if (operation == "erase") {
            int index, n;
            std::cin >> index >> n;
            list.erase(index, n);
        } else if (operation == "size") {
            std::cout << list.getSize() << std::endl;
        } else if (operation == "get") {
            int index;
            std::cin >> index;
            std::cout << list.get(index) << std::endl;
        } else if (operation == "set") {
            int index, value;
            std::cin >> index >> value;
            list.set(index, value);
        } else if (operation == "print") {
            std::cout << list << std::endl;
        }
    }

    return 0;
}

