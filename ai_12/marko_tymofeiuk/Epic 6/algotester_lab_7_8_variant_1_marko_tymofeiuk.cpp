#include <iostream>

template <class myType>
class Node {
public:
    myType parameter;
    Node* previous;
    Node* next;

    Node() : parameter(0), previous(nullptr), next(nullptr) {}
    Node(myType n, Node* prev) : parameter(n), previous(prev), next(nullptr) {}
};

template <class myType>
class List {
private:
    Node<myType>* head;

public:
    List() : head(nullptr) {}

    void insert() {
        size_t index, N;
        myType parameter;

        std::cin >> index >> N;

        Node<myType>* current = head;
        Node<myType>* prev = nullptr;

        for (size_t i = 0; i < index; i++) {
            prev = current;
            current = current->next;
        }

        for (size_t i = 0; i < N; i++) {
            std::cin >> parameter;
            Node<myType>* newNode = new Node<myType>(parameter, prev);
            if (prev) {
                prev->next = newNode;
            } else {
                head = newNode;
            }
            prev = newNode;
        }

        if (current) {
            prev->next = current;
            current->previous = prev;
        }
    }

    void erase() {
        size_t index, n;

        std::cin >> index >> n;

        Node<myType>* prev = nullptr;
        Node<myType>* current = head;
        Node<myType>* randomptr;

        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        prev = current->previous;

        for (size_t i = 0; i < n; i++) {
            randomptr = current->next;
            delete current;
            current = randomptr;
        }

        if (prev) {
            prev->next = current;
        } else {
            head = current;
        }
        if (current) {
            current->previous = prev;
        }
    }

    myType get() const {
        size_t index;
        std::cin >> index;

        Node<myType>* randomptr = head;

        for (size_t i = 0; i < index; i++) {
            randomptr = randomptr->next;
        }

        return randomptr->parameter;
    }

    void set() {
        size_t index;
        myType parameter;
        std::cin >> index >> parameter;

        Node<myType>* randomptr = head;

        for (size_t i = 0; i < index; i++) {
            randomptr = randomptr->next;
        }

        randomptr->parameter = parameter;
    }

    size_t size() const {
    size_t length = 0;
    Node<myType>* randomptr = head;

    for (size_t i = 0; randomptr != nullptr; i++) {
        randomptr = randomptr->next;
        ++length;
    }

    return length;
    }

void print() const {
    Node<myType>* randomptr = head;

    for (size_t i = 0; randomptr != nullptr; i++) {
        std::cout << randomptr->parameter << " ";
        randomptr = randomptr->next;
    }
    std::cout << std::endl;
}
};

int main() {
    List<size_t> selfcont;
    size_t q;
    std::string input;

    std::cin >> q;

    for (size_t i = 0; i < q ; i++) {
        std::cin >> input;

        if (input == "insert") {
            selfcont.insert();
        } else if (input == "erase") {
            selfcont.erase();
        } else if (input == "size") {
            std::cout << selfcont.size() << std::endl;
        } else if (input == "get") {
            std::cout << selfcont.get() << std::endl;
        } else if (input == "set") {
            selfcont.set();
        } else if (input == "print") {
            selfcont.print();
        }
    }

    return 0;
}
