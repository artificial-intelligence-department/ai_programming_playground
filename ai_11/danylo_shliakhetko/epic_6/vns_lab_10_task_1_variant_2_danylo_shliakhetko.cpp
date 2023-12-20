#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const string PATH = "C:/files/university/programming-paradigms/data/linkedList.txt";

class LinkedList
{
    class Node
    {
    public:
        int data;
        Node *next;
    };

private:
    Node *tail;
    Node *head;
    int size = 0;

public:
    int getSize()
    {
        return size;
    }
    Node *getNodeByIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return NULL;
        }
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current;
    }

    void addElementByIndex(int value, int index)
    {
        Node *node = new Node();
        node->data = value;
        node->next = NULL;

        if (node == NULL || index > size || index < 0)
        {
            return;
        }
        if (size == 0)
        {
            head = node;
            tail = node;
        }
        else if (index == 0)
        {
            node->next = head;
            head = node;
        }
        else if (index == size)
        {
            tail->next = node;
            tail = node;
        }
        else
        {
            Node *current = getNodeByIndex(index - 1);
            node->next = current->next;
            current->next = node;
        }
        size++;
    }

    void removeElementByIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        if (index == 0)
        {
            head = head->next;
        }

        Node *node = getNodeByIndex(index);
        Node *previousNode = getNodeByIndex(index - 1);

        if (index == size - 1)
        {
            tail = previousNode;
            tail->next = NULL;
        }
        else
        {
            previousNode->next = node->next;
        }

        delete node;
        --size;
    }

    void addRandomElementByIndex(int index)
    {
        addElementByIndex(rand() % 100, index);
    }

    void createRandomElementsList(int size)
    {
        for (int i = 0; i < size; i++)
        {
            addRandomElementByIndex(i);
        }
    }

    void print(Node *n)
    {
        if (n == NULL)
        {
            return;
        }
        cout << n->data << " ";
    }

    void printList(Node *n)
    {
        if (size == 0)
        {
            cout << "List is empty\n";
            return;
        }
        if (n == NULL)
        {
            cout << "\n";
            return;
        }
        print(n);
        printList(n->next);
    };

    void printList()
    {
        printList(head);
    }

    void deleteFromSomeNumber(int index, int k)
    {
        for (int i = 0; i < k; i++)
        {
            removeElementByIndex(index);
        }
    }

    void addFromSomeNumber(int index, int k)
    {
        for (int i = 0; i < k; i++)
        {
            addRandomElementByIndex(index + i);
        }
    }

    void writeToFile(string path)
    {
        Node *n = head;

        ofstream deleteFile(path, ios::trunc);
        deleteFile.close();

        ofstream writeFile;
        writeFile.open(path, ios_base::app);
        if (!writeFile)
        {
            return;
        }

        while (n != NULL)
        {
            writeFile << n->data << "\n";
            n = n->next;
        }
        writeFile.close();
    }

    void deleteList()
    {
        while (head != NULL)
        {
            Node *next = head->next;
            delete head;
            head = next;
            size--;
        }
    }

    void readFromFile(string path)
    {
        string currentLine;
        ifstream readFile;
        readFile.open(path, ios_base::app);
        if (!readFile)
        {
            return;
        }
        int i = 0;
        while (getline(readFile, currentLine))
        {
            int parsedOutput = stoi(currentLine);
            addElementByIndex(parsedOutput, i);
            i++;
        }
        readFile.close();
    }
};

main()
{
    int from;
    int k;
    LinkedList list;
    srand(time(0));

    cout << "Create List:\n";
    list.createRandomElementsList(10);
    list.printList();

    cout << "Enter from which element start deleting:\n";
    cin >> from;
    cout << "Enter number of elements to delete:\n";
    cin >> k;

    cout << "Delete elements from List:\n";
    list.deleteFromSomeNumber(from, k);
    list.printList();

    cout << "Enter from which element start adding:\n";
    cin >> from;
    cout << "Enter number of elements to add:\n";
    cin >> k;

    cout << "Add elements to List:\n";
    list.addFromSomeNumber(from, k);
    list.printList();

    cout << "Write List to file:\n";
    list.writeToFile(PATH);

    cout << "Delete List:\n";
    list.deleteList();
    list.printList();

    cout << "Read List from file:\n";
    list.readFromFile(PATH);
    list.printList();

    return 0;
}