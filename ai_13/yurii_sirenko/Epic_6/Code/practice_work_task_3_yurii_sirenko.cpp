#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void insert(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* current = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum = carry;

        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }

        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }

        int digit = sum % 10;
        carry = sum / 10;

        if (result == nullptr) {
            result = new Node(digit);
            current = result;
        } else {
            current->next = new Node(digit);
            current = current->next;
        }
    }

    return result;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* num1 = nullptr;
    Node* num2 = nullptr;

    insert(num1, 9);
    insert(num1, 7);
    insert(num1, 3);

    insert(num2, 8);
    insert(num2, 2);
    insert(num2, 4);


    Node* result = add(num1, num2);


    std::cout << "Number 1: ";
    printList(num1);

    std::cout << "Number 2: ";
    printList(num2);

    std::cout << "Sum: ";
    printList(result);

    return 0;
}
