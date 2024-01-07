#include <iostream>
#include <string>
using namespace std;

struct Node {
    int element;
    Node* next;
    Node* prev;
};
class List {
    public:
    int size;
    Node* head;
    Node* tail;
    List() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void clear() {
        Node *temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
        size=0;
    }
    Node* getNode(int index) {
        if (index < 0 || index >= size)
            return NULL;
        Node *m = head;
        for (int i = 0; i < index; ++i) {
            m = m->next;
        }
        return m;
    }
    void insert(int index, int value) {
        if (index < 0 || index > size)
            return;
        Node *elm = getNode(index - 1);
        Node *ins = new Node;
        ins->element = value;
        ins->prev = NULL;
        ins->next = NULL;

        if (elm == NULL) {
            ins->next = head;
            if (head != NULL) {
                head->prev = ins;
            }
            head = ins;
            if (tail == NULL) {
                tail = ins;
            }
        } else {
            ins->next = elm->next;
            ins->prev = elm;
            if (elm->next != NULL) {
                elm->next->prev = ins;
            } else {
                tail = ins;
            }

            elm->next = ins;
        }
        size++;
    }
    void erase(int index) {
        if (index < 0 || index >= size)
            return;

        Node *elm = getNode(index);
        if (elm == NULL) {
            return;
        }
        if (elm->prev != NULL) {
            elm->prev->next = elm->next;
        } else {
            head = elm->next;
            if (head != NULL) {
                head->prev = NULL;
            }
        }
        if (elm->next != NULL) {
            elm->next->prev = elm->prev;
        } else {
            tail = elm->prev;
            if (tail != NULL) {
                tail->next = NULL;
            }
        }
        delete elm;
        size--;
    }

    void print(ostream &s) {
        Node *m = head;
        while (m != NULL) {
            s << m->element << ' ';
            m = m->next;
        }
    }

    int Size() {
        return size;
    }
};

int main() {
    List list;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;
        switch (command[0]) {
            case 'i': {
                int index, N;
                cin >> index >> N;
                for (int j = 0; j < N; j++) {
                    int element;
                    cin >> element;
                    list.insert(index + j, element);
                }
                break;
            }
            case 'p': {
                list.print(cout);
                cout << endl;
                break;
            }
            case 'e': {
                int in, n;
                cin >> in >> n;
                for (int j = 0; j < n; j++) {
                    list.erase(in);
                }
                break;
            }
            case 's': {
                if (command[1] == 'e') {
                    int ind, value;
                    cin >> ind >> value;
                    list.erase(ind);
                    list.insert(ind, value);
                } else {
                    cout << list.Size() << endl;
                }
                break;
            }
            case 'g': {
                int Index;
                cin >> Index;
                Node* m = list.getNode(Index);
                if (m != NULL) {
                    cout << m->element << endl;
                } else {
                    cout << "Element not found" << endl;
                }
                break;
            }
        }
    }
    list.clear();
    return 0;
}