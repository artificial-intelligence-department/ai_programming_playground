#include <iostream>
using namespace std;

struct Node {
    int data; // всі елементи списку є int
    Node* next; // вказівник на наступний елемент

    Node(int value) : data(value), next(nullptr) {} // конструктор data - значення елемента
};

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
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
        } 
        else {
            current->next = new Node(digit);
            current = current->next;
        }
    }
    return result;
}

int main() {
    Node* num1 = new Node(3);
    num1->next = new Node(7);
    num1->next->next = new Node(9);

    Node* num2 = new Node(4);
    num2->next = new Node(2);
    num2->next->next = new Node(8);

    cout << "Number 1: ";
    printList(num1);

    cout << "Number 2: ";
    printList(num2);

    Node* result = add(num1, num2);

    cout << "Sum: ";
    printList(result);

    return 0;
}
