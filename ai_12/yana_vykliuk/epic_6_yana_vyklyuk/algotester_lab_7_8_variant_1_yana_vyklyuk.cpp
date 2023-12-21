#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node
{
    public:
    T data;
    Node* next;
    Node* previous;

    Node(T value) : data(value), next(nullptr), previous(nullptr)
    {

    }
};

template <typename T>
class List
{
    private:
    Node<T>* head;
    Node<T>* tail;
    int count;

    public:
    List() : head(nullptr), tail(nullptr), count(0)
    {

    }

    T get(int index)
    {
        Node<T>* current = head;

        for(int i = 0; i < index && current; ++i)
        {
            current = current -> next;
        }

        if(current)
        {
            return current -> data;
        }

        return T();
    }
    
    void insert(int index, int N, T*elements)
    {
        Node<T>* new_node;
        Node<T>* current = head;

        for(int i = 0; i < index && current; ++i)
        {
            current = current -> next;
        }

        for(int i = 0; i < N; ++i)
        {
            new_node = new Node<T> (elements[i]);

            if(!head)
            {
                head = tail = new_node;
            }
            else
            {
                if(current)
                {
                    new_node -> next = current;
                    new_node -> previous = current -> previous;
                    current -> previous = new_node;

                    if(new_node -> previous)
                    {
                        new_node -> previous -> next = new_node;
                    }
                    else
                    {
                        head = new_node;
                    }
                }
                else
                {
                    tail -> next = new_node;
                    new_node -> previous = tail;
                    tail = new_node;   
                }
            }

            if(current)
            {
                current = new_node -> next;
            }
            count++;
        }
    };

    void print()
    {
        Node<T>* current = head;

        while(current)
        {
            cout << current -> data << " ";
            current = current -> next;
        }

        cout << endl;
    };

    void erase(int index, int n)
    {
        Node<T>* current = head;

        for(int i = 0; i < index; ++i)
        {
            current = current -> next;
        }

        for(int i = 0; i < n && current; ++i)
        {
            Node<T>* next_node = current -> next;
            Node<T>* previous_node = current -> previous;
            
            if(previous_node)
            {
                previous_node -> next = next_node;
            }
            else
            {
                head = next_node;
            }

            if(next_node)
            {
                next_node -> previous = previous_node;
            }
            else
            {
                tail = next_node;
            }

            delete current;
            current = next_node;
        }
        count -= n;
    }

    void set(int index, T element)
    {
        Node<T>* current = head;
        
        for(int i = 0; i < index && current; ++i)
        {
            current = current -> next;
        }

        if(current)
        {
            current -> data = element;
        }
    };

    int size()
    {
        return count;
    };
};

int main()
{
    int Q;
    cin >> Q;
    List<int> new_list;

    for(int commands = 0; commands < Q; commands++)
    {
        string option;
        cin >> option;

        if(option == "insert")
        {
            int index, N;
            cin >> index >> N;

            int* elements = new int[N];
        
            for(int i = 0; i < N; ++i)
            {
                cin >> elements[i];
            }

            new_list.insert(index, N, elements);
            delete[] elements;
        }

        if(option == "print")
        {
            new_list.print();
        }

        if(option == "get")
        {
            int index;
            cin >> index;
            cout << new_list.get(index) << endl;
        }

        if(option == "erase")
        {
            int index, n;
            cin >> index >> n;
            new_list.erase(index, n);
        }

        if(option == "set")
        {
            int index, element;
            cin >> index >> element;
            new_list.set(index, element);
        }

        if(option == "size")
        {
            cout << new_list.size() << endl;
        }
    }
    
    return 0;
}
