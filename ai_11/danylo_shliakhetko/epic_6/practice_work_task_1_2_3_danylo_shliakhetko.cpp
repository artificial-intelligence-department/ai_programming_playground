#include <iostream>
using namespace std;

class ReverseList
{
    class Node
    {
    public:
        int data;
        Node *next;
        Node *previous;
    };

private:
    Node *tail;
    Node *head;
    int size = 0;

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
            head->previous = node;
            head = node;
        }
        else if (index == size)
        {
            node->previous = tail;
            tail->next = node;
            tail = node;
        }
        else
        {
            Node *current = getNodeByIndex(index - 1);
            node->previous = current;
            node->next = current->next;
            current->next->previous = node;
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

    void addRandomDigitByIndex(int index)
    {
        addElementByIndex(rand() % 10, index);
    }

    void print(Node *n)
    {
        if (n == NULL)
        {
            return;
        }
        cout << n->data << " ";
    }

    void printNumber(Node *n)
    {
        if (n == NULL)
        {
            return;
        }
        cout << n->data;
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

    void printNumberList(Node *n)
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
        printNumber(n);
        printNumberList(n->previous);
    };

    void printReversedList(Node *n)
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
        printReversedList(n->previous);
    };

    void reverse()
    {
        Node *current = head;
        swap(head, tail);
        Node *temp = NULL;
        while (current != NULL)
        {
            temp = current->next;
            current->next = current->previous;
            current->previous = temp;

            current = temp;
        }
    }

    bool compare(Node *h1, Node *h2)
    {

        while (h1->next != NULL || h2->next != NULL)
        {
            if (h1->data != h2->data)
            {
                return false;
            }

            h1 = h1->next;
            h2 = h2->next;
        }

        if (h1->next != h2->next)
            return false;
        return true;
    }

    Node *getHead()
    {
        return head;
    }

    ReverseList sum(Node *h1, Node *h2, ReverseList answer)
    {

        int index = 0;
        int intBuffer = 0;
        Node *a = h1;
        Node *b = h2;

        while (a != nullptr && b != nullptr)
        {
            int s = b->data + a->data + intBuffer;

            if ((s) < 10)
            {
                answer.addElementByIndex(s, index);
                intBuffer = 0;
            }
            else
            {
                answer.addElementByIndex(s - 10, index);
                intBuffer = 1;
            }
            a = a->next;
            b = b->next;
            index++;
        }
        if (intBuffer)
        {
            answer.addElementByIndex(intBuffer, index);
        }
        return answer;
    }

public:
    int getSize()
    {
        return size;
    }

    void createRandomElementsList(int size)
    {
        for (int i = 0; i < size; i++)
        {
            addRandomElementByIndex(i);
        }
    }

    void createRandomDigitList(int size)
    {
        for (int i = 0; i < size; i++)
        {
            addRandomDigitByIndex(i);
        }
    }

    void addNewElement(int value)
    {
        addElementByIndex(value, 0);
    }

    void printList()
    {
        printList(head);
    }

    void printReversedList()
    {
        printReversedList(tail);
    }

    void printNumberList()
    {
        printNumberList(tail);
    }

    void reverseList()
    {
        reverse();
    }

    bool compareList(ReverseList list)
    {
        return compare(head, list.getHead());
    }

    ReverseList sum(ReverseList a, ReverseList b)
    {
        ReverseList c;
        return sum(a.getHead(), b.getHead(), c);
    }
};

int main()
{
    cout << "Task 1\n";
    ReverseList list;
    list.createRandomElementsList(10);
    list.printList();

    list.reverseList();
    list.printList();

    list.reverseList();
    list.printList();

    list.printReversedList();

    cout << "\nTask 2\n";

    ReverseList newList;
    newList.createRandomElementsList(10);
    newList.printList();

    cout << boolalpha;
    cout << "list and newList: " << list.compareList(newList) << endl;
    cout << "list and list: " << list.compareList(list) << endl;

    cout << "\nTask 3\n";
    ReverseList listA;
    listA.createRandomDigitList(10);

    // listA.addNewElement(3);
    // listA.addNewElement(4);
    // listA.addNewElement(6);
    // listA.addNewElement(8);

    ReverseList listB;
    listB.createRandomDigitList(10);

    // listB.addNewElement(5);
    // listB.addNewElement(7);
    // listB.addNewElement(8);
    // listB.addNewElement(8);

    listA.printNumberList();
    listB.printNumberList();

    ReverseList listC;
    listC = listC.sum(listA, listB);
    listC.printNumberList();

    return 0;
}