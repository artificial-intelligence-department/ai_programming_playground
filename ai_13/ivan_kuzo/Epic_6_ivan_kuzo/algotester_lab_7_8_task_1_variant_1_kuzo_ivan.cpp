#include <iostream>
using namespace std;

class DoubleLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(const int& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int listSize;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    void insert(int index, int N, const int* Ni) {
    if (index > listSize || index < 0)
        return;

    if (N == 0)
        return;

    if (index == listSize) {
        for (int i = 0; i < N; i++) {
            Node* newNode = new Node(Ni[i]);
            if (tail != nullptr) {
                tail->next = newNode;
                newNode->prev = tail;
            } else {
                head = newNode;
            }
            tail = newNode;
            listSize++;
        }
    } else {
        Node* current = head;

        for (int i = 0; i < index; i++)
            current = current->next;

        Node* prevNode = current->prev;

        for (int i = 0; i < N; i++) {
            Node* newNode = new Node(Ni[i]);
            if (prevNode != nullptr)
                prevNode->next = newNode;
            else
                head = newNode;

            newNode->prev = prevNode;
            newNode->next = current;
            current->prev = newNode;

            prevNode = newNode;
            listSize++;
        }
    }
}

    void erase(int index, int N) {
        Node* current = head;

        for (int i = 0; i < index; i++)
            current = current->next;

        for (int i = 0; i < N && current != nullptr; i++) {
            Node* nextNode = current->next;

            if (current->prev != nullptr)
                current->prev->next = nextNode;
            else
                head = nextNode;

            if (nextNode != nullptr)
                nextNode->prev = current->prev;
            else
                tail = current->prev;

            delete current;
            current = nextNode;
            --listSize;

            if (index + N == listSize) {
                tail = current->prev;
            }
        }
    }

    void size() {
        cout << listSize<<endl;
    }

   void get(int index) {
    if (index < 0 || index >= listSize) {
        cout << "Invalid index"<<endl;
        return;
    }

    Node* current = head;

    for (int i = 0; i < index; i++)
        current = current->next;

    cout << current->data<<endl;
}

    void set(int index, int num) {
        Node* current = head;

        for (int i = 0; i < index; i++)
            current = current->next;

        current->data = num;
    }

    friend ostream& operator<<(ostream& os, const DoubleLinkedList& list) {
        Node* current = list.head;

        while (current != nullptr) {
            os << current->data << " ";
            current = current->next;
        }

        return os;
    }
};

int main() {
    DoubleLinkedList list;
    int q;
    cin >> q;
    string* identifiers = new string[q];

    for (int i = 0; i < q; i++) {
        cin >> identifiers[i];

        if (identifiers[i] == "insert") {
            int index, N;
            cin >> index >> N;

            int* NI = new int[N];
            for (int j = 0; j < N; j++) {
                cin >> NI[j];
            }

            list.insert(index, N, NI);
            delete[] NI;
        } else if (identifiers[i] == "erase") {
            int index, N;
            cin >> index >> N;
            list.erase(index, N);
        } else if (identifiers[i] == "size") {
            list.size();
        } else if (identifiers[i] == "get") {
            int index;
            cin >> index;
            list.get(index);
        } else if (identifiers[i] == "set") {
            int index, num;
            cin >> index >> num;
            list.set(index, num);
        } else {
            cout << list << endl;
        }
    }

    delete[] identifiers;
    return 0;
}