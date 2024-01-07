#include <iostream>

using namespace std;

class Node // Клас для представлення вузла зв'язаного списку
{
public:
    int data; // Значення вузла
    Node* next; // Вказівник на наступний вузол


    Node(int value) : data(value), next(nullptr) {} // Конструктор для ініціалізації значення вузла
};

Node* add(Node* n1, Node* n2) // Функція для додавання двох чисел, представлених у вигляді списків
{
    Node* result = nullptr;
    Node* current = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0) // Проходимо обидва списки та додаємо числа разом з переносом 
    {
        int sum = (n1 ? n1->data : 0) + (n2 ? n2->data : 0) + carry;
        carry = sum / 10;

        Node* newNode = new Node(sum % 10); // Створюємо новий вузол з отриманою сумою

        if (result == nullptr) // Додаємо вузол до результуючого списку
        {
            result = newNode;
            current = result;
        } 
        else 
        {
            current->next = newNode;
            current = current->next;
        }

        if (n1) n1 = n1->next; // Переходимо до наступного вузла в обох вхідних списках
        if (n2) n2 = n2->next;
    }

    return result;
}

void printList(Node* head) // Функція для виведення списку на екран
{
    Node* current = head;
    while (current != nullptr) 
    {
        cout << current->data;
        current = current->next;
        if (current != nullptr) 
        {
            cout << " -> ";
        }
    }
    cout << "\n";
}

int main() 
{
    Node* num1 = new Node(7);
    num1->next = new Node(2);
    num1->next->next = new Node(4);

    Node* num2 = new Node(5);
    num2->next = new Node(6);
    num2->next->next = new Node(4);

    cout << "Число 1\n";
    printList(num1);

    cout << "\nЧисло 2\n";
    printList(num2);

    Node* sum = add(num1, num2);

    cout << "\nСума\n";
    printList(sum);

    while (num1 != nullptr) // Звільнення пам'яті
    {
        Node* temp = num1;
        num1 = num1->next;
        delete temp;
    }

    while (num2 != nullptr) 
    {
        Node* temp = num2;
        num2 = num2->next;
        delete temp;
    }

    while (sum != nullptr) 
    {
        Node* temp = sum;
        sum = sum->next;
        delete temp;
    }

    return 0;
}
