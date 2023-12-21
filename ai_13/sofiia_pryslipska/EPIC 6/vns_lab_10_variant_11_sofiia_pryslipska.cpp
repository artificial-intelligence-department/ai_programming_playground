#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура елемента списку
struct Node {
    string data;
    Node* prev;
    Node* next;
};

// Клас двонаправленого списку
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Конструктор
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Функція для додавання елемента в кінець списку
    void addElement(const string& value) {
        Node* newNode = new Node();
        newNode->data = value; // призначення значення value полю data
        newNode->prev = tail;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
    }

    // Функція для видалення елемента зі списку за заданим ключем (рядком символів)
    void deleteElement(const string& key) {
        Node* current = head;
        while (current) {
            if (current->data == key) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete current;
                cout << "Element with a key'" << key << "'deleted from the list." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Element with a key'" << key << "'not found in the list." << endl;
    }

    // Функція для виводу списку
    void printList() const {
        if (!head) {
            cout << "The list is empty" << endl;
            return;
        }

        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Функція для запису списку у файл
    void saveToFile(const string& filename) const {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            Node* current = head;
            while (current) {
                outFile << current->data << "\n";
                current = current->next;
            }
            outFile.close();
            cout << "List successfully saved to file '" << filename << "'." << endl;
        } else {
            cout << "Could not open file for writing." << endl;
        }
    }

    // Функція для знищення списку
    void clearList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        cout << "The list is empty." << endl;
    }

    // Функція для відновлення списку з файлу
    void restoreFromFile(const string& filename) {
        clearList();

        ifstream inFile(filename);
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                addElement(line);
            }
            inFile.close();
            cout << "List restored from file '" << filename << "'." << endl;
        } else {
            cout << "Failed to open recovery file." << endl;
        }
    }
};

int main() {
    DoublyLinkedList myList;

    // Додавання елементів у список
    myList.addElement("element1");
    myList.addElement("element2");
    myList.addElement("element3");

    // Друк списку
    cout << "List after adding elements: ";
    myList.printList();

    // Видалення елемента зі списку
    myList.deleteElement("element2");

    // Друк списку після видалення елемента
    cout << "List after deleting an element: ";
    myList.printList();

    // Запис списку у файл
    myList.saveToFile("myList.txt");

    // Знищення списку та вивід порожнього списку
    myList.clearList();
    myList.printList();

    // Відновлення списку з файлу
    myList.restoreFromFile("myList.txt");

    // Друк відновленого списку
    cout << "Restored list: ";
    myList.printList();

    return 0;
}
