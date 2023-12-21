#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void addNode(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void printList() const
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};

int main()
{
    LinkedList linkedList;

    linkedList.addNode(1);
    linkedList.addNode(2);
    linkedList.addNode(3);
    linkedList.addNode(4);
    linkedList.addNode(5);

    std::cout << "Original List: ";
    linkedList.printList();

    linkedList.reverse();

    std::cout << "Reversed list: ";
    linkedList.printList();

    return 0;
}
