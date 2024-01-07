#include <iostream>
#include <algorithm>  
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Задача 1 - Реверс списку
Node* reverse(Node* head) {
    Node *prev = nullptr, *current = head, *next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Задача 2 - Порівняння списків
bool compare(Node* head1, Node* head2) {
    while (head1 && head2) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return !head1 && !head2;
}

// Задача 3 – Додавання великих чисел
Node* add(Node* num1, Node* num2) {
    Node* result = nullptr;
    Node** tail = &result;

    int carry = 0;

    while (num1 != nullptr || num2 != nullptr || carry != 0) {
        int sum = (num1 ? num1->data : 0) + (num2 ? num2->data : 0) + carry;

        *tail = new Node(sum % 10);
        tail = &((*tail)->next);

        carry = sum / 10;

        if (num1) num1 = num1->next;
        if (num2) num2 = num2->next;
    }

    return result;
}

// Функція для виведення списку
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Функція для виведення списку в зворотньому порядку
void reversedPrintList(Node* head) {
    stack<int> stack;

    while (head) {
        stack.push(head->data);
        head = head->next;
    }

    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }

    cout << endl;
}

// Функція для створення списку з масиву значень
Node* createList(const initializer_list<int>& values) {
    Node* head = nullptr;
    Node** tail = &head;

    for (int value : values) {
        *tail = new Node(value);
        tail = &((*tail)->next);
    }

    return head;
}

int main() {
    // Задача 1 - Реверс списку
    Node* list0 = createList({1, 2, 3, 4, 5});

    cout << "List: ";
    printList(list0);

    list0 = reverse(list0);

    cout << "Reversed list: ";
    printList(list0);

    // Задача 2 - Порівняння списків
    Node* list1 = createList({1, 2, 3});
    Node* list2 = createList({1, 2, 3});

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    bool result = compare(list1, list2);
    if (result) {
        cout << "Lists are equal." << endl;
    } else {
        cout << "Lists are not equal." << endl;
    }

    // Задача 3 – Додавання великих чисел
    Node* num1 = createList({9, 9, 9});
    Node* num2 = createList({7, 1});

    cout << "Number 1: ";
    reversedPrintList(num1);
    cout << "Number 2: ";
    reversedPrintList(num2);
    
    Node* sum = add(num1, num2);

    cout << "Sum: ";
    reversedPrintList(sum);

    return 0;
}
