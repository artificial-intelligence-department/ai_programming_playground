#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Node 
{
    char data[100];
    Node* previous;
    Node* next;
};


Node* createList() 
{
    return nullptr;
}


void addtolist(Node*& head, const char* data) 
{
    Node* newNode = new Node;
    strncpy(newNode->data, data, sizeof(newNode->data));
    newNode->previous = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) 
    {
        head = newNode;
    } 
    else 
    {
        Node* current = head;
        while (current->next != nullptr) 
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->previous = current;
    }
}


void printList(const Node* head) 
{
    if (head == nullptr) 
    {
        cout << "Список порожній(" << endl;
    }
    else 
    {
        const Node* current = head;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}


void earasenode(Node*& head, const char* key) 
{
    Node* current = head;
    while (current != nullptr) 
    {
        if (strcmp(current->data, key) == 0) 
        {
            if (current->previous != nullptr) {

                current->previous->next = current->next;
            } 
            else 
            {
                head = current->next;
            }
            if (current->next != nullptr) 
            {
                current->next->previous = current->previous;
            }
            delete current;
            return;
        }
        current = current->next;
    }
}


void addition(Node*& head, int K) 
{
    for (int i = 0; i < K; ++i) 
    {
        char buffer[100];
        sprintf(buffer, "Елемент %d", i);
        Node* newNode = new Node;
        strncpy(newNode->data, buffer, sizeof(newNode->data));
        newNode->previous = nullptr;
        newNode->next = head;

        if (head != nullptr) 
        {
            head->previous = newNode;
        }

        head = newNode;
    }

    Node* current = head;
    while (current->next != nullptr) 
    {
        current = current->next;
    }

    for (int i = K; i < 2 * K; ++i) 
    {
        char buffer[100];
        sprintf(buffer, "Елемент %d", i);
        Node* newNode = new Node;
        strncpy(newNode->data, buffer, sizeof(newNode->data));
        newNode->previous = current;
        newNode->next = nullptr;
        current->next = newNode;
        current = newNode;
    }
}


void destroy(Node*& head) 
{
    Node* current = head;
    while (current != nullptr) 
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}


void writeinfile(const Node* head, const char* filename) 
{
    ofstream file(filename);
    if (!file.is_open()) 
    {
        cerr << "Помилка відкриття файлу" << endl;
        exit(EXIT_FAILURE);
    }

    const Node* current = head;
    while (current != nullptr) 
    {
        file << current->data << endl;
        current = current->next;
    }

    file.close();
}


Node* readinfile(const char* filename) 
{
    ifstream file(filename);
    if (!file.is_open()) 
    {
        cerr << "Помилка відкриття файлу" << endl;
        exit(EXIT_FAILURE);
    }

    Node* head = nullptr;
    char buffer[100];
    while (file.getline(buffer, sizeof(buffer))) 
    {
        addtolist(head, buffer);
    }

    file.close();
    return head;
}

int main() {
    Node* myList = createList();

    addition(myList, 3);

    cout << "Список після додавання елементів:" << endl;
    printList(myList);

    earasenode(myList, "Елемент 1");

    cout << "Список після знищення елемента:" << endl;
    printList(myList);
    writeinfile(myList, "myList.txt");

    destroy(myList);

    cout << "Список після знищення:" << endl;
    printList(myList);

    myList = readinfile("myList.txt");

    cout << "Відновлений список:" << endl;
    printList(myList);

    destroy(myList);

    return 0;
}
