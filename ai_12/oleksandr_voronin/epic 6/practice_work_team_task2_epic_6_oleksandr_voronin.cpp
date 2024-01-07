#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    
};




bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    return (h1 == nullptr && h2 == nullptr);
}


void printLinkedList(Node* n) {
    while (n != nullptr) {
        cout << n->data;
        if (n->next != nullptr) {
            cout << " ";
        }
        n = n->next;
    }
    cout << endl;
}

int main() {
    Node* number1 = new Node();
    number1->data = 4;
    number1->next = new Node();
    number1->next->data = 2;
    number1->next->next = new Node();
    number1->next->next->data = 3;
    number1->next->next->next = nullptr;

    Node* number2 = new Node();
    number2->data = 4;
    number2->next = new Node();
    number2->next->data = 2;
    number2->next->next = new Node();
    number2->next->next->data = 3;
    number2->next->next->next = nullptr;

    cout << "Number 1: ";
    printLinkedList(number1);

    cout << "Number 2: ";
    printLinkedList(number2);

    if (compare(number1, number2)) {
        cout << "Lists are equal.\n";
    } else {
        cout << "Lists are different.\n";
    }

    
    delete number1;
    delete number2;
    

    return 0;
}
