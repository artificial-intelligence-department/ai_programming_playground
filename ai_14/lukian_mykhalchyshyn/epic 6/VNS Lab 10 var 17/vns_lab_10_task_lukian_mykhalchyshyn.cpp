#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Node // Структура для представлення вузла списку
{
    char* data; // Ключове поле - рядок символів
    Node* next; // Вказівник на наступний вузол
    Node* prev; // Вказівник на попередній вузол
}; 

class DoublyLinkedList // Клас для реалізації двонаправленого списку
{
private:
    Node* head; // Вказівник на початок списку

public:
    DoublyLinkedList() : head(nullptr) {}

    void createList() // Функція для створення порожнього списку
    {
        head = nullptr;
        cout << "Створено порожній список\n";
    }

    void addElement(const char* newData) // Функція для додавання елемента в початок списку
    {
        Node* newNode = new Node; // Створення нового вузла
        newNode->data = strdup(newData); // Копіювання рядка символів
        newNode->next = nullptr; 
        newNode->prev = nullptr;

        if (head == nullptr) 
        {
            head = newNode;
        } 
        else 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        cout << "Додано елемент: " << newData << endl;
        printList();
    }

    void deleteElement(int position) // Функція для видалення елемента за заданим номером
    {
        if (head == nullptr) 
        {
            cout << "Список порожній. Нема що видаляти\n";
            return;
        }

        Node* current = head;
        int count = 1;

        while (current != nullptr && count < position) 
        {
            current = current->next;
            count++;
        }

        if (current == nullptr) 
        {
            cout << "Елемент не знайдено\n";
            return;
        }

        if (current->prev != nullptr) 
        {
            current->prev->next = current->next;
        } 
        else
        {
            head = current->next;
        }

        if (current->next != nullptr) 
        {
            current->next->prev = current->prev;
        }

        cout << "Елемент видалено. Новий вигляд списку:\n";
        printList();
    }

    void printList() // Функція для друку всього списку
    {
        if (head == nullptr) 
        {
            cout << "Список порожній\n";
            return;
        }

        Node* current = head;
        cout << "Список: ";
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void writeToFile(const char* filename)  // Функція для запису списку у файл
    {
        ofstream outFile(filename);

        Node* current = head;
        while (current != nullptr) 
        {
            outFile << current->data << endl;
            current = current->next;
        }

        outFile.close();
        cout << "Список записано у файл: " << filename << endl;
    }

    void destroyList() // Функція для знищення всього списку
    {
        Node* current = head;
        while (current != nullptr) 
        {
            Node* nextNode = current->next;
            delete[] current->data;
            delete current;
            current = nextNode;
        }

        head = nullptr;
        cout << "Список знищено\n";
    }

    void restoreFromFile(const char* filename)  // Функція для відновлення списку з файлу
    {
        ifstream inFile(filename);
        if (!inFile.is_open()) 
        {
            cout << "Помилка відкриття файлу\n";
            return;
        }

        destroyList(); // Очищення поточного списку перед відновленням

        char buffer[256];
        while (inFile.getline(buffer, sizeof(buffer))) 
        {
            addElement(buffer);
        }

        inFile.close();
        cout << "Список відновлено\n";
    }
};

int main() 
{
    DoublyLinkedList myList; // Створення об'єкта класу

    myList.createList(); // Створення порожнього списку

    myList.addElement("Елемент1");
    myList.addElement("Елемент2");
    myList.addElement("Елемент3");

    myList.deleteElement(2);

    myList.addElement("Елемент4");
    myList.addElement("Елемент5");

    myList.writeToFile("output.txt");

    myList.destroyList();

    myList.restoreFromFile("output.txt");

    return 0;
}
