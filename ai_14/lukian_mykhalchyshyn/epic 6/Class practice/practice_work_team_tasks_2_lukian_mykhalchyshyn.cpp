#include <iostream>

using namespace std;

class Node // Клас для представлення вузла списку
{
public:
    int data; // Значення вузла
    Node* next; // Вказівник на наступний вузол

    Node(int value) : data(value), next(nullptr) {} // Конструктор для ініціалізації значення вузла
};

bool compare(Node* h1, Node* h2) // Порівняння двох списків
{
    while (h1 != nullptr && h2 != nullptr) 
    {
        if (h1->data != h2->data) 
        {
            return false;  // Знайдена різниця в даних вузлів
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    // Перевірка чи обидва списки закінчилися
    return h1 == nullptr && h2 == nullptr;
}

int main() 
{
    // Приклад використання
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);

    Node* list2 = new Node(1);
    list2->next = new Node(2);
    list2->next->next = new Node(3);

    // Виведення результату порівняння
    if (compare(list1, list2)) 
    {
        cout << "Списки рівні\n";
    } 
    else 
    {
        cout << "Списки відрізняються\n";
    }

    // Звільнення пам'яті
    while (list1 != nullptr) 
    {
        Node* temp = list1;
        list1 = list1->next;
        delete temp;
    }

    while (list2 != nullptr) 
    {
        Node* temp = list2;
        list2 = list2->next;
        delete temp;
    }

    return 0;
}
