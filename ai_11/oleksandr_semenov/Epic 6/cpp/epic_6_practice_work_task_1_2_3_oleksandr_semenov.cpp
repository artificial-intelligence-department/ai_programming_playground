#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Task 1 - Реверс списку
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Task 2 - Порівняння списків
bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    // Порівнюємо довжини списків
    return h1 == nullptr && h2 == nullptr;
}

// Функція для додавання двох чисел, представлених у вигляді списків
Node* add(Node* n1, Node* n2, int carry = 0) {
    if (n1 == nullptr && n2 == nullptr && carry == 0) {
        return nullptr;
    }

    int value1 = (n1 != nullptr) ? n1->data : 0;
    int value2 = (n2 != nullptr) ? n2->data : 0;

    int sum = value1 + value2 + carry;
    int digit = sum % 10;
    carry = sum / 10;

    cout << "Add: " << value1 << " + " << value2 << " + " << carry << " = " << sum << " (Digit: " << digit << " Carry: " << carry << ")" << endl;

    Node* result = new Node(digit);
    result->next = add((n1 != nullptr) ? n1->next : nullptr, (n2 != nullptr) ? n2->next : nullptr, carry);

    return result;
}

// Функція для виведення значень у списку
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Функція для звільнення пам'яті, видалення усіх вузлів списку
void freeList(Node* node) {
    while (node != nullptr) {
        Node* temp = node;
        node = node->next;
        delete temp;
    }
}

int main() {
  
    // Task 1 - Реверс списку
    Node* list = new Node(1);
    list->next = new Node(2);
    list->next->next = new Node(3);

    cout << "Вихідний список: ";
    printList(list);

    list = reverse(list);

    cout << "Обернений список: ";
    printList(list);

    // Task 2 - Порівняння списків
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);

    Node* list2 = new Node(1);
    list2->next = new Node(2);
    list2->next->next = new Node(3);

    bool resultCompare = compare(list1, list2);
    cout << "Результат порівняння списків: " << (resultCompare ? "true" : "false") << endl;

    Node* n1 = new Node(3);
    n1->next = new Node(7);
    n1->next->next = new Node(9);

    Node* n2 = new Node(2);
    n2->next = new Node(5);
    n2->next->next = new Node(6);

    // Додавання двох чисел
    Node* result = add(n1, n2);
    // Виведення результату

    cout << "Sum: ";
    result=reverse(result);
    printList(result);

    // Звільнення пам'яті
    freeList(n1);
    freeList(n2);
    freeList(result);
    freeList(list);
    freeList(list1);
    freeList(list2);

    return 0;
}
