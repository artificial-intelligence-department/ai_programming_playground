#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* add(Node* n1, Node* n2) {
    Node* result = nullptr; 
    Node* current = nullptr;  

    int carry = 0;  

    while (n1 != nullptr || n2 != nullptr) {
        int num1 = (n1 != nullptr) ? n1->data : 0;
        int num2 = (n2 != nullptr) ? n2->data : 0;

        int sum = num1 + num2 + carry;

        carry = sum / 10;
        int value = sum % 10;

        Node* newNode = new Node(value);

        if (result == nullptr) {
            result = newNode;
            current = newNode;
        }
        else {
            current->next = newNode;
            current = newNode;
        }

        if (n1 != nullptr) n1 = n1->next;
        if (n2 != nullptr) n2 = n2->next;
    }

    if (carry > 0) {
        Node* newNode = new Node(carry);
        current->next = newNode;
    }

    return result;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* num1 = new Node(3);
    num1->next = new Node(7);
    num1->next->next = new Node(9);

    Node* num2 = new Node(4);
    num2->next = new Node(5);
    num2->next->next = new Node(6);

    Node* result = add(num1, num2);
    cout << "result dodavania: ";
    printList(result);

    delete result;
    delete num1;
    delete num2;
    return 0;
}
