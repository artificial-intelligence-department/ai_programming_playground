#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node *prev;

    Node(string value, Node *nextNode = nullptr, Node *prevNode = nullptr)
        : data(std::move(value)), next(nextNode), prev(prevNode) {}
};

class DoubleLinkedList
{
    Node *head;
    Node *tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void addElement(string value)
    {
        Node *newNode = new Node(value, nullptr, tail);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void addElementAfter(string value, string after)
    {
        Node *current = findNode(after);

        if (current)
        {
            Node *newNode = new Node(value, current->next, current);
            if (current->next)
            {
                current->next->prev = newNode;
            }
            current->next = newNode;
            if (current == tail)
            {
                tail = newNode;
            }
        }
    }

    void printList() const
    {
        Node *current = head;
        while (current)
        {
            cout << current->data << ' ';
            current = current->next;
        }
        cout << '\n';
    }

    void deleteNodes(int amount)
    {
        Node *current = tail;
        while (current && amount > 0)
        {
            Node *prev = current->prev;
            if (prev)
            {
                prev->next = nullptr;
            }
            delete current;
            current = prev;
            --amount;
        }
        tail = current;
    }

    void removeList()
    {
        Node *current = head;
        while (current)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }

    void copyToFile(string filename) const
    {
        ofstream file(filename);
        Node *current = head;
        while (current)
        {
            file << current->data << endl;
            current = current->next;
        }
        file.close();
    }

    void copyFromFile(string filename)
    {
        ifstream file(filename);
        string value;
        while (file >> value)
        {
            addElement(value);
        }
        file.close();
    }

private:
    Node *findNode(const string &value) const
    {
        Node *current = tail;
        while (current && current->data != value)
        {
            current = current->prev;
        }
        return current;
    }
};

int main()
{
    DoubleLinkedList list;

    int numberOfElements;

    cout << "Enter the number of elements you want to add: \n";
    cin >> numberOfElements;
    cout << "Enter those elements: \n";

    for (; numberOfElements; numberOfElements--)
    {
        string word = "";
        cin >> word;
        list.addElement(word);
    }
    bool continueFlag = true;

    while (continueFlag)
    {
        string nextMove;
        cout << "\nEnter what you want to do next \n Options:\n print \tdeleteNodes \taddElementAfter \tCopyToFile \tCopyFromFile \tremoveList \tEnd\n";
        cin >> nextMove;
        if (nextMove == "print" || nextMove == "Print")
        {
            list.printList();
        }
        else if (nextMove == "DeleteNodes" || nextMove == "deleteNodes")
        {
            cout << "Enter the amount of numbers you want to delete from back\n";
            int index;
            cin >> index;
            list.deleteNodes(index);
        }
        else if (nextMove == "addElementAfter" || nextMove == "AddElementAfter")
        {
            string after;
            cout << "Enter after which element you would like to add another element\n";
            cin >> after;
            string word;
            cout << "Enter which element you would like to insert\n";
            cin >> word;
            list.addElementAfter(word, after);
        }
        else if (nextMove == "CopyToFile" || nextMove == "copyToFile")
        {
            list.copyToFile("strings.txt");
        }
        else if (nextMove == "CopyFromFile" || nextMove == "copyFromFile")
        {
            list.copyFromFile("strings.txt");
        }
        else if (nextMove == "removeList" || nextMove == "RemoveList")
        {
            list.removeList();
        }
        else if (nextMove == "end" || nextMove == "End")
        {
            continueFlag = false;
        }
        else
        {
            cout << "You wrote the wrong word, try again";
        }
    }

    return 0;
}
