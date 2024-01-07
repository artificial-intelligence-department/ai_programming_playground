#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class DynamicList {
private:
    Node* head;

public:
    DynamicList() : head(nullptr) {}

    ~DynamicList() {
        destroyList();
    }

    void createList() {}

    void addElement(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void deleteElement(int value) {
        Node* current = head;
        Node* previous = nullptr;

        while (current && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
        }
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

    void writeToFile(const string& filename) {
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cerr << "Помилка відкриття файлу для запису." << endl;
            return;
        }

        Node* current = head;
        while (current) {
            outFile << current->data << " ";
            current = current->next;
        }

        outFile.close();
    }

    void destroyList() {
        Node* current = head;
        Node* next;

        while (current) {
            next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
    }

    void restoreFromFile(const string& filename) {
        destroyList();

        ifstream inFile(filename);
        if (!inFile.is_open()) {
            cerr << "Помилка відкриття файлу для читання." << endl;
            return;
        }

        int value;
        while (inFile >> value) {
            addElement(value);
        }

        inFile.close();
    }
};

int main() {
    DynamicList myList;

    myList.createList();
    myList.addElement(10);
    myList.addElement(20);
    myList.addElement(30);

    cout << "Список до видалення елемента: ";
    myList.printList();

    myList.deleteElement(20);

    cout << "Список після видалення елемента: ";
    myList.printList();

    myList.writeToFile("list.txt");

    myList.destroyList();

    cout << "Список після знищення: ";
    myList.printList();

    myList.restoreFromFile("list.txt");

    cout << "Список після відновлення: ";
    myList.printList();

    return 0;
}
