#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Допоміжна функція для додавання нового вузла до кінця списку
void append(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функція для додавання двох чисел, представлених у вигляді списків
Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* current = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum = (n1 ? n1->data : 0) + (n2 ? n2->data : 0) + carry;
        carry = sum / 10;
        int digit = sum % 10;

        append(result, digit);

        if (n1) n1 = n1->next;
        if (n2) n2 = n2->next;

        if (current == nullptr) {
            current = result;
        } else {
            current = current->next;
        }
    }

    return result;
}

// Функція для виведення списку
void printList(Node* list) {
    Node* current = list;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* num1 = new Node(2);
    num1->next = new Node(4);
    num1->next->next = new Node(3);

    Node* num2 = new Node(5);
    num2->next = new Node(6);
    num2->next->next = new Node(4);

    cout << "Number 1: ";
    printList(num1);

    cout << "Number 2: ";
    printList(num2);

    Node* sum = add(num1, num2);

    cout << "Sum: ";
    printList(sum);

    // Очистка пам'яті
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
