#include <iostream>

// Структура елемента списку
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Функція для додавання чисел, представлених у вигляді списків
Node* add(Node* n1, Node* n2) {
    Node* resultHead = nullptr;
    Node* resultTail = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum = carry;

        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }

        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }

        carry = sum / 10; // Запам'ятовуємо перенос
        sum %= 10; // Запам'ятовуємо поточний розряд

        // Додаємо новий вузол у результат
        Node* newNode = new Node(sum);
        if (resultHead == nullptr) {
            resultHead = resultTail = newNode;
        } else {
            resultTail->next = newNode;
            resultTail = newNode;
        }
    }

    return resultHead;
}

// Допоміжна функція для виведення списку на екран
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data;
        current = current->next;
        if (current != nullptr) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

// Функція для введення числа у список
Node* inputNumberToList() {
    int num;
    std::cout << "Enter the number: ";
    std::cin >> num;

    Node* head = nullptr;
    Node* tail = nullptr;

    // Розділяємо число на цифри та додаємо їх до списку
    while (num > 0) {
        int digit = num % 10;
        Node* newNode = new Node(digit);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }

        num /= 10;
    }

    return head;
}

int main() {
    // Введення чисел у перший та другий список
    Node* num1 = inputNumberToList();
    Node* num2 = inputNumberToList();

    // Виведення чисел на екран
    std::cout << "Number 1: ";
    printList(num1);

    std::cout << "Number 2: ";
    printList(num2);

    // Додавання чисел та виведення результату
    Node* result = add(num1, num2);
    std::cout << "Sum: ";
    printList(result);

    // Очищення пам'яті
    while (num1 != nullptr) {
        Node* temp = num1;
        num1 = num1->next;
        delete temp;
    }

    while (num2 != nullptr) {
        Node* temp = num2;
        num2 = num2->next;
        delete temp;
    }

    while (result != nullptr) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}