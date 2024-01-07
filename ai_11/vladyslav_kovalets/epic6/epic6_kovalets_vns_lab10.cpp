#include <iostream>

using namespace std;

// Структура для елемента списку
struct Node 
{
    int key;
    Node* next;
};

// Функція для створення порожнього списку
Node* createList()
{
    return nullptr;
}

// Функція для додавання елемента в кінець списку
void addElement(Node* &head, int key) 
{
    Node* newNode = new Node;
    newNode->key = key;
    newNode->next = nullptr;

    if (!head) 
    {
        head = newNode;
    } 
    else 
    {
        Node* current = head;
        while (current->next) 
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функція для видалення елемента зі списку за ключем
void removeElement(Node* &head, int key) 
{
    if (!head)
    {
        cout << "Список порожній" << endl;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current && current->key != key) 
    {
        prev = current;
        current = current->next;
    }

    if (!current) 
    {
        cout << "Елемент не знайдений у списку" << endl;
        return;
    }

    if (!prev) 
    {
        head = current->next;
    } 
    else 
    {
        prev->next = current->next;
    }

    delete current;
}

// Функція для додавання елемента перед елементом за ключем
void addBeforeElement(Node*& head, int key, int newKey) 
{
    Node* newNode = new Node;
    newNode->key = newKey;
    newNode->next = nullptr;

    if (!head) 
    {
        cout << "Список порожній" << endl;
        delete newNode;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current && current->key != key)
    {
        prev = current;
        current = current->next;
    }

    if (!current) 
    {
        cout << "Елемент не знайдений у списку" << endl;
        delete newNode;
        return;
    }

    if (!prev) 
    {
        newNode->next = head;
        head = newNode;
    } 
    else 
    {
        prev->next = newNode;
        newNode->next = current;
    }
}

// Функція для друку списку
void printList(const Node* head) 
{
    if (!head) 
    {
        cout << "Список порожній" << endl;
        return;
    }

    const Node* current = head;
    while (current) 
    {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

// Функція для знищення списку
void destroyList(Node* &head) 
{
    Node* current = head;
    while (current) 
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

int main() 
{
    Node* myList = createList();

    // Додавання елементів до списку
    addElement(myList, 10);
    addElement(myList, 20);
    addElement(myList, 30);

    // Друк списку
    cout << "Список після додавання елементів: ";
    printList(myList);

    // Видалення елемента зі списку
    removeElement(myList, 20);

    // Друк списку після видалення елемента
    cout << "Список після видалення елемента: ";
    printList(myList);

    // Додавання елемента перед елементом з заданим ключем
    addBeforeElement(myList, 30, 25);

    // Друк списку після додавання перед елементом
    cout << "Список після додавання перед елементом: ";
    printList(myList);

    // Знищення списку після використання
    destroyList(myList);

    return 0;
}
