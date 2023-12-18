#include <iostream>

// Структура для вузла зв'язаного списку
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Функція для реверсу зв'язаного списку
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

    // Після циклу 'prev' вказує на новий початок реверсованого списку
    return prev;
}

// Допоміжна функція для виведення зв'язаного списку на екран
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main()
 {
    int n;
    std::cout << "Enter the amount of numbers in the list: ";
    std::cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    std::cout << "Enter " << n << " numbers for the list:\n";

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;

        if (head == nullptr) {
            head = new Node(num);
            tail = head;
        } else {
            tail->next = new Node(num);
            tail = tail->next;
        }
    }

    std::cout << "First list: ";
    printList(head);

    // Реверс списку
    head = reverse(head);

    std::cout << "Reversed list: ";
    printList(head);

    // Очищення пам'яті
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}