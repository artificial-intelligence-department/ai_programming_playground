#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    char data[50];  // ключове поле типу *char (рядок символів)
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void createList() {
        head = nullptr;
        cout << "Список створений." << endl;
    }

    void printList() {
        if (!head) {
            cout << "Список порожній." << endl;
            return;
        }

        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void destroyList() {
        head = nullptr;
        cout << "Список знищений." << endl;
    }
    /*
    void destroyList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    cout << "Список знищений." << endl;
    } Така версія допомагає почистити память, але чатгпт сказав шо і попередня підійде
    тому шо після закінчення програми память сама підчиститься

    */

    void addElement(const char* newData) {
        Node* newNode = new Node;
        strcpy(newNode->data, newData);
        newNode->next = head;
        newNode->prev = nullptr;
        if (head) {
            head->prev = newNode;
        }
        head = newNode;
        cout << "Додано елемент: " << newData << endl;
    }

    void deleteElement(const char* key) {
        Node* current = head;
        while (current) {
            if (strcmp(current->data, key) == 0) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next) {
                    current->next->prev = current->prev;
                }

                cout << "Елемент " << key << " видалено." << endl;
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Елемент " << key << " не знайдено." << endl;
    }

    void writeToFile(const char* filename) {
        ofstream file(filename);
        Node* current = head;
        while (current) {
            file << current->data << endl;
            current = current->next;
        }
        file.close();
        cout << "Список записано у файл " << filename << "." << endl;
    }

    void restoreFromFile(const char* filename) {
        ifstream file(filename);
        if (file.is_open()) {
            char newData[50];
            while (file.getline(newData, sizeof(newData))) {
                addElement(newData);
            }
            file.close();
            cout << "Список відновлено з файлу " << filename << "." << endl;
        } else {
            cout << "Не вдалося відкрити файл " << filename << "." << endl;
        }
    }
};

int main() {
    DoublyLinkedList linkedList;
    linkedList.createList();
    linkedList.addElement("A");
    linkedList.addElement("B");
    linkedList.printList();
    linkedList.deleteElement("A");
    linkedList.printList();
    linkedList.addElement("C");
    linkedList.printList();
    linkedList.writeToFile("list.txt");
    linkedList.destroyList();
    linkedList.printList();
    cout << "-----\n";

    DoublyLinkedList restoredList;
    restoredList.restoreFromFile("list.txt");
    restoredList.printList();
    restoredList.destroyList();

    return 0;
}