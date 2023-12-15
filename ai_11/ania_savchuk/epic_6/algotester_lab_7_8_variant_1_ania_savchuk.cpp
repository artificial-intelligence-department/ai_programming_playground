#include <iostream>
using namespace std;

class DoublyLinkedList {
    private:
        struct Node {
            int data;
            Node* next;
            Node* prev;
        };

        Node* head;
        Node* tail;
        int size;
    public:
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr; 
            size = 0;
        }

        void insert(int index, int N, int arr[]) {
            if (index > size) {
                return;
            }

            for (int i = N - 1; i >= 0; i--) {
                Node* tmp = new Node();
                tmp->data = arr[i];
                tmp->prev = nullptr;
                tmp->next = nullptr;

                if (index == 0) {
                    tmp->next = head;
                    if (head != nullptr) {
                        head->prev = tmp;
                    }
                    head = tmp;
                    if (tail == nullptr) {
                        tail = tmp;
                    }
                } else if (index == size) {
                    tmp->prev = tail;
                    if (tail != nullptr) {
                        tail->next = tmp;
                    }
                    tail = tmp;
                    if (head == nullptr) {
                        head = tmp;
                    }
                } else {
                    Node* current = head;
                    for (int j = 0; j < index - 1; j++) {
                        current = current->next;
                    }
                    tmp->next = current->next;
                    tmp->prev = current;
                    if (current->next != nullptr) {
                        current->next->prev = tmp;
                    }
                    current->next = tmp;
                }
                size++;
            }
        }
        void erase(int index, int n) {
            if (index >= size) {
                return;
            }
            Node* current = head;
            while (index--) {
                current = current->next;
            }
            while (n--) {
                if (current->prev == nullptr) {
                    head = current->next;
                } else {
                    current->prev->next = current->next;
                }
                if (current->next == nullptr) {
                    tail = current->prev;
                } else {
                    current->next->prev = current->prev;
                }
                Node* tmp = current;
                current = current->next;
                delete tmp;
                size --;
            }
            
        }
        int get(int index) {
            if (index >= size) {
                return -1;
            }
            Node* current = head;
            while (index--) {
                current = current->next;
            }
            return current->data;
        }
        void set(int index, int val) {
            if (index >= size) {
                return;
            }
            Node* current = head;
            while (index--) {
                current = current->next;
            }
            current->data = val;
        }
        size_t Size() {
            return size;
        }
        friend ostream& operator<<(ostream& os, DoublyLinkedList& list) {
            Node* current = list.head;
            while (current != nullptr) {
                os << current->data << " ";
                current = current->next;
            }
            return os;
        }
};

int main() {
    int Q;
    cin >> Q;
    DoublyLinkedList list;
    while (Q--) {
        string query;
        cin >> query;
        if (query == "insert") {
            int index, N;
            cin >> index >> N;
            int arr[N];
            for (int i = 0; i < N; i++) {
                cin >> arr[i];
            }
            list.insert(index, N, arr);
        } else if (query == "erase") {
            int index, n;
            cin >> index >> n;
            list.erase(index, n);
        } else if (query == "get") {
            int index;
            cin >> index;
            cout << list.get(index) << endl;
        } else if (query == "set") {
            int index, val;
            cin >> index >> val;
            list.set(index, val);
        } else if (query == "size") {
            cout << list.Size() << endl;
        } else if (query == "print") {
            cout << list << endl;
        }
    }
    return 0;
}
