#include <iostream>
#include <fstream>
using namespace std;

// Структура для представлення елементів списку
struct Node {
    int data;
    Node* next;
    Node* previous;
};

// Функція для створення списку заданого розміру
void createList(Node*& head, Node*& tail, int size) {
    head = nullptr, tail = nullptr;
    if (size == 0) {
        return;
    }
    head = new Node;
    head->data = 1;
    Node* current = head;
    for (int i = 2; i <= size; i++) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->previous = current;
        current->next = newNode;
        current = newNode;
    }
    tail = current;
}

// Функція для виведення списку
void printList(Node* node, Node* tail) {
    while (node != tail->next) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Функція для вставки нового елемента в задану позицію
void insertNode(Node*& head, Node*& tail, int position, int value) {
    Node* current = head;
    for (int i = 1; i < position; i++) {
        if (current == tail) {
            cout << "Неправильна позиція!" << endl;
            return;
        }
        current = current->next;
    }

    Node* newNode = new Node;
    newNode->data = value;

    newNode->next = current->next;
    newNode->previous = current;

    if (current->next != tail->next) {
        (current->next)->previous = newNode;
    }
    else {
        tail = newNode;
    }

    current->next = newNode;
}

// Функція для видалення N елементів з кінця списку
void deleteElements(Node*& head, Node*& tail, int N) {
    if (head == nullptr) {
        cout << "Список порожній" << endl;
        return;
    }

    Node* target = tail;
    for (int i = 1; i <= N && target != nullptr; i++) {
        Node* previous = target->previous;
        tail = previous;
        delete target;
        target = previous;
    }

    if (target == nullptr) {
        head = nullptr;
        tail = nullptr;
    }
}

// Функція для запису списку в файл
void fillTheFile(Node* node, Node* tail, string path) {
    ofstream file;
    file.open(path, ios_base::app);
    while (node != tail->next) {
        file << node->data << " ";
        node = node->next;
    }
    file.close();
}

// Функція для видалення всього списку
void deletelist(Node*& head, Node*& tail) {
    while (head != tail->next) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

int main() {
    Node* head;
    Node* tail;
    int size = 10;
    createList(head, tail, size);
    printList(head, tail);

    insertNode(head, tail, 6, 3);
    printList(head, tail);

    deleteElements(head, tail, 8);
    printList(head, tail);

    string path = "vns_task_10.txt";
    fillTheFile(head, tail, path);

    deletelist(head, tail);

    return 0;
}
