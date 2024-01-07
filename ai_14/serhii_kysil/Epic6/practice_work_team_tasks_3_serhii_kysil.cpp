#include <iostream>
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* current = nullptr;
    int carry = 0; 
    while (n1 != nullptr || n2 != nullptr) {
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
        sum = sum % 10; 
        Node* newNode = new Node(sum);
        if (result == nullptr) {
            result = newNode;
            current = result;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }
    if (carry > 0) {
        Node* newNode = new Node(carry);
        current->next = newNode;
    }
    return result;
}
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data;
        current = current->next;
    }
    std::cout << std::endl;
}
int main() {
    Node* num1 = new Node(3);
    num1->next = new Node(7);
    num1->next->next = new Node(9);
    Node* num2 = new Node(4);
    num2->next = new Node(2);
    num2->next->next = new Node(5);
    std::cout << "Число 1: ";
    printList(num1);
    std::cout << "Число 2: ";
    printList(num2);
    Node* result = add(num1, num2);
    std::cout << "Сума: ";
    printList(result);
    return 0;
}
