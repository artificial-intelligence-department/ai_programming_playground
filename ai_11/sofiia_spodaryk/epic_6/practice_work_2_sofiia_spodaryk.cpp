#include <iostream>
using namespace std;

// Структура для представлення вузла списку
struct Node {
    int data;    // Дані вузла
    Node* next;  // Вказівник на наступний вузол

    // Конструктор для ініціалізації вузла
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Функція порівняння двох списків
bool compare(Node* h1, Node* h2) {
    // Пройдемось по обох списках, порівняючи значення в кожному вузлі
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false;  // Якщо значення не рівні, списки не однакові
        }
        h1 = h1->next;  // Переходимо до наступного вузла
        h2 = h2->next;
    }

    // Якщо один список закінчується раніше іншого, порівнюємо їх довжини
    return h1 == nullptr && h2 == nullptr;
}

// Допоміжна функція для виведення списку на екран
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";  // Виводимо значення вузла
        head = head->next;          // Переходимо до наступного вузла
    }
    cout << endl;
}

int main() {
    // Створення списку 1: 1 -> 2 -> 3
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);

    // Створення списку 2: 1 -> 2 -> 3
    Node* list2 = new Node(1);
    list2->next = new Node(2);
    list2->next->next = new Node(3);

    // Виведення списку 1
    cout << "List 1: ";
    printList(list1);

    // Виведення списку 2
    cout << "List 2: ";
    printList(list2);

    // Порівняння списків
    bool result = compare(list1, list2);

    // Виведення результату
    cout << "Lists are " << (result ? "equal" : "not equal") << endl;

    // Звільнення пам'яті
    while (list1 != nullptr) {
        Node* temp = list1;
        list1 = list1->next;
        delete temp;  // Звільнення пам'яті кожного вузла
    }

    while (list2 != nullptr) {
        Node* temp = list2;
        list2 = list2->next;
        delete temp;
    }

    return 0;
}