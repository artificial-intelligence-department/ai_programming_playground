#include <iostream>

// Визначення структури Node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Метод реверсу для зв'язаного списку
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;   // Зберігаємо наступний вузол
        current->next = prev;   // Робимо зворотній зв'язок

        // Пересуваємо покажчики для наступної ітерації
        prev = current;
        current = next;
    }

    // Новий початок списку - останній вузол
    head = prev;

    return head;
}

// Допоміжна функція для виведення списку
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Створення зразка списку: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original list: ";
    printList(head);

    // Виклик методу реверсу
    head = reverse(head);

    std::cout << "Reversed list: ";
    printList(head);

    return 0;
}
