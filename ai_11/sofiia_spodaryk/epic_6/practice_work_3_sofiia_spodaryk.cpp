#include <iostream>
using namespace std;

// Структура для представлення вузла списку
struct Node {
    int data;     // Дані вузла
    Node* next;   // Вказівник на наступний вузол

    // Конструктор для ініціалізації даних та вказівника на наступний вузол
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Функція додавання великих чисел, представлених у вигляді списків
Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;  // Результат додавання
    Node* current = nullptr; // Вказівник на поточний вузол
    int carry = 0;           // Запам'ятовування переносу

    // Проходимо обидва списки та виконуємо додавання
    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum = (n1 != nullptr ? n1->data : 0) + (n2 != nullptr ? n2->data : 0) + carry;
        carry = sum / 10;  // Отримуємо перенос для наступного розряду
        sum %= 10;         // Отримуємо поточний розряд суми

        // Створюємо новий вузол та ініціалізуємо його даними
        if (result == nullptr) {
            result = new Node(sum);
            current = result;
        } else {
            current->next = new Node(sum);
            current = current->next;
        }

        // Переходимо до наступних вузлів у списку
        if (n1 != nullptr) n1 = n1->next;
        if (n2 != nullptr) n2 = n2->next;
    }

    return result;  // Повертаємо результат додавання
}

// Допоміжна функція для виведення списку на екран
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;  // Виводимо дані поточного вузла
        head = head->next;
        if (head != nullptr) {
            cout << " -> ";  // Виводимо стрілку, якщо є наступний вузол
        }
    }
    cout << endl;
}

int main() {
    // Створення числа 123: 1 -> 2 -> 3
    Node* num1 = new Node(1);
    num1->next = new Node(2);
    num1->next->next = new Node(3);

    // Створення числа 456: 4 -> 5 -> 6
    Node* num2 = new Node(4);
    num2->next = new Node(5);
    num2->next->next = new Node(6);

    // Виведення числа 123
    cout << "Number 1: ";
    printList(num1);

    // Виведення числа 456
    cout << "Number 2: ";
    printList(num2);

    // Додавання чисел
    Node* sum = add(num1, num2);

    // Виведення результату
    cout << "Sum: ";
    printList(sum);

    // Звільнення пам'яті
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

    while (sum != nullptr) {
        Node* temp = sum;
        sum = sum->next;
        delete temp;
    }

    return 0;
}