#include <iostream>

// Визначення структури Node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Функція для порівняння двох списків
bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        // Порівнюємо дані в кожному вузлі
        if (h1->data != h2->data) {
            return false;
        }

        // Переходимо до наступного вузла в обох списках
        h1 = h1->next;
        h2 = h2->next;
    }

    // Якщо довжина списків різна, то повертаємо false
    return (h1 == nullptr && h2 == nullptr);
}

int main() {
    // Створення першого списку: 1 -> 2 -> 3
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    // Створення другого списку: 1 -> 2 -> 3
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    // Порівняння списків
    bool result = compare(head1, head2);

    // Виведення результату
    if (result) {
        std::cout << "Списки ідентичні." << std::endl;
    } else {
        std::cout << "Списки різні." << std::endl;
    }

    return 0;
}
