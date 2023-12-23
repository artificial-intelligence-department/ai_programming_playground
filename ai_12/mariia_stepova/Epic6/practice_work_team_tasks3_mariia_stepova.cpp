#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* addLists(Node* l1, Node* l2) {
    Node* result = nullptr;
    Node* current = nullptr;
    int carry = 0;

    while (l1 != nullptr  l2 != nullptr  carry != 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        sum = sum % 10;

        Node* newNode = new Node(sum);
        if (result == nullptr) {
            result = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return result;
}

void printList(Node* node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    using namespace std;

    // Приклади чисел
    Node* num1 = new Node(9);
    num1->next = new Node(7);
    num1->next->next = new Node(3);

    Node* num2 = new Node(2);
    num2->next = new Node(5);
    num2->next->next = new Node(4);

    cout << "Число 1: ";
    printList(num1);

    cout << "Число 2: ";
    printList(num2);

    Node* result = addLists(num1, num2);

    cout << "Сума: ";
    printList(result);

    return 0;
}
