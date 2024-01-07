#include <iostream>
#include <cstring>

using namespace std;

// Структура елемента двонаправленого списку
struct Node {
    char *data;
    Node *prev;
    Node *next;
};

// Функція для створення нового вузла
Node* createNode(const char *str) {
    Node *newNode = new Node;
    newNode->data = new char[strlen(str) + 1];
    strcpy(newNode->data, str);
    newNode->prev = newNode->next = nullptr;
    return newNode;
}

// Функція для додавання нового вузла на початок списку
void addToFront(Node *&head, const char *str) {
    Node *newNode = createNode(str);
    if (!head) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Функція для додавання нового вузла на кінець списку
void addToEnd(Node *&head, const char *str) {
    Node *newNode = createNode(str);
    if (!head) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Функція для видалення елементів перед і після елемента з заданим ключем
void removeAdjacentNodes(Node *&head, const char *key) {
    Node *current = head;
    while (current) {
        if (strcmp(current->data, key) == 0) {
            if (current->prev) {
                Node *prevNode = current->prev;
                if (prevNode->prev) {
                    prevNode->prev->next = current;
                } else {
                    head = current;
                }
                delete prevNode;
            }

            if (current->next) {
                Node *nextNode = current->next;
                if (nextNode->next) {
                    nextNode->next->prev = current;
                }
                delete nextNode;
            }
        }
        current = current->next;
    }
}

// Функція для виведення списку
void printList(Node *head) {
    Node *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Головна функція
int main() {
    Node *head = nullptr;

    addToFront(head, "world");
    addToFront(head, "hello");

    printList(head);  // Виведе: hello world
    return 0;
}
