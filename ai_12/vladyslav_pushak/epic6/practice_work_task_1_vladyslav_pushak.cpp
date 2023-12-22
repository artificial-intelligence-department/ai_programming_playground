#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void add(int val) {
        Node* newNode = new Node(val);

        if (size == 0) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }

        ++size;
    }

    bool compare(LinkedList& list) {
        if (size != list.size) {
            return false;
        }

        Node* current1 = head;
        Node* current2 = list.head;

        while (current1 && current2) {
            if (current1->data != current2->data) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }

        return true;
    }

    void print() {
        Node* current = head;

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        size = 0;
    }
};

int main() {
    LinkedList list1;
    list1.add(1);
    list1.add(2);
    list1.add(3);
    list1.add(4);
    list1.add(5);

    LinkedList list2;
    list2.add(6);
    list2.add(7);
    list2.add(8);
    list2.add(9);
    list2.add(10);

    cout << "List 1: ";
    list1.print();

    cout << "List 2: ";
    list2.print();

    if (list1.compare(list2)) {
        cout << "Lists are identical" << endl;
    } else {
        cout << "Lists are different" << endl;
    }

    return 0;
}
