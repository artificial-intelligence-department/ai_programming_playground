#include <iostream>
#include <ctime>
using namespace std;

struct Node
{
    int Value;
    Node *Previous;
    Node *Next;

    Node(int value)
    {
        Value = value;
        Previous = NULL;
        Next = NULL;
    }
};

class Linked_list
{
    Node *start;
    Node *end;

public:
    Linked_list()
    {
        start = end = NULL;
    }

    void add(int value)
    {
        Node *newNode = new Node(value);
        if (!start)
            start = end = newNode;
        else
        {
            end->Next = newNode;
            newNode->Previous = end;
            end = newNode;
        }
    }

    void Delete(int token)
    {
        Node *node = start;
        while (node != NULL)
        {
            if (node->Value == token)
            {
                if (node->Previous)
                    node->Previous->Next = node->Next;
                else
                    start = node->Next;

                if (node->Next)
                    node->Next->Previous = node->Previous;
                else
                    end = node->Previous;

                delete node;
                break;
            }
            node = node->Next;
        }
    }

    void AddBeforeToken(int token, int count)
    {
        Node *node = start;
        while (node)
        {
            if (node->Value == token)
            {
                for (int i = 0; i < count; ++i)
                {
                    Node *newNode = new Node(0);
                    newNode->Next = node;
                    newNode->Previous = node->Previous;

                    if (node->Previous)
                        node->Previous->Next = newNode;
                    else
                        start = newNode;

                    node->Previous = newNode;
                }
                break;
            }

            node = node->Next;
        }
    }

    void Print()
    {
        Node *node = start;
        while (node)
        {
            cout << node->Value << " ";
            node = node->Next;
        }
        cout << "\n";
    }

    Node *GetNode(int Position)
    {
        Node *node = start;
        for (int i = 0; i < Position && node != NULL; i++)
            node = node->Next;
        return node;
    }
};

int main()
{
    Linked_list list;
    srand(time(0));

    for (int j = 0; j < 10; j++)
    {
        list.add(rand() % 20 + 1);
    }

    cout << "List: ";
    list.Print();

    list.Delete(list.GetNode(5)->Value);
    cout << "List: ";
    list.Print();

    list.AddBeforeToken(list.GetNode(7)->Value, 7);
    cout << "List: ";
    list.Print();

    return 0;
}