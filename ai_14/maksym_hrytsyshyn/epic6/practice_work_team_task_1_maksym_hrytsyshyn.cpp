#include <iostream>
using namespace std;

class Node {    
public: 
    int value;
    Node* next;
};

Node* reverse(Node *head) {
    Node *current = head;
    Node *prev = nullptr, *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

    void printList(Node *n) {
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
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->value = 1;
    head->next = second;

    second->value = 2;
    second->next = third;

    third->value = 3;
    third->next = nullptr;

    cout << "Original list: ";
    printList(head);
    cout << endl;

    cout << "Reversed list: ";
    head = reverse(head);
    printList(head);
    cout << endl;
    return 0;
}