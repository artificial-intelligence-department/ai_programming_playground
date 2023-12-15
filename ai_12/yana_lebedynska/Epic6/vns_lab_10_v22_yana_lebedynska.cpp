#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>

using namespace std;

struct Node
{
    char* data;
    Node* previous;
    Node* next;
};

//створення пустого списоку
Node* createNewList()
{
    return nullptr;
}

//додавання елеемнту в кінець списку
void add(Node* &head, const char* element)
{
    Node* newNode = new Node;
    newNode->data = new char[strlen(element) + 1];
    strcpy(newNode->data, element); //копіює рядок element в newNode->data
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        newNode->previous = nullptr;
    }
    else
    {
        Node* temporary = head;
        while (temporary->next != nullptr)
        {
            temporary = temporary->next;
        }
        temporary->next = newNode;
        newNode->previous = temporary;
    }
}

//вивести на екран весь список
void print(Node* head)
{
    if (head == nullptr)
    {
        cout << "The list is empty" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

//видалення елемента
void deleteElement(Node* &head, const char* key)
{
    Node* current = head;
    while (current != nullptr && strcmp(current->data, key) != 0)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Element with the key " << key << " isn't found!" << endl;
        return;
    }

    if (current->previous != nullptr)
    {
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

    delete[] current->data; //видалення виділеної пам'яті
    delete current; //видалення самого елемента
}

//додавання елемента перед вказаним елементом
void addKElemBeforeKey(Node* &head, const char* key, int k, const char* elements)
{
    Node* current = head;
    while (current != nullptr && strcmp(current->data, key) != 0)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Element with the key " << key << " isn't found!" << endl;
        return;
    }

    istringstream iss(elements);
    string element;
    for (int i = 0; i < k && iss >> element; ++i)
    {
        Node* newNode = new Node;
        newNode->data = new char[element.length() + 1];
        strcpy(newNode->data, element.c_str());

        if (current->previous != nullptr)
        {
            current->previous->next = newNode;
        }
        else
        {
            head = newNode;
        }

        newNode->previous = current->previous;
        newNode->next = current;

        if (current->previous != nullptr)
        {
            current->previous = newNode;
        }
    }
}

//запис списку у файл
void writeToFile(Node* head, const char* nameOfFile)
{
    ofstream file_output(nameOfFile);

    if (!file_output.is_open())
    {
        cout << "File couldn't be opened!" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr)
    {
        file_output << current->data << endl;
        current = current->next;
    }

    cout << "List is written to file '" << nameOfFile << "'" << endl;

    file_output.close();
}

//видалення цілого списку
void deleteList(Node* &head)
{
    while (head != nullptr)
    {
        Node* temporary = head;
        head = head->next;
        delete[] temporary->data;
        delete temporary;
    }
}

//перезапис списку з файлу
Node* restoreList(const char* nameOfFile)
{
    ifstream file_input(nameOfFile);
    Node* head = nullptr;

    if (!file_input.is_open())
    {
        cout << "File couldn't be opened!" << endl;
        return nullptr;
    }

    string line;
    while (getline(file_input, line))
    {
        add(head, line.c_str());
    }

    file_input.close();

    cout << "List is restored from file '" << nameOfFile << "'" << endl;

    return head;
}

int main()
{
    Node* List = createNewList();

    int operation;
    do
    {
        cout << endl;
        cout << "Choose the operation (enter a number): " << endl;
        cout << "1. Add element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Add element before another element" << endl;
        cout << "4. Print whole list" << endl;
        cout << "5. Write list to file" << endl;
        cout << "6. Restore list from file" << endl;
        cout << "7. Delete the entire list" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter the operation number -> ";
        cin >> operation;
        cin.ignore();

        switch (operation)
        {
            case 1:
            {
                cout << endl;
                cout << "Enter the element you want to add: ";
                string element;
                getline(cin, element);
                add(List, element.c_str());
                break;
            }

            case 2:
            {
                cout << endl;
                cout << "Enter the key of the element you want to delete: ";
                string key;
                getline(cin, key);
                deleteElement(List, key.c_str());
                break;
            }

            case 3:
            {
                cout << endl;
                cout << "Enter the key before which you want to add elements: ";
                string key;
                getline(cin, key);

                int k;
                cout << "Enter the number of elements you want to add: ";
                cin >> k;
                cin.ignore();

                cout << "Enter the elements you want to add: ";
                string ELEMENTS;
                getline(cin, ELEMENTS);
                addKElemBeforeKey(List, key.c_str(), k, ELEMENTS.c_str());

                break;
            }

            case 4:
            {
                cout << endl;
                cout << "Your current list: ";
                print(List);
                break;
            }

            case 5:
            {
                cout << endl;
                cout << "Enter the name of the file in which you want to write the list: ";
                string fileName;
                getline(cin, fileName);
                writeToFile(List, fileName.c_str());
                break;
            }

            case 6:
            {
                cout << endl;
                cout << "Enter the name of the file from which you want to restore the list: ";
                string fileName;
                getline(cin, fileName);
                deleteList(List); //очистити існуючий список
                List = restoreList(fileName.c_str());
                print(List);
                break;
            }

            case 7:
            {
                cout << endl;
                deleteList(List);
                List = createNewList();
                cout << "The entire list now is deleted!" << endl;
                break;
            }

            case 0:
            {
                cout << "The end of the program!" << endl;
                break;
            }

            default:
            {
                cout << endl;
                cout << "Operation not found! Try again." << endl;
                break;
            }
        }
    }
    while (operation != 0);

    deleteList(List);

    return 0;
}
