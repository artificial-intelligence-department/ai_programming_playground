#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *nextnumber;

    Node(int value) : data(value), nextnumber(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void insertNode(int value)
    {
        Node *newNode = new Node(value);
        newNode->nextnumber = head;
        head = newNode;
    }

    void reverseList()
    {
        Node *previousnumber = nullptr;
        Node *currentnumber = head;
        Node *nextnumber = nullptr;

        while (currentnumber != nullptr)
        {
            nextnumber = currentnumber->nextnumber;
            currentnumber->nextnumber = previousnumber;
            previousnumber = currentnumber;
            currentnumber = nextnumber;
        }

        head = previousnumber;
    }

    void displayList() const
    {
        Node *currentnumber = head;
        while (currentnumber != nullptr)
        {
            cout << currentnumber->data << " ";
            currentnumber = currentnumber->nextnumber;
        }
        cout << "\n";
    }

    bool Equal(Node *first, Node *second)
    {
        while (first != nullptr && second != nullptr)
        {
            if (first->data != second->data)
            {
                return false;
            }
            first = first->nextnumber;
            second = second->nextnumber;
        }

        if (first != nullptr || second != nullptr)
        {
            return false;
        }

        return true;
    }

    Node *getHead() const
    {
        return head;
    }
};

int main()
{
    LinkedList list1;
    list1.insertNode(5);
    list1.insertNode(2);
    list1.insertNode(7);

    LinkedList list2;
    list2.insertNode(5);
    list2.insertNode(2);
    list2.insertNode(7);

    cout << "First list of numbers: ";
    list1.displayList();

    cout << "Secind list of numbers: ";
    list2.displayList();

    cout << "Result of equality: " << boolalpha << list1.Equal(list1.getHead(), list2.getHead()) << "\n";

    return 0;
}
