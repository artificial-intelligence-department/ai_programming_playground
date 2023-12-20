#include <iostream>

struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* add(Node *n1, Node *n2) {
    Node *result = nullptr;
    Node *current = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int val1 = (n1 != nullptr) ? n1->data : 0;
        int val2 = (n2 != nullptr) ? n2->data : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        Node *newNode = new Node(sum);
        if (result == nullptr) {
            result = newNode;
            current = result;
        } else {
            current->next = newNode;
            current = newNode;
        }

        if (n1 != nullptr) n1 = n1->next;
        if (n2 != nullptr) n2 = n2->next;
    }

    return result;
}

void printList(Node *head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void deleteList(Node *head) {
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node *num1 = new Node(3);
    num1->next = new Node(7);
    num1->next->next = new Node(9);

    Node *num2 = new Node(4);
    num2->next = new Node(5);
    num2->next->next = new Node(6);

    std::cout << "Перше число: ";
    printList(num1);

    std::cout << "Друге число: ";
    printList(num2);

    Node *sum = add(num1, num2);

    std::cout << "Сума: ";
    printList(sum);

    deleteList(num1);
    deleteList(num2);
    deleteList(sum);

    return 0;
}