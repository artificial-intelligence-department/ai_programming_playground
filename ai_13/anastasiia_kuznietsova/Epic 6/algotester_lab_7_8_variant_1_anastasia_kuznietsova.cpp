#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
    T element;
    Node<T> *next;
    Node<T> *prev;
    Node<T> *head;
    Node<T> *tail;
    int size;

    Node(const T &newval) : element(newval) {}
    Node()
    {
        next = nullptr;
        prev = nullptr;
        head = nullptr;
        tail = nullptr;
        size = 0;
    };

    void insert(int index, int N, T *list)
    {
        if (index < 0 || index > size)
        {
            return;
        }

        Node<T> *newNode;
        Node<T> *current;

        for (int i = N-1; i >=0 ; i--)
        {
            newNode = new Node<T>(list[i]);
            newNode->prev = nullptr;
            newNode->next = nullptr;
            if (index == 0)
            {

                newNode->next = head;
                if (head != nullptr)
                {
                    head->prev = newNode;
                }
                head = newNode;
                if (tail == nullptr) {
                        tail = newNode;
                    }
            }
            else if (index == size)
            {
                newNode->prev = tail;
                if (tail != nullptr)
                {
                    tail->next = newNode;
                }
                tail = newNode;
                if (head == nullptr) {
                        head = newNode;
                    }
            }
            else
            {
                current = head;
                for (int j = 0; j < index - 1; ++j)
                {
                    current = current->next;
                }
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next != nullptr)
                {
                    current->next->prev = newNode;
                }
                current->next = newNode;
            }
            ++size;
        }
    }

    void erase(int index, int n)
    {
        Node *todelete = head;
        for (int i = 0; i < index; ++i)
        {
            todelete = todelete->next;
        }

        for (int i = 0; i < n; ++i)
        {
            Node<T> *nextnode = todelete->next;

            if (todelete->prev != nullptr)
            {
                todelete->prev->next = todelete->next;
            }
            else
            {
                head = todelete->next;
            }
            if (todelete->next != nullptr)
            {
                todelete->next->prev = todelete->prev;
            }
            else
            {
                tail = todelete->prev;
            }

            delete todelete;
            todelete = nextnode;
            size--;
        }
    }

    int listsize()
    {
        return size;
    }

    int getelem(int index)
    {
        if (index < 0 || index > size)
        {
            return 0;
        }
        Node *current = head;
        while (index--)
        {
            current = current->next;
        }
        return current->element;
    }

    void set(int index, T newval)
    {
        Node<T> *nchange = head;

        for (int i = 0; i < index; ++i)
        {
            nchange = nchange->next;
        }
        nchange->element = newval;
    }

    void print()
    {
        Node<T> *current = head;
        while (current)
        {
            cout << current->element << ' ';
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Node<int> task;
    int Q;
    cin >> Q;

    while (Q--)
    {
        string theword;
        cin >> theword;

        if (theword == "insert")
        {
            int index, N;
            cin >> index;
            cin >> N;
            int *list = new int[N];
            for (int i = 0; i < N; ++i)
            {
                cin >> list[i];
            }
            task.insert(index, N, list);
            delete[] list;
        }
        else if (theword == "erase")
        {
            int index, n;
            cin >> index;
            cin >> n;
            task.erase(index, n);
        }
        else if (theword == "get")
        {
            int index;
            cin >> index;
            cout << task.getelem(index) << "\n";
        }
        else if (theword == "print")
        {
            task.print();
        }
        else if (theword == "size")
        {
            cout << task.listsize() << "\n";
        }
        else if (theword == "set")
        {
            int index, newval;
            cin >> index;
            cin >> newval;
            task.set(index, newval);
        }
    }

    return 0;
}
