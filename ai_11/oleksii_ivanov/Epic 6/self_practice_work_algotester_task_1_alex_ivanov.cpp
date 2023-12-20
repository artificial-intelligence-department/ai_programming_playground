#include <iostream>
#include <functional>

// Algotester Lab 7-8 V1
// Doubly linked list

// TODO - make this an iterable collection
template<class T>
class DoublyLinkedList {
protected:
    struct Node {
    public:
        T value;
        Node* next;
        Node* prev;

        Node() : next(nullptr), prev(nullptr) {}

        Node(T value, Node* next, Node* prev)
            : value(value), next(next), prev(prev) {}

        explicit Node(T value)
            : Node(value, nullptr, nullptr) {}
    };

    Node* get_node(const int index) {
        check_index(index);

        const int mid = _size / 2;
        Node* node;

        if (index <= mid) {
            node = head;
            for (int i = 0; i < index; ++i) {
                node = node->next;
            }
        } else {
            node = tail;
            for (int i = _size - 1; i > index; --i) {
                node = node->prev;
            }
        }

        return node;
    }

    void check_index(const int index) const {
        if (index < 0 || index > _size) {
            throw std::out_of_range("Index out of range");
        }
    }

    void create_head(T value) {
        head = tail = new Node(value);
        _size = 1;
    }

private:
    Node* head;
    Node* tail;
    int _size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), _size(0) {}
    DoublyLinkedList(std::initializer_list<T> list)
        : DoublyLinkedList() {
        for (auto& value : list) {
            push_back(value);
        }
    }

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
        _size = 0;
    }

    // Nodiscard is used to warn the user if the return value is ignored
    // (Function is useless if we just call it)
    [[nodiscard]] int size() const {
        return _size;
    }

    [[nodiscard]] bool empty() const {
        return _size == 0;
    }

    int index_of(T& element) {
        Node* node = head;
        int index = 0;
        while (node != nullptr) {
            if (node->value == element) {
                return index;
            }
            node = node->next;
            index++;
        }
        return -1;
    }

    void push_front(T value) {
        if (head == nullptr) {
            create_head(value);
            return;
        }

        Node* node = new Node(value, head, nullptr);
        head->prev = node;
        head = node;
        _size++;
    }

    void push_back(T value) {
        if (head == nullptr) {
            create_head(value);
            return;
        }

        Node* node = new Node(value, nullptr, tail);
        tail->next = node;
        tail = node;
        _size++;
    }

    void insert(T value, const int index) {
        check_index(index);

        if (index == 0) {
            push_front(value);
            return;
        }

        if (index == _size) {
            push_back(value);
            return;
        }

        Node* node = get_node(index);
        Node* new_node = new Node(value, node, node->prev);
        node->prev->next = new_node;
        node->prev = new_node;
        _size++;
    }

    void pop_front() {
        if (head == nullptr) return;

        const Node* node = head;
        head = head->next;
        delete node;
        _size--;

        if (head == nullptr) tail = nullptr;
        else head->prev = nullptr;
    }

    void pop_back() {
        if (tail == nullptr) return;

        const Node* node = tail;
        tail = tail->prev;
        delete node;
        _size--;

        if (tail == nullptr) head = nullptr;
        else tail->next = nullptr;
    }

    void erase(const int index) {
        check_index(index);

        if (index == 0) {
            pop_front();
            return;
        }

        if (index == _size - 1) {
            pop_back();
            return;
        }

        Node* node = get_node(index);
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        _size--;
    }

    void remove(T& element) {
        erase(index_of(element));
    }

    void forEach(std::function<void(T&)> callback) {
        Node* node = head;
        while (node != nullptr) {
            callback(node->value);
            node = node->next;
        }
    }

    T& operator[](const int index) {
        return get_node(index)->value;
    }
};

template<class T>
std::ostream& operator<<(std::ostream& os, DoublyLinkedList<T>& list) {
    list.forEach([&os](T& value) {
        os << value << " ";
    });
    return os;
}

int main() {
    using namespace std;
    DoublyLinkedList<int> list;

    int queries;
    string query;
    cin >> queries;

    for (int i = 0; i < queries; ++i) {
        cin >> query;

        try {
            if (query == "insert") {
                int index, count;
                cin >> index >> count;

                DoublyLinkedList<int> values;
                for (int j = 0; j < count; ++j) {
                    int value;
                    cin >> value;
                    values.push_back(value);
                }

                for (int j = count - 1; j >= 0; --j)
                    list.insert(values[j], index);
            } else if (query == "erase") {
                int index, count;
                cin >> index >> count;

                for (int j = 0; j < count; ++j)
                    list.erase(index);
            } else if (query == "size") {
                cout << list.size() << endl;
            } else if (query == "get") {
                int index;
                cin >> index;
                cout << list[index] << endl;
            } else if (query == "set") {
                int index, value;
                cin >> index >> value;
                list[index] = value;
            } else if (query == "print") {
                cout << list << endl;
            }
        }
        catch (out_of_range&) {}
        catch (exception&) {}
    }

    return 0;
}
