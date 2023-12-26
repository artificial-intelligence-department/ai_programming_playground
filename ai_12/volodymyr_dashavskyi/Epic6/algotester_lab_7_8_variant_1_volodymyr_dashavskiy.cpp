#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node *previous;

    Node(T value) : data(value), next(nullptr), previous(nullptr)
    {
    }
};

template <typename T>
class List
{
private:
    Node<T> *head;
    Node<T> *tail;
    int counter;

public:
    List() : head(nullptr), tail(nullptr), counter(0)
    {
    }

    T get(int number)
    {
        Node<T> *currentnumber = head;

        for (int i = 0; i < number && currentnumber; ++i)
        {
            currentnumber = currentnumber->next;
        }

        if (currentnumber)
        {
            return currentnumber->data;
        }

        return T();
    }

    void insert(int number, int N, T *elements)
    {
        Node<T> *new_node;
        Node<T> *currentnumber = head;

        for (int i = 0; i < number && currentnumber; ++i)
        {
            currentnumber = currentnumber->next;
        }

        for (int i = 0; i < N; ++i)
        {
            new_node = new Node<T>(elements[i]);

            if (!head)
            {
                head = tail = new_node;
            }
            else
            {
                if (currentnumber)
                {
                    new_node->next = currentnumber;
                    new_node->previous = currentnumber->previous;
                    currentnumber->previous = new_node;

                    if (new_node->previous)
                    {
                        new_node->previous->next = new_node;
                    }
                    else
                    {
                        head = new_node;
                    }
                }
                else
                {
                    tail->next = new_node;
                    new_node->previous = tail;
                    tail = new_node;
                }
            }

            if (currentnumber)
            {
                currentnumber = new_node->next;
            }
            counter++;
        }
    };

    void erase(int number, int n)
    {
        Node<T> *currentnumber = head;

        for (int i = 0; i < number; ++i)
        {
            currentnumber = currentnumber->next;
        }

        for (int i = 0; i < n && currentnumber; ++i)
        {
            Node<T> *next_node = currentnumber->next;
            Node<T> *previous_node = currentnumber->previous;

            if (previous_node)
            {
                previous_node->next = next_node;
            }
            else
            {
                head = next_node;
            }

            if (next_node)
            {
                next_node->previous = previous_node;
            }
            else
            {
                tail = next_node;
            }

            delete currentnumber;
            currentnumber = next_node;
        }
        counter -= n;
    }

    void set(int number, T element)
    {
        Node<T> *currentnumber = head;

        for (int i = 0; i < number && currentnumber; ++i)
        {
            currentnumber = currentnumber->next;
        }

        if (currentnumber)
        {
            currentnumber->data = element;
        }
    };
    void print()
    {
        Node<T> *currentnumber = head;

        while (currentnumber)
        {
            cout << currentnumber->data << " ";
            currentnumber = currentnumber->next;
        }

        cout << endl;
    };

    int size()
    {
        return counter;
    };
};

int main()
{
    int Q;
    cin >> Q;
    List<int> listofnumbers;

    for (int commands = 0; commands < Q; commands++)
    {
        string option;
        cin >> option;

        if (option == "insert")
        {
            int number, N;
            cin >> number >> N;

            int *elements = new int[N];

            for (int i = 0; i < N; ++i)
            {
                cin >> elements[i];
            }

            listofnumbers.insert(number, N, elements);
            delete[] elements;
        }

        else if (option == "print")
        {
            listofnumbers.print();
        }

        else if (option == "get")
        {
            int number;
            cin >> number;

            cout << listofnumbers.get(number) << endl;
        }

        else if (option == "erase")
        {
            int number, n;
            cin >> number >> n;
            listofnumbers.erase(number, n);
        }

        else if (option == "set")
        {
            int number, element;
            cin >> number >> element;

            listofnumbers.set(number, element);
        }

        else if (option == "size")
        {
            cout << listofnumbers.size() << endl;
        }
        else
        {

            cout << "Wrong input!" << endl;
        }
    }

    return 0;
}