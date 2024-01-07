#include <iostream>
#include <string>

class LinkedList {
private:
    struct Node {
        int value;
        Node* prev;
        Node* next;

        Node(int val, Node* previous = nullptr, Node* nextNode = nullptr) 
            : value(val), prev(previous), next(nextNode) {}
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void insert(int index, int N, int arr[]) {
        if (index > size()) {
            return;
        }

        for (int i = N - 1; i >= 0; --i) {
            Node* newNode = new Node(arr[i]);

            if (index == 0) {
                newNode->next = head;
                if (head) {
                    head->prev = newNode;
                } else {
                    tail = newNode;
                }
                head = newNode;
            } else if (index == size()) {
                newNode->prev = tail;
                if (tail) {
                    tail->next = newNode;
                } else {
                    head = newNode;
                }
                tail = newNode;
            } else {
                Node* current = getNode(index - 1);
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
            }
        }
    }

    void erase(int index, int N) {
        if (index < 0 || N <= 0) {
            return;
        }

        Node* current = getNode(index);

        for (int i = 0; i < N && current; ++i) {
            Node* nextNode = current->next;
            Node* prevNode = current->prev;

            if (prevNode) {
                prevNode->next = nextNode;
            } else {
                head = nextNode;
            }

            if (nextNode) {
                nextNode->prev = prevNode;
            } else {
                tail = prevNode;
            }

            delete current;
            current = nextNode;
        }
    }

    int size() const {
        int size = 0;
        Node* current = head;
        while (current) {
            ++size;
            current = current->next;
        }
        return size;
    }

    void set(int index, int content) {
        Node* current = getNode(index);
        if (current) {
            current->value = content;
        }
    }

    int get(int index) const {
        Node* current = getNode(index);
        return current ? current->value : 0;
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    Node* getNode(int index) const {
        Node* current = head;
        for (int i = 0; i < index && current; ++i) {
            current = current->next;
        }
        return current;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

int main() {
    int Q;
    std::cin >> Q;

    LinkedList list;

    while (Q--) {
        std::string request;
        std::cin >> request;

        if (request == "insert") {
            int index, N;
            std::cin >> index >> N;
            int nums[N];
            for (int i = 0; i < N; ++i) {
                std::cin >> nums[i];
            }
            list.insert(index, N, nums);
        } else if (request == "erase") {
            int index, n;
            std::cin >> index >> n;
            list.erase(index, n);
        } else if (request == "size") {
            std::cout << list.size() << std::endl;
        } else if (request == "set") {
            int index, content;
            std::cin >> index >> content;
            list.set(index, content);
        } else if (request == "get") {
            int index;
            std::cin >> index;
            std::cout << list.get(index) << std::endl;
        } else if (request == "print") {
            list.print();
        }
    }

    return 0;
}