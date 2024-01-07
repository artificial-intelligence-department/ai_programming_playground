#include <iostream>

// Структура вузла списку
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Функція порівняння двох списків
bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        // Порівнюємо дані в кожному вузлі
        if (h1->data != h2->data) {
            return false;
        }

        // Переходимо до наступних вузлів
        h1 = h1->next;
        h2 = h2->next;
    }

    // Якщо один зі списків закінчується раніше іншого, то вони не рівні
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

    // Спроба порівняння списків
    if (compare(head1, head2)) {
        std::cout << "Списки рівні." << std::endl;
    } else {
        std::cout << "Списки не рівні." << std::endl;
    }

    // Очистка пам'яті (звільнення вузлів)
    while (head1 != nullptr) {
        Node* temp = head1;
        head1 = head1->next;
        delete temp;
    }

    while (head2 != nullptr) {
        Node* temp = head2;
        head2 = head2->next;
        delete temp;
    }

    return 0;
}
