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

    bool compare(Node *h1, Node *h2)
    {
        while (h1 != nullptr && h2 != nullptr)
        {
            if (h1->data != h2->data)
            {
                return false;
            }
            h1 = h1->next;
            h2 = h2->next;
        }

        if (h1 != nullptr || h2 != nullptr)
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
    LinkedList linkedList1;
    linkedList1.addNode(1);
    linkedList1.addNode(2);
    linkedList1.addNode(3);

    LinkedList linkedList2;
    linkedList2.addNode(1);
    linkedList2.addNode(2);
    linkedList2.addNode(3);

    std::cout << "List 1: ";
    linkedList1.printList();

    std::cout << "List 2: ";
    linkedList2.printList();

    std::cout << "Result: " << std::boolalpha << linkedList1.compare(linkedList1.getHead(), linkedList2.getHead()) << "\n";

    return 0;
}
