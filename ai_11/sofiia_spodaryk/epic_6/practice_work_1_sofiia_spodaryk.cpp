#include <iostream>
using namespace std;

struct Node {
    int data;    // Дані вузла
    Node* next;  // Вказівник на наступний вузол

    // Конструктор для створення нового вузла з заданим значенням
    Node(int a) {
        data = a;
        next = nullptr; // Початково вказівник на наступний вузол - nullptr, тобто немає наступного вузла
    }
};

// Функція для реверсування списку
Node* reverse(Node* head) {
    Node* prev = nullptr;   // Вказівник на попередній вузол, початково - nullptr
    Node* current = head;   // Вказівник на поточний вузол, початково - початок списку
    Node* next = nullptr;    // Вказівник на наступний вузол, початково - nullptr

    // Проходження по списку і зміна вказівників для реверсування
    while (current != nullptr) {
        next = current->next;   // Зберігаємо вказівник на наступний вузол перед зміною
        current->next = prev;   // Змінюємо вказівник на наступний вузол на попередній вузол
        prev = current;         // Переміщаємо вказівник на попередній вузол на поточний
        current = next;         // Переміщаємо вказівник на поточний вузол на наступний
    }

    return prev;  // Повертаємо новий початок списку (раніше кінцевий елемент)
}

// Функція для виведення списку на екран
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";   // Виводимо дані поточного вузла
        head = head->next;           // Переміщаємо вказівник на наступний вузол
    }
    cout << endl;
}

int main() {
    // Створення списку: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Виведення вихідного списку
    cout << "Original List: ";
    printList(head);

    // Реверс списку
    Node* reversedHead = reverse(head);

    // Виведення реверсованого списку
    cout << "Reversed List: ";
    printList(reversedHead);

    // Звільнення пам'яті, щоб уникнути витоку пам'яті
    while (reversedHead != nullptr) {
        Node* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;  // Звільняємо пам'ять для кожного вузла
    }

    return 0;
}