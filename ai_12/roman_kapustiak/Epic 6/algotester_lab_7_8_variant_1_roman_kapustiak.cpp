#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
   T data;
   struct Node *previous;
   struct Node *next;

    Node()
    {
        data = 0;
        next = NULL;
        previous = NULL;
    }
    Node(T n, Node *prev)
    {
        data = n;
        next = NULL;
        previous = prev;
    }
};

template <class T>
class DoublyLinkedList
{
private:
    Node<T> *head;
public:
    DoublyLinkedList() {head = NULL;}
    void insert();
    void erase();
    T get();
    void set();
    int size();
    template <class U>
    friend ostream& operator<<(ostream&, const DoublyLinkedList<U>& );
};

template <class T>
void DoublyLinkedList<T>::insert()
{
    int index, N;
    T data;
    cin >> index >> N;
    Node<T> *current = head;
    Node<T> *prev = NULL;

    for(int i = 0; i < index; i++)
    {
        prev = current;
        current = current->next;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> data;
        if (prev)
        {
            prev->next = new Node<T>(data, prev);
            prev = prev->next;
        }
        else
        {
            head = new Node<T>(data, prev);
            prev = head;
        }        
    }

    if(current)
    {
        prev->next = current;
        current->previous = prev;
    }

    return;
}
template <class T>
void DoublyLinkedList<T>::erase()
{
    int index, n;

    cin >> index >> n;
    Node<T> *prev = NULL;
    Node<T> *current = head;
    Node<T> *temp;

    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    prev = current->previous;

    for (int i = 0; i < n; i++)
    {
        temp = current->next;
        delete current;
        current = temp;
    }

    if(prev)
    {
        prev->next = current;
    }
    else
    {
        head = current;
    }
    if(current)
    {
        current->previous = prev;
    }

    return;
}
template <class T>
T DoublyLinkedList<T>::get()
{   
    int index;
    cin >> index;
    Node<T> *temp = head;

    while(index--)
    {
        temp = temp->next;
    }
    
    return temp->data;
}
template <class T>
void DoublyLinkedList<T>::set()
{
    int index;
    T data;
    cin >> index >> data;
    Node<T> *temp = head;

    while(index--)
    {
        temp = temp->next;
    }

    temp->data = data;
    return;
}
template <class T>
int DoublyLinkedList<T>::size()
{
    int length = 0;
    Node<T> *temp = head;

    while(temp)
    {
        length++;
        temp = temp->next;
    }

    return length;
}
template <class T>
ostream & operator << (ostream &out, const DoublyLinkedList<T> &list)
{
    Node<T> *temp = list.head;

    while(temp)
    {
        out << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return out;
}

int main()
{
    DoublyLinkedList <int>dll;
    int Q;
    string request;
    cin >> Q;

    while(Q--)
    {
        cin >> request;

        if(request == "insert")
        {
            dll.insert();
        }
        else if(request == "erase")
        {
            dll.erase();
        }
        else if(request == "size")
        {
            cout << dll.size() << endl;
        }
        else if(request == "get")
        {
            cout << dll.get() << endl;
        }
        else if(request == "set")
        {
            dll.set();
        }
        else if(request == "print")
        {
            cout << dll;
        }
        else
        {
            cout << "Wrong input!\n";
        }
    }

    return 0;
}
