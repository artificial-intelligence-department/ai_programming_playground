#include <iostream>
#include <vector>

template <typename T>
class DoublyLinkedList {
private:
    class Node {
    public:
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

    void insert(int index, int N, const T* values) {
        if (index < 0 || index > size) {
            return;
        }

        Node* newNode = nullptr;
        Node* current = nullptr;

        for (int i = 0; i < N; ++i) {
            newNode = new Node(values[i]);

            if (head == nullptr) {
                head = newNode;
                tail = head;
            } else if (index == 0) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else if (index == size) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
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

        while (n > 0 && current != nullptr) {
            Node* nextNode = current->next;

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
            --size;
            --n;
            current = nextNode;
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
            return;
        }

        Node* current = head;

        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        current->data = value;
    }

    void print() const {
        Node* current = head;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    int Q;
    std::cin >> Q;

    DoublyLinkedList<int> list;

    for (int i = 0; i < Q; ++i) {
        std::string identifier;
        std::cin >> identifier;

        if (identifier == "insert") {
            int index, N;
            std::cin >> index >> N;
            std::vector<int> values(N);
            for (int j = 0; j < N; ++j) {
                std::cin >> values[j];
            }
            list.insert(index, N, values.data());
        } else if (identifier == "erase") {
            int index, n;
            std::cin >> index >> n;
            list.erase(index, n);
        } else if (identifier == "size") {
            std::cout << list.getSize() << std::endl;
        } else if (identifier == "get") {
            int index;
            std::cin >> index;
            std::cout << list.get(index) << std::endl;
        } else if (identifier == "set") {
            int index, value;
            std::cin >> index >> value;
            list.set(index, value);
        } else if (identifier == "print") {
            list.print();
        }
    }

    return 0;
}
