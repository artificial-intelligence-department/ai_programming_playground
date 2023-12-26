#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
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

    void insert(int index, int count, T* values) {
        if (index < 0 || index > size) {
            return;
        }

        Node<T>* current = getNode(index);
        for (int i = 0; i < count; ++i) {
            Node<T>* newNode = new Node<T>(values[i]);

            if (current == nullptr) {
                if (tail == nullptr) {
                    head = tail = newNode;
                } else {
                    newNode->prev = tail;
                    tail->next = newNode;
                    tail = newNode;
                }
            } else {
                if (current->prev == nullptr) {
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                } else {
                    newNode->prev = current->prev;
                    newNode->next = current;
                    current->prev->next = newNode;
                    current->prev = newNode;
                }
            }

            ++size;
        }
    }

    void erase(int index, int count) {
        if (index < 0 || index >= size || count <= 0) {
            return;
        }

        Node<T>* current = getNode(index);
        Node<T>* end = getNode(index + count - 1);

        if (current != nullptr && end != nullptr) {
            if (current->prev != nullptr) {
                current->prev->next = end->next;
            } else {
                head = end->next;
            }

            if (end->next != nullptr) {
                end->next->prev = current->prev;
            } else {
                tail = current->prev;
            }

            while (current != nullptr && current != end->next) {
                Node<T>* temp = current;
                current = current->next;
                delete temp;
                --size;
            }
        }
    }

    int getSize() const {
        return size;
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            return T();
        }

        Node<T>* current = getNode(index);
        if (current != nullptr) {
            return current->data;
        }

        return T();
    }

    void set(int index, T value) {
        if (index < 0 || index >= size) {
            return;
        }

        Node<T>* current = getNode(index);
        if (current != nullptr) {
            current->data = value;
        }
    }

    void print() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
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
            if (current != nullptr) {
                current = current->next;
            }
        }

        return current;
    }
};

int main() {
    int Q;
    std::cin >> Q;

    DoublyLinkedList<int> dll;

    for (int i = 0; i < Q; ++i) {
        std::string identifier;
        std::cin >> identifier;

        if (identifier == "insert") {
            int index, count;
            std::cin >> index >> count;
            int* values = new int[count];
            for (int j = 0; j < count; ++j) {
                std::cin >> values[j];
            }
            dll.insert(index, count, values);
            delete[] values;
        } else if (identifier == "erase") {
            int index, count;
            std::cin >> index >> count;
            dll.erase(index, count);
        } else if (identifier == "size") {
            std::cout << dll.getSize() << std::endl;
        } else if (identifier == "get") {
            int index;
            std::cin >> index;
            std::cout << dll.get(index) << std::endl;
        } else if (identifier == "set") {
            int index, value;
            std::cin >> index >> value;
            dll.set(index, value);
        } else if (identifier == "print") {
            dll.print();
        }
    }

    return 0;
}
