#include <iostream>

using namespace std;

class Node // Клас для представлення вузла списку
{
public:
    int data; // Значення вузла
    Node* next; // Вказівник на наступний вузол

    Node(int value) : data(value), next(nullptr) {} // Конструктор для ініціалізації значення вузла
};

class LinkedList // Клас для представлення зв'язаного списку
{
private:
    Node* head; // Вказівник на голову списку

public:
    LinkedList() : head(nullptr) {} // Конструктор для ініціалізації голови списку

    void insert(int value) // Вставлення нового вузла на початок списку
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    Node* reverse(Node* head) // Обертання списку
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    void print_List(Node* head) // Виведення елементів списку 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    void print_original() // Виведення оригінального та обернутого списку
    {
        cout << "Original List: ";
        print_List(head);

        Node* reversedHead = reverse(head);

        cout << "Reversed List: ";
        print_List(reversedHead);
    }
};

int main() 
{
    LinkedList myList;

    myList.insert(1); // Вставка елементів до списку
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);

    myList.print_original(); // Виведення оригінального та обернутого списку

    return 0;
}
