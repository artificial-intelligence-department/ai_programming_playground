#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* add(Node* n1, Node* n2) {
    Node* current = nullptr;
    Node* result = nullptr;
    int carry = 0;   // Перенос в старший розряд

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
        if (result == nullptr) {
            result = newNode;
            current = result;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return result;
}

void printReversedNum(Node* num) {
    if (num == nullptr) {
        return;
    }

    printReversedNum(num->next);
    cout << num->data;
}

int main() {
    Node* num1 = new Node(7);
    num1->next = new Node(8);
    num1->next->next = new Node(2);

    Node* num2 = new Node(5);
    num2->next = new Node(1);
    num2->next->next = new Node(6);

    Node* result = add(num1, num2);

    cout << "Number 1: ";
    printReversedNum(num1);
    cout << endl;

    cout << "Number 2: ";
    printReversedNum(num2);
    cout << endl;

    cout << "The sum is: ";
    printReversedNum(result);
    cout << endl;

    return 0;
}
