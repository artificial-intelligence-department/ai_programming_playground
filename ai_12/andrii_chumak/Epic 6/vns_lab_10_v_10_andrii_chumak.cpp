#include <iostream>
#include <fstream>

using namespace std;

/*
Створення списку: Функція для створення порожнього списку або додавання елементів до існуючого списку.

Додавання елемента до списку: Функція для додавання нового елемента до кінця двонаправленого списку.

Видалення елемента зі списку: Функція видалення заданої кількості елементів з кінця списку.

Виведення списку: Функція для відображення значень елементів списку на екрані.

Запис списку у файл: Функція для збереження значень елементів списку текстового файлу.

Видалення списку: Функція повного видалення всіх елементів зі списку.

Відновлення списку з файлу: Функція для зчитування значень елементів текстового файлу та відновлення списку.

*/

// Структура для представлення елементу списку
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Клас для представлення двонаправленого списку
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    // Функція для створення списку
    void createList() {}
    
    // Функція для додавання елемента в список
    void addElement(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    // Функція для знищення елемента з кінця списку
    void deleteKElementsFromEnd(int k) {
        Node* current = tail;
        while (current && k > 0) {
            Node* temp = current;
            current = current->prev;
            delete temp;
            k--;
        }
        
        // Перевірка чи весь список був знищений
        if (current == nullptr) {
            head = tail = nullptr;
        } else {
            current->next = nullptr;
            tail = current;
        }
    }
    
    // Функція для друку списку
    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    // Функція для запису списку у файл
    void writeToFile(const char* filename) {
        ofstream outFile(filename);
        Node* current = head;
        while (current) {
            outFile << current->data << " ";
            current = current->next;
        }
        outFile.close();
    }
    
    // Функція для знищення списку
    void deleteList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
    }
    
    // Функція для відновлення списку з файлу
    void restoreFromFile(const char* filename) {
        ifstream inFile(filename);
        int value;
        while (inFile >> value) {
            addElement(value);
        }
        inFile.close();
    }
};

int main() {
    DoublyLinkedList myList;
    
    // Створення списку
    myList.createList();
    
    // Додавання елементів
    myList.addElement(10);
    myList.addElement(20);
    myList.addElement(30);
    
    // Друк списку
    cout << "List before deletion: ";
    myList.printList();
    
    // Знищення К елементів з кінця списку
    int k = 2;
    myList.deleteKElementsFromEnd(k);
    
    // Друк списку після знищення
    cout << "List after deletion of " << k << " elements from end: ";
    myList.printList();
    
    // Запис списку у файл
    myList.writeToFile("output.txt");
    
    // Знищення списку
    myList.deleteList();
    
    // Відновлення списку з файлу
    myList.restoreFromFile("output.txt");
    
    // Друк відновленого списку
    cout << "Restored list: ";
    myList.printList();
    
    return 0;
}
