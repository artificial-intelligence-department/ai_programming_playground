#include <iostream>
using namespace std;
// Структура вузла списку
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Функція додавання великих чисел, представлених у вигляді списків
Node* add(Node* n1, Node* n2) {
    Node* result = nullptr; // Результат додавання
    Node* current = nullptr; // Поточний вузол в результаті

    int carry = 0; // Запам'ятовування переносу

    // Ітеративний обхід списків
    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        // Сума і перенос
        int sum = (n1 ? n1->data : 0) + (n2 ? n2->data : 0) + carry;
        carry = sum / 10;

        // Створення нового вузла для результату
        Node* newNode = new Node(sum % 10);

        // Додавання вузла до результату
        if (result == nullptr) {
            result = newNode;
            current = result;
        } else {
            current->next = newNode;
            current = newNode;
        }

        // Перехід до наступного вузла в обох списках
        if (n1) n1 = n1->next;
        if (n2) n2 = n2->next;
    }

    return result;
}

// Функція для виведення списку
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Створення чисел (представлених у вигляді списків)
    Node* num1 = new Node(9);
    num1->next = new Node(7);
    num1->next->next = new Node(3);

    Node* num2 = new Node(5);
    num2->next = new Node(8);
    num2->next->next = new Node(2);

    // Виведення вихідних чисел
    cout << "Число 1: ";
    printList(num1);

    cout << "Число 2: ";
    printList(num2);

    // Додавання чисел
    Node* sumResult = add(num1, num2);

    // Виведення результату додавання
    cout << "Сума: ";
    printList(sumResult);

    // Звільнення пам'яті
    delete num1;
    delete num2;
    delete sumResult;

    return 0;
}
