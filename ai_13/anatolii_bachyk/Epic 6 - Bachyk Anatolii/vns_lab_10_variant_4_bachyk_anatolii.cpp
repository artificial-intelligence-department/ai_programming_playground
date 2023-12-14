#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Функція для створення порожнього списку
Node* createEmptyList() {
    return nullptr;
}

// Функція для додавання елементів в кінець списку
void addEl(Node* &head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Функція для друку списку
void printList(Node* head) {
    if (head == nullptr) {
        cout << "Список порожній" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Функція для знищення списку
void destroyList(Node* &head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Функція для запису списку у файл
void writeListToFile(Node* head, const string& filename) {
    ofstream file(filename);

    Node* temp = head;
    while (temp != nullptr) {
        file << temp->data << " ";
        temp = temp->next;
    }

    file.close();
}

// Функція для відновлення списку з файлу
Node* restoreListFromFile(const string& filename) {
    ifstream file(filename);
    Node* head = nullptr;
    int value;

    while (file >> value) {
        addEl(head, value);
    }

    file.close();
    return head;
}

int main() {
    Node* List = createEmptyList();

    addEl(List, 10);
    addEl(List, 20);
    addEl(List, 30);

    cout << "Початковий список: ";
    printList(List);

    writeListToFile(List, "List.txt");

    destroyList(List);

    cout << "Список після знищення: ";
    printList(List);

    List = restoreListFromFile("List.txt");

    cout << "Відновлений список: ";
    printList(List);

    destroyList(List);

    return 0;
}