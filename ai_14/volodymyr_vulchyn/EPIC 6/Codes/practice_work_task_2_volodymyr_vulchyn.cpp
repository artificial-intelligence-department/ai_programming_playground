#include <iostream>

using namespace std;

// Визначення структури Node для зв'язаного списку
struct Node {
    int data;   // Цілочисельне значення вузла
    Node* next; // Вказівник на наступний вузол у списку

    Node(int val, Node* nextNode = nullptr) : data(val), next(nextNode) {} // Конструктор для створення вузла
};

// Функція для порівняння двох зв'язаних списків
bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) { // Проходимо по обох списках
        if (h1->data != h2->data) {
            return false; // Дані в вузлах не співпадають
        }
        h1 = h1->next; // Переходимо до наступного вузла першого списку
        h2 = h2->next; // Переходимо до наступного вузла другого списку
    }
    return h1 == nullptr && h2 == nullptr; // Повертаємо true, якщо обидва списки закінчились одночасно
}

// Функція для додавання нового вузла в кінець списку
void append(Node** head, int newData) {
    Node* newNode = new Node(newData);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
}

// Функція для введення даних користувачем та створення списку
void createList(Node** head) {
    cout << "Введіть кількість елементів у списку: ";
    int n, value;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Введіть значення елемента " << i + 1 << ": ";
        cin >> value;
        append(head, value);
    }
}

// Основна функція для демонстрації порівняння списків
int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    cout << "--------- Створіть перший список ---------\n";
    createList(&list1);

    cout << "--------- Створіть другий список ---------\n";
    createList(&list2);

    // Порівняння списків
    if (compare(list1, list2)) {
        cout << "Визначені списки є однакові." << endl;
    } else {
        cout << "Визначені списки є різні." << endl;
    }

    // Очищення пам'яті
    while (list1 != nullptr) {
        Node* temp = list1;
        list1 = list1->next;
        delete temp;
    }
    while (list2 != nullptr) {
        Node* temp = list2;
        list2 = list2->next;
        delete temp;
    }

    return 0;
}
