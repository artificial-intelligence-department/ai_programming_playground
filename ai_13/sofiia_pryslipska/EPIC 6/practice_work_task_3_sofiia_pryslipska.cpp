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

        carry = sum / 10; // Отримуємо розряд для переносу
        sum = sum % 10;   // Отримуємо поточний розряд для нового вузла

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
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* num1 = new Node(9);
    num1->next = new Node(7);
    num1->next->next = new Node(3);

    Node* num2 = new Node(6);
    num2->next = new Node(8);
    num2->next->next = new Node(2);

    cout << "number 1: ";
    printList(num1);

    cout << "number 2: ";
    printList(num2);

    Node* sum = add(num1, num2);
    cout << "the sum of numbers: ";
    printList(sum);

    // Очищення пам'яті
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
    while (sum != nullptr) {
        Node* temp = sum;
        sum = sum->next;
        delete temp;
    }

    return 0;
}







