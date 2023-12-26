#include <iostream>
using namespace std;

template <class ownType>
class Node
{
public:
    ownType parameter;
    Node *back;
    Node *next;

    Node() : parameter(0), back(nullptr), next(nullptr) {}
    Node(ownType n, Node *prev) : parameter(n), back(prev), next(nullptr) {}
};

template <class ownType>
class List
{
private:
    Node<ownType> *head;

public:
    List() : head(nullptr) {}

    void insert()
    {
        long long index, N;
        ownType parameter;

        cin >> index >> N;

        Node<ownType> *current = head;
        Node<ownType> *prev = nullptr;

        for (long long i = 0; i < index; i++)
        {
            prev = current;
            current = current->next;
        }

        for (long long i = 0; i < N; i++)
        {
            cin >> parameter;
            Node<ownType> *newNode = new Node<ownType>(parameter, prev);
            if (prev)
            {
                prev->next = newNode;
            }
            else
            {
                head = newNode;
            }
            prev = newNode;
        }

        if (current)
        {
            prev->next = current;
            current->back = prev;
        }
    }

    void erase()
    {
        long long index, n;

        cin >> index >> n;

        Node<ownType> *prev = nullptr;
        Node<ownType> *current = head;
        Node<ownType> *randomptr;

        for (long long i = 0; i < index; i++)
        {
            current = current->next;
        }
        prev = current->back;

        for (long long i = 0; i < n; i++)
        {
            randomptr = current->next;
            delete current;
            current = randomptr;
        }

        if (prev)
        {
            prev->next = current;
        }
        else
        {
            head = current;
        }
        if (current)
        {
            current->back = prev;
        }
    }

    ownType get() const
    {
        long long index;
        cin >> index;

        Node<ownType> *randomptr = head;

        for (long long i = 0; i < index; i++)
        {
            randomptr = randomptr->next;
        }

        return randomptr->parameter;
    }

    void set()
    {
        long long index;
        ownType parameter;
        cin >> index >> parameter;

        Node<ownType> *randomptr = head;

        for (long long i = 0; i < index; i++)
        {
            randomptr = randomptr->next;
        }

        randomptr->parameter = parameter;
    }

    long long size() const
    {
        long long length = 0;
        Node<ownType> *randomptr = head;

        for (long long i = 0; randomptr != nullptr; i++)
        {
            randomptr = randomptr->next;
            ++length;
        }

        return length;
    }

    void print() const
    {
        Node<ownType> *randomptr = head;

        for (long long i = 0; randomptr != nullptr; i++)
        {
            cout << randomptr->parameter << " ";
            randomptr = randomptr->next;
        }
        cout << endl;
    }
};

int main()
{
    List<long long> selfcont;
    long long q;
    string input;

    cin >> q;

    for (long long i = 0; i < q; i++)
    {
        cin >> input;

        if (input == "insert")
        {
            selfcont.insert();
        }
        else if (input == "erase")
        {
            selfcont.erase();
        }
        else if (input == "size")
        {
            cout << selfcont.size() << endl;
        }
        else if (input == "get")
        {
            cout << selfcont.get() << endl;
        }
        else if (input == "set")
        {
            selfcont.set();
        }
        else if (input == "print")
        {
            selfcont.print();
        }
    }

    return 0;
}