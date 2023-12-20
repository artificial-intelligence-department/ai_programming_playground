#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void printLinkedList(Node* n) {
    while (n != nullptr) {
        std::cout << n->data;
        if (n->next != nullptr) {
            std::cout << " -> ";
        }
        n = n->next;
    }
    std::cout << std::endl;
}

Node* add(Node* n1, Node* n2) {
    Node* resultHead = nullptr;
    Node* resultTail = nullptr;
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

        Node* newNode = new Node(sum);

        if (resultHead == nullptr) {
            resultHead = newNode;
            resultTail = resultHead;
        } else {
            resultTail->next = newNode;
            resultTail = newNode;
        }
    }

    return resultHead;
}

int main() {
    Node* number1 = new Node(9);
    number1->next = new Node(7);
    number1->next->next = new Node(3);

    Node* number2 = new Node(2);
    number2->next = new Node(8);

    std::cout << "Number 1: ";
    printLinkedList(number1);

    std::cout << "Number 2: ";
    printLinkedList(number2);

    Node* sumResult = add(number1, number2);

    std::cout << "Sum: ";
    printLinkedList(sumResult);

    return 0;
}
