#include <iostream>
#include <fstream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoubleLinkedList {
private:
    Node* head;

public:
    // Конструктор
    DoubleLinkedList() : head(nullptr) {}

    // Функція для створення порожнього списку
    void createList() {
        head = nullptr;
    }

    // Функція для додавання елемента в кінець списку
    void addElement(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
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

    // Функція для знищення першого елемента списку та додавання нового елемента в кінець
    void deleteFirstElementAddToEnd(int newValue) {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }

            // Додавання нового елемента в кінець списку
            addElement(newValue);

            delete temp;
        }
    }

    // Функція для друку списку
    void printList() const {
        if (!head) {
            std::cout << "The list is empty" << std::endl;
            return;
        }

        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Функція для запису списку у файл
    void writeToFile(const std::string& filename) const {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            Node* current = head;
            while (current) {
                outFile << current->data << " ";
                current = current->next;
            }
            outFile.close();
        } else {
            std::cerr << "Error opening the file for writing" << std::endl;
        }
    }

    // Функція для знищення списку
    void destroyList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Функція для відновлення списку з файлу
    void restoreFromFile(const std::string& filename) {
        destroyList(); // Знищення цього списку перед відновленням

        std::ifstream inFile(filename);
        if (inFile.is_open()) {
            int value;
            while (inFile >> value) {
                addElement(value);
            }
            inFile.close();
        } else {
            std::cerr << "Error opening the file for reading" << std::endl;
        }
    }
};

int main() {
    DoubleLinkedList list;

    // Створення порожнього списку
    list.createList();

    // Додавання елементів у список
    list.addElement(10);
    list.addElement(20);
    list.addElement(30);

    // Друк списку
    std::cout << "Initial list: ";
    list.printList();

    // Знищення першого елемента та додавання нового елемента в кінець
    list.deleteFirstElementAddToEnd(40);

    // Друк списку після змін
    std::cout << "List after modifications: ";
    list.printList();

    // Запис списку у файл
    list.writeToFile("list.txt");

    // Знищення списку
    list.destroyList();

    // Друк порожнього списку
    std::cout << "List after destruction: ";
    list.printList();

    // Відновлення списку з файлу
    list.restoreFromFile("list.txt");

    // Друк відновленого списку
    std::cout << "Restored list: ";
    list.printList();

    // Знищення списку
    list.destroyList();

    return 0;
}
