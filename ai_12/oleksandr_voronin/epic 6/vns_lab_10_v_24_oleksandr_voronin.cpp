
#include <iostream>
#include <cstring>

using namespace std;

struct Node
{
    char* data;
    Node* next;
    Node* prev;
};

struct DoubleLinkedList
{
    int size;
    Node* head;
    Node* tail;
};

DoubleLinkedList* createList()
{
    DoubleLinkedList* list = new DoubleLinkedList;
    list->size = 0;
    list->head = list->tail = nullptr;
    return list;
}

void addElementToList(DoubleLinkedList* list, const char* newData)
{
    Node* newNode = new Node;
    newNode->data = strdup(newData);
    newNode->next = nullptr;

    if (list->head == nullptr) {
        newNode->prev = nullptr;
        list->head = list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;
}


void addElements(DoubleLinkedList* list)
{
    char newData[100];
    int keyToAad = 1;

    cout << "Enter word to add: ";
    cin >> newData;

    cout << "Enter key around which want to add: ";
    char key[100];
    cin >> key;


    Node* current = list->head;

    
    while (current != nullptr && strcmp(current->data, key) != 0) {
        current = current->next;
    }

    
    if (current == nullptr) {
        cout << "Element with key " << key << " not found." << endl;
        return;
    }

    
    for (int i = 0; i < keyToAad; ++i) {
        Node* newNode = new Node;
        newNode->data = strdup(newData);
        newNode->prev = current->prev;
        newNode->next = current;

        if (current->prev != nullptr) {
            current->prev->next = newNode;
        } else {
            list->head = newNode;
        }

        current->prev = newNode;
        list->size++;
    }

    
    for (int i = 0; i < keyToAad; ++i) {
        Node* newNode = new Node;
        newNode->data = strdup(newData);
        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            list->tail = newNode;
        }

        current->next = newNode;
        list->size++;
    }
}

void deleteElementKey(DoubleLinkedList* list)
{   
    char keyToDelete[100];
    cout << "Enter the word you wana delete: ";
    cin >> keyToDelete;
    Node* current = list->head;

    while (current != nullptr && strcmp(current->data, keyToDelete) != 0) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Element with key " << keyToDelete << " not found." << endl;
        return;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }

    delete[] current->data;
    delete current;
    list->size--;
}


void printList(DoubleLinkedList* list)
{
    Node* current = list->head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    DoubleLinkedList* list = createList();

    addElementToList(list, "How");
    addElementToList(list, "Are");
    addElementToList(list, "you");

    cout << "Initial List: ";
    printList(list);

    addElements(list);

    cout << "List after add: ";
    printList(list);

    
    deleteElementKey(list);

    
    printList(list);
    delete list;

    return 0;
}
