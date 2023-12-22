#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }

        current->next = newNode;
    }

    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while (current) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;
    }

    void printList(Node* list) const {
        Node* current = list;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);
    myList.append(5);

    cout << "Original list: ";
    myList.printList(myList.head);

    myList.head = myList.reverse(myList.head);

    cout << "Reversed list: ";
    myList.printList(myList.head);

    return 0;
}