#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура для представлення елемента списку
struct Node {
    string key;  // Ключове поле - рядок символів
    Node* next;  // Вказівник на наступний елемент
    Node* prev;  // Вказівник на попередній елемент
};

// Клас для управління списком
class DoublyLinkedList {
public:
    Node* head;

    // Конструктор для ініціалізації порожнього списку
    DoublyLinkedList() : head(nullptr) {}

    // Функція для додавання елемента в кінець списку
    void appendNode(const string& key) {
        Node* newNode = new Node{key, nullptr, nullptr};

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Функція для видалення елемента зі списку за ключем
    void deleteNode(const string& key) {
        Node* current = head;

        while (current != nullptr) {
            if (current->key == key) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }

                delete current;
                return;
            }

            current = current->next;
        }
    }

    // Функція для друку списку
    void printList() const {
        if (head == nullptr) {
            cout << "Список порожній" << endl;
        } else {
            Node* current = head;
            while (current != nullptr) {
                cout << current->key << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    // Функція для запису списку у файл
    void writeListToFile(const string& filename) const {
        ofstream file(filename);

        if (!file.is_open()) {
            cerr << "Помилка відкриття файлу" << endl;
            exit(EXIT_FAILURE);
        }

        Node* current = head;
        while (current != nullptr) {
            file << current->key << endl;
            current = current->next;
        }

        file.close();
    }

    // Функція для видалення всього списку
    void deleteList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    // Функція для відновлення списку з файлу
    static DoublyLinkedList restoreListFromFile(const string& filename) {
        DoublyLinkedList newList;

        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Помилка відкриття файлу" << endl;
            exit(EXIT_FAILURE);
        }

        string buffer;
        while (file >> buffer) {
            newList.appendNode(buffer);
        }

        file.close();
        return newList;
    }

    // Функція для додавання елемента після елемента із заданим ключовим полем
    void insertAfterKey(const string& keyToInsertAfter, const string& newKey) {
        Node* current = head;

        while (current != nullptr) {
            if (current->key == keyToInsertAfter) {
                Node* newNode = new Node{newKey, current->next, current};

                if (current->next != nullptr) {
                    current->next->prev = newNode;
                }

                current->next = newNode;
                return;
            }

            current = current->next;
        }

        cout << "Елемент з ключем " << keyToInsertAfter << " не знайдено" << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // 1. Створення списку
    list.appendNode("A");
    list.appendNode("B");
    list.appendNode("C");
    list.appendNode("D");

    // 2. Додавання елемента в список
    cout << "Список після додавання елемента 'E':" << endl;
    list.appendNode("E");
    list.printList();

    // 3. Знищення елемента зі списку
    cout << "Список після видалення елемента 'A':" << endl;
    list.deleteNode("A");
    list.printList();

    // 4. Друк списку
    cout << "Поточний стан списку:" << endl;
    list.printList();

    // 5. Запис списку у файл
    list.writeListToFile("output.txt");

    // 6. Знищення списку
    cout << "Список після знищення:" << endl;
    list.deleteList();
    list.printList();

    // 7. Відновлення списку з файлу
    cout << "Список після відновлення з файлу:" << endl;
    list = DoublyLinkedList::restoreListFromFile("output.txt");
    list.printList();

    // 8. Додавання елемента після елемента із заданим ключовим полем
    cout << "Список після вставки елемента 'F' після 'B':" << endl;
    list.insertAfterKey("B", "F");
    list.printList();

    // 9. Знищення списку
    cout << "Знищення списку:" << endl;
    list.deleteList();
    list.printList();

    return 0;
}
