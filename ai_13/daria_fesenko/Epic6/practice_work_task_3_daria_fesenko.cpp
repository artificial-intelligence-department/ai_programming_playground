#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

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

        carry = sum / 10;
        sum %= 10;

        if (result == nullptr) {
            result = new Node(sum);
            current = result;
        } else {
            current->next = new Node(sum);
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
    Node* num1 = new Node(3);
    num1->next = new Node(2);
    num1->next->next = new Node(1);

    Node* num2 = new Node(6);
    num2->next = new Node(5);
    num2->next->next = new Node(4);

    Node* result = add(num1, num2);
    std::cout << "Сума чисел: ";
    printList(result);

    while (num1 != nullptr) {
        Node* temp = num1;
        num1 = num1->next;
        delete temp;
    }

    while (num2 != nullptr) {
        Node* temp = num2;
        num2 = num2->next;
        delete temp;
    }

    while (result != nullptr) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
