#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* add(Node* n1, Node* n2) {
    Node* resultHead = nullptr; 
    Node* resultTail = nullptr; 
    int carry = 0;

    while (n1 || n2 || carry) {
        int value1;
        if (n1) {
            value1 = n1->data;
        } else {
            value1 = 0;
        }

        int value2;
        if (n2) {
            value2 = n2->data;
        } else {
            value2 = 0;
        }

        int sum = value1 + value2 + carry;
        int digit = sum % 10; 
        carry = sum / 10;

        if (n1 != nullptr) {
            n1 = n1->next;
        }
        if (n2 != nullptr) {
            n2 = n2->next;
        }

        if (resultHead == nullptr) {
            resultHead = new Node(digit);
            resultTail = resultHead;
        } else {
            resultTail->next = new Node(digit);
            resultTail = resultTail->next;
        }    
    }
    return resultHead;
}

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
            cout << n->data << " ";
            n = n->next;
        }

    }

int main() {
    Node* number1 = new Node(3);
    number1->next = new Node(2);
    number1->next->next = new Node(1);

    Node* number2 = new Node(7);
    number2->next = new Node(8);
    number2->next->next = new Node(9);

    cout << "Number 1: ";
    printList(number1);
    cout << endl;

    cout << "Number 2: ";
    printList(number2);
    cout << endl;

    Node* result1 = add(number1, number2);
    result1 = reverse(result1);

    cout << "Sum: ";
    printList(result1);
    cout << endl;


    return 0;
}
