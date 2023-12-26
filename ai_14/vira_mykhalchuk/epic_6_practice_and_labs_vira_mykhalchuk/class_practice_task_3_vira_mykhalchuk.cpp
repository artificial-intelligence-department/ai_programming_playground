#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* add(Node* n1, Node* n2) {
    Node* resultHead = nullptr;
    Node* currentResult = nullptr;
    int carry = 0;

    while (n1 || n2 || carry) {
        int sum = (n1 ? n1->data : 0) + (n2 ? n2->data : 0) + carry;
        carry = sum / 10; 
        sum %= 10; 

        Node* newNode = new Node(sum);
        if (!resultHead) {
            resultHead = newNode;
            currentResult = resultHead;
        } else {
            currentResult->next = newNode;
            currentResult = newNode;
        }

        if (n1) n1 = n1->next;
        if (n2) n2 = n2->next;
    }

    return resultHead;
}

void printList(Node* list) {
    while (list) {
        cout << list->data;
        list = list->next;
        if (list) cout << " -> ";
    }
    cout << endl;
}

int main() {
    Node* number1 = new Node(4);
    number1->next = new Node(3);
    number1->next->next = new Node(2);
    number1->next->next->next = new Node(1);

    Node* number2 = new Node(8);
    number2->next = new Node(7);
    number2->next->next = new Node(6);
    number2->next->next->next = new Node(5);

    Node* result = add(number1, number2);

    cout << "Число 1: ";
    printList(number1);

    cout << "Число 2: ";
    printList(number2);

    cout << "Сума: ";
    printList(result);

    while (number1) {
        Node* temp = number1;
        number1 = number1->next;
        delete temp;
    }

    while (number2) {
        Node* temp = number2;
        number2 = number2->next;
        delete temp;
    }

    while (result) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}