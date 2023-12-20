#include <iostream>

// Визначення структури Node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Функція додавання двох чисел, представлених у вигляді списків
Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;  // Результат додавання
    Node* current = nullptr; // Поточний вузол в результуючому списку
    int carry = 0;           // Перенос для наступного розряду

    // Поки є числа для додавання або є перенос
    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        // Обчислення суми та переносу
        int sum = (n1 ? n1->data : 0) + (n2 ? n2->data : 0) + carry;
        carry = sum / 10;

        // Створення нового вузла для результуючого списку
        Node* newNode = new Node(sum % 10);

        // Додавання вузла до результуючого списку
        if (result == nullptr) {
            result = newNode;
            current = result;
        } else {
            current->next = newNode;
            current = newNode;
        }

        // Перехід до наступних вузлів
        if (n1) n1 = n1->next;
        if (n2) n2 = n2->next;
    }

    return result;
}

// Допоміжна функція для виведення списку
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data;
        head = head->next;
        if (head != nullptr) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Перше число: 1234
    Node* num1 = new Node(4);
    num1->next = new Node(3);
    num1->next->next = new Node(2);
    num1->next->next->next = new Node(1);

    // Друге число: 5678
    Node* num2 = new Node(8);
    num2->next = new Node(7);
    num2->next->next = new Node(6);
    num2->next->next->next = new Node(5);

    // Додавання двох чисел
    Node* sum = add(num1, num2);

    // Виведення результату
    std::cout << "Sum: ";
    printList(sum);

    return 0;
}
