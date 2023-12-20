#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Node
{
    char *data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    Node *createNode(const char *value)
    {
        Node *newNode = new Node;
        newNode->data = new char[strlen(value) + 1];
        strcpy(newNode->data, value);
        newNode->prev = nullptr;
        newNode->next = nullptr;
        return newNode;
    }

    void addNode(const char *value)
    {
        Node *newNode = createNode(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void deleteNodeByKey(const char *key)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (strcmp(current->data, key) == 0)
            {
                if (current == head)
                {
                    head = head->next;
                    if (head != nullptr)
                    {
                        head->prev = nullptr;
                    }
                }
                else if (current == tail)
                {
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete[] current->data;
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Елемент з ключем '" << key << "' не знайдений." << endl;
    }

    void addKElemToStartEnd(int k)
    {
        for (int i = 0; i < k; ++i)
        {
            char value[100];
            cout << "Введіть елемент для додавання на початок та в кінець списку: ";
            cin >> value;
            addNodeToFront(value);
            addNode(value);
        }
    }

    void addNodeToFront(const char *value)
    {
        Node *newNode = createNode(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void writeToFile(const string &filename)
    {
        ofstream file(filename);
        Node *current = head;
        while (current != nullptr)
        {
            file << current->data << "\n";
            current = current->next;
        }
        file.close();
        cout << "Список записано у файл '" << filename << "'" << endl;
    }

    void restoreFromFile(const string &filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "Не вдалося відкрити файл '" << filename << "'" << endl;
            return;
        }

        char value[100];
        while (file >> value)
        {
            addNode(value);
        }
        file.close();
        cout << "Список відновлено з файлу '" << filename << "'" << endl;
    }

    void deleteList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete[] temp->data;
            delete temp;
        }
        head = tail = nullptr;
    }
};

int main()
{
    DoublyLinkedList list;

    list.addNode("One");
    list.addNode("Two");
    list.addNode("Three");
    cout << "Друк списку: ";
    list.printList();
    list.deleteNodeByKey("Two");
    int K = 2;
    list.addKElemToStartEnd(K);
    cout << "Оновлений список: ";
    list.printList();
    list.writeToFile("list.txt");
    list.deleteList();
    list.restoreFromFile("list.txt");

    cout << "Відновлений список: ";
    list.printList();

    return 0;
}
