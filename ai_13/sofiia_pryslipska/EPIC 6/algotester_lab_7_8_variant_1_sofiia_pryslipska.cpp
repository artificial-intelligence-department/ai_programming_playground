#include <iostream>
using namespace std;

class DoublyLinkedList
{
private:
    struct Node
    {
    public:
        int data;
        Node *prev;
        Node *next;
    };

    Node *head;
    Node *tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insert(int index, int N)
    {
        Node *newNode = new Node{N};//Ств новий вузол newNode зі значенням N(розмір списку)
        if (index == 0)
        {
            newNode->next = head;
            if (head != nullptr)
                head->prev = newNode;
            head = newNode;
            if (tail == nullptr)
                tail = newNode;
        }
        else if (index != size)
        {
            Node *temp = head;
            for (int i = 0; i < index - 1; ++i)//коли темп буде на потрібному індексі
            {
                temp = temp->next;
            }

        // встановлення newNode між temp та його наступником 
            newNode->next = temp->next; 
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
        else //якщо вставка в кінці списку
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        size++;
    }

    void erase(int index, int n)
    {
        Node *temp = head;

        while (index--)
        {
            temp = temp->next; //вказує на вузол, що треба видалити
        }
        while (n--)
        {
            if (temp->prev == nullptr)//чи ел. який видаляється це початок
            {
                head = temp->next;
            }
            else
            {
                temp->prev->next = temp->next;
            }
            if (temp->next == nullptr)//чи останній
            {
                tail = temp->prev;
            }
            else
            {
                temp->next->prev = temp->prev;
            }
            Node *tmp = temp;
            temp = temp->next;
            delete tmp;
            size--;
        }
    }

    int getsize() const
    {
        return size;
    }

    int get(int index) const
    {//перевірка чи індекс в межах діапазону
        if (index < 0 || index >= size)
            return -1;

        Node *temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    void set(int index, int value)
    {
        if (index < 0 || index >= size)
            return;

        Node *temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        temp->data = value;
    }

    void print() const
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    int Q;
    cin >> Q;

    DoublyLinkedList list;

    for (int k = 0; k < Q; k++)
    {
        string request;
        cin >> request;

        if (request == "insert")
        {
            int index, N;
            cin >> index >> N;
            int arr[N];
            for (int i = 0; i < N; i++)
            {
                cin >> arr[i];
            }
            for (int i = N - 1; i >= 0; i--)
            {
                list.insert(index, arr[i]);
            }
        }
        else if (request == "erase")
        {
            int index, n;
            cin >> index >> n;
            list.erase(index, n);
        }
        else if (request == "size")
        {
            cout << list.getsize() << endl;
        }
        else if (request == "get")
        {
            int index;
            cin >> index;
            int value = list.get(index);
            if (value != -1)
                cout << value << endl;
        }
        else if (request == "set")
        {
            int index, value;
            cin >> index >> value;
            list.set(index, value);
        }
        else if (request == "print")
        {
            list.print();
        }
    }

    return 0;
}
