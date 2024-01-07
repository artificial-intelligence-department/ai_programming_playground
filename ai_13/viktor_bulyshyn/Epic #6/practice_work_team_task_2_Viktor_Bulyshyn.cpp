#include <iostream>

// Визначення структури Node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Функція порівняння списків
bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        // Порівняння даних у вузлах
        if (h1->data != h2->data) {
            return false;
        }

        // Перехід до наступних вузлів
        h1 = h1->next;
        h2 = h2->next;
    }

    // Порівняння довжин списків
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
    if (compare(head1, head2)) {
        std::cout << "Lists are equal." << std::endl;
    } else {
        std::cout << "Lists are not equal." << std::endl;
    }

    // Додавання додаткового елементу до другого списку
    head2->next->next->next = new Node(4);

    // Повторне порівняння списків
    if (compare(head1, head2)) {
        std::cout << "Lists are equal." << std::endl;
    } else {
        std::cout << "Lists are not equal." << std::endl;
    }

    return 0;
}
