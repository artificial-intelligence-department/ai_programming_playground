#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

class dll
{
private:
        //створюємо початок та кінець списку
        //вони не є посиланнями
    Node head;
    Node tail;
public:
    dll()
    {
        head.prev = nullptr;
        head.next = &tail;

        tail.prev = &head;
        tail.next = nullptr;
    }
    int size = 0;

    Node* start() {
        return head.next;
    }

    Node* end() {
        return &tail;
    }

    void pushBack(int value) {
        insertAfter(*tail.prev, value);
    }

    void push(int value) {
        insertAfter(head, value);
    }

    void insertAfter(Node &after, int value)
    {
        Node* node = new Node();
        node->data = value;

            //main logic
        node->next = after.next;
        after.next->prev = node;

        after.next = node;
        node->prev = &after;

        size++;
    }

    void deleteAfter(int index)
    {
            //exeption
        if (index <= 0 || index > size) {
            cout << "Wrong index..." << endl;
            return;
        } if(head.next == nullptr) {
            cout << "List is empty..." << endl;
            return;
        }

        Node* node = start();
        for (int i = 1; i < index && node != end(); i++)
            node = node->next;

        node->prev->next = node->next;
        node->next->prev = node->prev;

        delete node;
        size--;
    }

    void print()
    {
        if (size == 0)
        {
            cout << "List is empty..." << endl;
            return;
        }
        
        for (Node* list = head.next; list->next != nullptr; list = list->next)
            cout << list->data << " ";
        cout << endl;
    }

    bool writeToFile(string fileName)
    {
        ofstream fout(fileName);

            //error while try to open while
        if (!fout.is_open())
            return false;
        
        for (Node* list = start(); list->next != nullptr; list = list->next)
            fout << list->data << endl;
        
        return true;
    }

    bool readFromFile(string fileName)
    {
        ifstream fin(fileName);

        Node* result = start();

            //error while try to open while
        if (!fin.is_open())
            return false;

        string line;
        while (getline(fin, line))
            pushBack(stoi(line));

        return true;
    }

    void clear()
    {
        for (Node* list = head.next->next; list != nullptr; list = list->next)
            delete list->prev;

        size = 0;
        dll();
    }
};

int main()
{
        //1. Створення списку
    dll list = dll();

        //2. Додавання елемента в список
    for (int i = 0; i < 10; i++)
    {
        if(i < 5)
            list.push(i);
        else
            list.pushBack(i);
    }

    list.print();

        //3. Знищення елемента зі списку
    list.deleteAfter(10);
        //2. Додавання елемента в список (у відповідності зі своїм варіантом).
    list.push(66);

        //4. Друк списку
    list.print();

        //5. Запис списку у файл
    list.writeToFile("saveLinkedList.dat");

        //6. Знищення списку
    list.clear();
    list.print();

        //7. Відновлення списку з файлу.
    list.readFromFile("saveLinkedList.dat");
    list.print();

    return 0;
}