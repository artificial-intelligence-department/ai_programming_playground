#include <iostream>

// Структура елемента списку
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Функція для порівняння двох списків
bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false;  // Знайдена невідповідність
        }

        h1 = h1->next;
        h2 = h2->next;
    }

    // Перевірка, чи обидва списки закінчились одночасно
    return (h1 == nullptr && h2 == nullptr);
}

// Функція для введення чисел у список
Node* inputList() {
    int n;
    std::cout << "Enter the number of elements in the list: ";
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

    return head;
}

int main() {
    // Введення чисел у перший та другий список
    Node* head1 = inputList();
    Node* head2 = inputList();

    // Виведення списків на екран
    std::cout << "List 1: ";
    Node* current1 = head1;
    while (current1 != nullptr) {
        std::cout << current1->data << " ";
        current1 = current1->next;
    }
    std::cout << std::endl;

    std::cout << "List 2: ";
    Node* current2 = head2;
    while (current2 != nullptr) {
        std::cout << current2->data << " ";
        current2 = current2->next;
    }
    std::cout << std::endl;

    // Порівняння списків та виведення результату
    if (compare(head1, head2)) {
        std::cout << "Lists are equal." << std::endl;
    } else {
        std::cout << "Lists are not equal." << std::endl;
    }

    // Очищення пам'яті
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

