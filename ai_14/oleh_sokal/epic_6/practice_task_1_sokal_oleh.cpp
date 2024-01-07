#include <iostream>
using namespace std;


class Node {
public:
    int value;
    Node* next;


    // Constructor to initialize values
    Node(int val) : value(val), next(nullptr) {}
};


Node* reverse(Node* head) {
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;


    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }


    head = prev;
    return head;
}


void printList(Node* n) {
    if (n == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    while (n != nullptr) {
        cout << n->value << " ";
        n = n->next;
    }
}


int main() {
    // Initialize nodes with values using constructor
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);


    // Link nodes together
    head->next = second;
    second->next = third;
    third->next = nullptr;


    cout << "Original list: ";
    printList(head);
    cout << endl;


    cout << "Reversed list: ";
    head = reverse(head);
    printList(head);
    cout << endl;


    // Clean up memory
    delete head;
    delete second;
    delete third;


    return 0;
}
