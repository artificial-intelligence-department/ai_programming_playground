#include <iostream>

// Структура для представлення вузла списку
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

// Функція для реверсу списку
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;   // Зберігаємо наступний вузол
        current->next = prev;   // Змінюємо вказівник на наступний вузол на попередній
        prev = current;         // Переміщаємо покажчик попереднього вузла на поточний
        current = next;         // Переміщаємо покажчик поточного вузла на наступний
    }

    return prev;  // Новий початок списку - коли current стане nullptr, prev буде останнім вузлом, який тепер є початком списку
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
    // Створюємо зразок списку: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Вихідний список: ";
    printList(head);

    // Викликаємо функцію реверсу
    head = reverse(head);

    std::cout << "Обернений список: ";
    printList(head);

    // Очищаємо пам'ять
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
