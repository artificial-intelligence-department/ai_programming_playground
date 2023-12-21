#include <iostream>
#include <fstream>
#include <cstring>

struct Node {
    char* key;
    Node* next;
    Node* prev;
};

Node* createNode(const char* value) {
    Node* newNode = new Node;
    newNode->key = strdup(value);
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void appendNode(Node*& head, const char* value) {
    Node* newNode = createNode(value);
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void printList(Node* head) {
    if (!head) {
        std::cout << "Список порожній" << std::endl;
        return;
    }

    Node* current = head;
    while (current) {
        std::cout << current->key << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void saveListToFile(Node* head, const char* filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
        return;
    }

    Node* current = head;
    while (current) {
        file << current->key << std::endl;
        current = current->next;
    }

    file.close();
}

void deleteKNodesFromEnd(Node*& head, int k) {
    if (!head) {
        return;
    }

    Node* current = head;
    int length = 0;
    while (current) {
        length++;
        current = current->next;
    }

    current = head;
    for (int i = 0; i < length - k - 1; i++) {
        current = current->next;
    }

    if (current->next) {
        Node* temp = current->next;
        current->next = temp->next;
        if (temp->next) {
            temp->next->prev = current;
        }
        delete temp;
    }
}

void insertAfterKey(Node*& head, const char* keyToFind, const char* newValue) {
    Node* current = head;
    while (current) {
        if (strcmp(current->key, keyToFind) == 0) {
            Node* newNode = createNode(newValue);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}

void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete[] temp->key;
        delete temp;
    }
}

int main() {
    Node* myList = nullptr;

    appendNode(myList, "A");
    appendNode(myList, "B");
    appendNode(myList, "C");
    appendNode(myList, "D");

    std::cout << "Наш початковий список: ";
    printList(myList);

    int k = 2;
    deleteKNodesFromEnd(myList, k);
    std::cout << "Після видалення " << k << " елементів з кінця: ";
    printList(myList);

    const char* keyToFind = "B";
    const char* newValue = "X";
    insertAfterKey(myList, keyToFind, newValue);
    std::cout << "Після вставки нового елемента після нашого ключа " << keyToFind << ": ";
    printList(myList);

    saveListToFile(myList, "moyfile.txt");

    deleteList(myList);

    return 0;
}