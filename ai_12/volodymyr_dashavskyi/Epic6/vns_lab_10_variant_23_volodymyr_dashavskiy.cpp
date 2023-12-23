#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура елементу списку
struct Node
{
    string key;
    Node *prev;
    Node *next;
};

// Функція створення нового елементу
Node *createNode(const string &key)
{
    Node *newNode = new Node;
    newNode->key = key;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Функція додавання елемента в кінець списку
void addNode(Node **head, const string &key)
{
    Node *newNode = createNode(key);
    if (*head == nullptr)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Функція друку списку
void printList(Node *head)
{
    cout << "List elements:" << endl;
    while (head != nullptr)
    {
        cout << head->key << endl;
        head = head->next;
    }
}

// Функція знищення елемента зі списку за заданим ключем
void deleteNodeByKey(Node **head, const string &key)
{
    Node *current = *head;
    Node *temp = nullptr;

    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (current->prev == nullptr)
            {
                *head = current->next;
            }
            else
            {
                current->prev->next = current->next;
            }
            if (current->next != nullptr)
            {
                current->next->prev = current->prev;
            }
            temp = current;
            delete temp;
            return;
        }
        current = current->next;
    }
    cout << "element with key '" << key << "' haven't been found in the list." << endl;
}

// Функція додавання K елементів після елемента з заданим ключем
void addKElemAfterKey(Node *head, const string &key, int K)
{
    while (head != nullptr)
    {
        if (head->key == key)
        {
            for (int i = 0; i < K; ++i)
            {
                string newElement;
                cout << "Enter new element which will be added after element with key '" << key << "': ";
                cin >> newElement;
                Node *newNode = createNode(newElement);
                newNode->next = head->next;
                newNode->prev = head;
                if (head->next != nullptr)
                {
                    head->next->prev = newNode;
                }
                head->next = newNode;
                head = newNode;
            }
            return;
        }
        head = head->next;
    }
    cout << "Element with key '" << key << "' haven't been found in the list." << endl;
}

// Функція запису списку у файл
void writeListToFile(Node *head, const string &filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Error while opening file!" << endl;
        exit(EXIT_FAILURE);
    }

    while (head != nullptr)
    {
        file << head->key << endl;
        head = head->next;
    }

    file.close();
    cout << "List was succesfully inputed in file '" << filename << "'." << endl;
}

// Функція знищення всього списку
void deleteList(Node **head)
{
    Node *current = *head;
    Node *next;

    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }

    *head = nullptr;
    cout << "The list have been succesfully deleted." << endl;
}

// Функція відновлення списку з файлу
Node *restoreListFromFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error while opening file for reading!" << endl;
        exit(EXIT_FAILURE);
    }

    Node *head = nullptr;
    string buffer;

    while (getline(file, buffer))
    {
        addNode(&head, buffer);
    }

    file.close();
    cout << "The list was succesfully returned from the file '" << filename << "'." << endl;
    return head;
}

int main()
{
    Node *head = nullptr;
    int choice, K;
    string key, filename;
    do
    {
        cout << "\n----- Menu -----" << endl;
        cout << "1. Add an element into the list" << endl;
        cout << "2. Delete element from the list by its key" << endl;
        cout << "3. Add K elements after an element with presented key" << endl;
        cout << "4. Print the list" << endl;
        cout << "5. Write the list to a file" << endl;
        cout << "6. Return the list from the file" << endl;
        cout << "7. List removal" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose the ation: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element for adding: ";
            cin >> key;
            addNode(&head, key);
            break;
        case 2:
            cout << "Enter key for removing element: ";
            cin >> key;
            deleteNodeByKey(&head, key);
            break;
        case 3:
            cout << "Enter element key after which new elements will be added: ";
            cin >> key;
            cout << "Enter number of elements to be added: ";
            cin >> K;
            addKElemAfterKey(head, key, K);
            break;
        case 4:
            printList;
            printList(head);
            break;
        case 5:
            cout << "Enter file name: ";
            cin >> filename;
            writeListToFile(head, filename);
            break;
        case 6:
            cout << "Enter file name for returning the list: ";
            cin >> filename;
            head = restoreListFromFile(filename);
            break;
        case 7:
            deleteList(&head);
            break;
        case 0:
            cout << "Thanks for using the program!" << endl;
            deleteList(&head);
            break;
        default:
            cout << "Incorrect input. Select an excisting action ." << endl;
        }
    } while (choice != 0);

    return 0;
}