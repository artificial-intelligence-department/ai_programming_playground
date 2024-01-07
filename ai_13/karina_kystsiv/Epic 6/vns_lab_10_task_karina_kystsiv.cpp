#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class DoublyLinkedList
{
private:
    struct Node
    {
        string value;
        Node *prev;
        Node *next;

        Node(string value)
        {
            this->value = value;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };
    Node *current;
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList()
    {
        deleteList();
    }

    void printList()
    {
        Node *currentNode = head;
        if (currentNode == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            while (currentNode != nullptr)
            {
                cout << currentNode->value << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }

    void insert(string value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertHead(string value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = nullptr;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertBefore(const string &value)
    {
        if (!head)
        {
            head = new Node(value);
            tail = head;
            return;
        }

        Node *newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    void writeToFile(const string &filename)
    {
        fstream outFile;
        outFile.open(filename, ios::out | ios::trunc);
        if (!outFile)
        {
            cerr << "Unable to open the file: " << filename << endl;
            return;
        }

        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            outFile << currentNode->value << " ";
            currentNode = currentNode->next;
        }

        outFile.close();
    }

    void restoreFromFile(const string &filename)
    {
        ifstream inFile(filename);

        if (!inFile)
        {
            cerr << "Unable to open the file: " << filename << endl;
            return;
        }

        deleteList();

        string value;

        if (inFile.peek() == EOF)
        {
            cout << "The file is empty." << endl;
            return;
        }

        while (inFile >> value)
        {
            insert(value);
        }

        inFile.close();
    }

    void deleteList()
    {
        Node *currentNode = head;
        while (currentNode != nullptr)
        {
            Node *tempNode = currentNode;
            currentNode = currentNode->next;
            delete tempNode;
        }
        head = nullptr;
        tail = nullptr;
    }

    void deleteNode(string key)
    {
        Node *currentNode = head;

        while (currentNode != nullptr && currentNode->value != key)
        {
            currentNode = currentNode->next;
        }

        if (currentNode == nullptr)
        {
            cout << "Key not found in the list." << endl;
            return;
        }

        if (currentNode->prev == nullptr)
        {
            head = currentNode->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
        }
        else if (currentNode->next == nullptr)
        {
            tail = currentNode->prev;
            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }
        }
        else
        {
            currentNode->prev->next = currentNode->next;
            currentNode->next->prev = currentNode->prev;
        }

        delete currentNode;
    }

    void addKNodes(int K)
    {
        srand(time(0));
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        int len = alphabet.length();

        for (int i = 0; i < K; i++)
        {
            if (i == 0)
            {
                insertHead("node_" + to_string(i));
                current = head;
            }
            else
            {
                string value;
                int n = rand() % 10 + 1;
                for (int j = 0; j < n; j++)
                {
                    value += alphabet[rand() % len];
                }
                insertBefore("node_" + to_string(i));
            }
        }
    }
};

int main()
{
    int K;
    char *key = new char[20];
    cout << "Enter the number of nodes to add at the beginning: ";
    cin >> K;

    cout << "Enter the key to delete: ";
    cin >> key;

    DoublyLinkedList myList;

    myList.insert("first");
    myList.insert("second");
    myList.insert("third");
    myList.insert("fourth");
    myList.printList();

    myList.deleteNode(key);
    myList.printList();

    myList.addKNodes(K);
    myList.printList();

    myList.writeToFile("ineedmaxgrade.txt");
    myList.deleteList();
    myList.printList();

    myList.restoreFromFile("ineedmaxgrade.txt");
    myList.printList();

    return 0;
}
