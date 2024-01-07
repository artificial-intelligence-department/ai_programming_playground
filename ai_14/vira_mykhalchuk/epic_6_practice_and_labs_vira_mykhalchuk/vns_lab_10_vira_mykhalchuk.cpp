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

Node* createNewList()
{
    return nullptr;
}

void add(Node* &head, const char* element)
{
    Node* newNode = new Node;
    newNode->data = new char[strlen(element) + 1];
    strcpy(newNode->data, element);
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

    delete[] current->data;
    delete current;
}

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

    string action;
    do
    {
        cout << endl;
        cout << "Choose the operation (enter an action): " << endl;
        cout << "1. To add element write: \"add element\"" << endl;
        cout << "2. To delete element write: \"delete element\"" << endl;
        cout << "3. To add element before another element write: \"add before\"" << endl;
        cout << "4. To print the whole list write: \"print\"" << endl;
        cout << "5. To write list to file write: \"write\"" << endl;
        cout << "6. To restore list from file write: \"restore list\"" << endl;
        cout << "7. T delete the entire list write: \"delete list\"" << endl;
        cout << "0. To exit write: \"exit\"" << endl;

        cout << "Enter the action -> ";
        getline(cin, action);

        if (action == "add element")
        {
            cout << "Enter the element you want to add: ";
            string element;
            getline(cin, element);
            add(List, element.c_str());
        }
        else if (action == "delete element")
        {
            cout << "Enter the key of the element you want to delete: ";
            string key;
            getline(cin, key);
            deleteElement(List, key.c_str());
        }
        else if (action == "add before")
        {
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
        }
        else if (action == "print")
        {
            cout << "Your current list: ";
            print(List);
        }
        else if (action == "write")
        {
            cout << "Enter the name of the file in which you want to write the list: ";
            string fileName;
            getline(cin, fileName);
            writeToFile(List, fileName.c_str());
        }
        else if (action == "restore list")
        {
            cout << "Enter the name of the file from which you want to restore the list: ";
            string fileName;
            getline(cin, fileName);
            deleteList(List);
            List = restoreList(fileName.c_str());
            print(List);
        }
        else if (action == "delete list")
        {
            deleteList(List);
            List = createNewList();
            cout << "The entire list now is deleted!" << endl;
        }
        else if (action != "exit")
        {
            cout << "Action not found! Try again." << endl;
        }

    } while (action != "exit");

    deleteList(List);

    return 0;
}