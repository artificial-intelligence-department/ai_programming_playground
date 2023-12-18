#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct node
{
    string data;
    node* prev;
    node* next;
};

void add(node*& head, node*& tail, const string& value);
void deletenode(node*& head, node*& tail, const string& key);
void print(const node* head);
node* createList(const string values[], int size);
void writeToFile(const node* head, const string& filename);
node* readFromFile(const string& filename);
void destroyList(node*& head);

int main()
{
    node* head = nullptr;
    node* tail = nullptr;

    const string initialValues[] = {"yoda", "baby", "love"};
    int initialSize = sizeof(initialValues) / sizeof(initialValues[0]);
    head = createList(initialValues, initialSize);

    cout << "Початковий список елементів: ";
    print(head);

    cout << "Введіть кількість елементів для додавання: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string value;
        cout << "Введіть значення для елемента " << i + 1 << ": ";
        cin >> value;
        add(head, tail, value);
    }

    cout << "Список елементів: ";
    print(head);

    string key;
    cout << "Введіть ключ для видалення елемента: ";
    cin >> key;

    deletenode(head, tail, key);

    cout << "Оновлений список елементів після видалення: ";
    print(head);

    writeToFile(head, "list.txt");
    destroyList(head);

    cout << "Оновлений список елементів після повного видалення і запису в файл: ";
    print(head);

    head = readFromFile("list.txt");

    cout << "Список елементів після відновлення з файлу: ";
    print(head);

    destroyList(head);

    remove("list.txt");
}

void add(node*& head, node*& tail, const string& value)
{
    node* newnode = new node{value, nullptr, nullptr};
    if (!head)
    {
        head = tail = newnode;
    }
    else
    {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void deletenode(node*& head, node*& tail, const string& key)
{
    node* current = head;
    while (current)
    {
        if (current->data == key)
        {
            if (current->prev)
                current->prev->next = current->next;
            else
                head = current->next;

            if (current->next)
                current->next->prev = current->prev;
            else
                tail = current->prev;

            delete current;
            return;
        }
        current = current->next;
    }

    cout << "Елемент з ключем '" << key << "' не знайдений." << endl;
}

void print(const node* head)
{
    if (!head)
    {
        cout << "Список порожній" << endl;
        return;
    }
    const node* current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

node* createList(const string values[], int size)
{
    node* head = nullptr;
    node* tail = nullptr;

    for (int i = 0; i < size; ++i)
    {
        add(head, tail, values[i]);
    }

    return head;
}

void writeToFile(const node* head, const string& filename)
{
    ofstream outFile(filename);
    const node* current = head;
    while (current)
    {
        outFile << current->data << endl;
        current = current->next;
    }
    outFile.close();
}

node* readFromFile(const string& filename)
{
    node* head = nullptr;
    node* tail = nullptr;

    ifstream inFile(filename);
    string value;
    while (inFile >> value)
    {
        add(head, tail, value);
    }
    inFile.close();

    return head;
}


void destroyList(node*& head)
{
    while (head)
    {
        node* next = head->next;
        delete head;
        head = next;
    }
}
