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

// Функція для виведення списку
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Функція для видалення списку та звільнення пам'яті
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Функція для додавання двох великих чисел, представлених у вигляді списків
Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    int carry = 0;

    // Проходимо обидва списки, додаючи відповідні розряди та перенос
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

        // Визначаємо перенос на наступний розряд та залишок для поточного розряду
        carry = sum / 10;
        sum %= 10;

        // Створюємо новий вузол для результату та вставляємо його в початок
        Node* newNode = new Node(sum, result);
        result = newNode;
    }

    return result;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    cout << "--------- Створіть перший список ---------\n";
    createList(&list1);

    cout << "--------- Створіть другий список ---------\n";
    createList(&list2);

    cout << "Перше число: ";
    printList(list1);

    cout << "Друге число: ";
    printList(list2);

    Node* sumResult = add(list1, list2);

    cout << "Сума: ";
    printList(sumResult);

    // Очищення пам'яті
    deleteList(list1);
    deleteList(list2);
    deleteList(sumResult);

    return 0;
}
