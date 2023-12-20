#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Завдання №1 - Реверс списку
Node* reverse(Node *head) {
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Допоміжна функція для виведення списку
void printList(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Завдання №2 - Порівняння списків
bool compare(Node *h1, Node *h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    // Перевірка, чи довжини списків рівні
    return h1 == nullptr && h2 == nullptr;
}

// Завдання №3 - Додавання великих чисел
Node* add(Node *n1, Node *n2) {
    Node *result = nullptr;
    Node *current = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum = (n1 ? n1->data : 0) + (n2 ? n2->data : 0) + carry;
        carry = sum / 10;
        
        Node *newNode = new Node(sum % 10);
        if (result == nullptr) {
            result = newNode;
            current = result;
        } else {
            current->next = newNode;
            current = newNode;
        }

        if (n1) n1 = n1->next;
        if (n2) n2 = n2->next;
    }

    // Реверс результату перед поверненням
    return reverse(result);
}

int main() {
    // Приклад для завдання №1
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original list: ";
    printList(head);

    Node *reversedHead = reverse(head);

    cout << "Reversed list: ";
    printList(reversedHead);

    // Приклад для завдання №2
    Node *list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);

    Node *list2 = new Node(1);
    list2->next = new Node(2);
    list2->next->next = new Node(4);  // змінено для різниці

    cout << "Lists are equal: " << boolalpha << compare(list1, list2) << endl;

    // Приклад для завдання №3
    Node *num1 = new Node(9);
    num1->next = new Node(7);
    num1->next->next = new Node(3);

    Node *num2 = new Node(2);
    num2->next = new Node(4);
    num2->next->next = new Node(6);

    cout << "Number 1: ";
    printList(num1);

    cout << "Number 2: ";
    printList(num2);

    Node *sum = add(num1, num2);

    cout << "Sum of numbers: ";
    printList(sum);

    return 0;
}
