#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *end;
    int size;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        end = nullptr;
        size = 0;
    }
    ~DoublyLinkedList()
    {
        Node *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    

   void insert(int index, std::vector<int>& list) {
    
    Node* current = head;
    Node* prevNode = nullptr;
    for (int i = 0; i < index; ++i) {
        prevNode = current;
        current = current->next;
    }

    for (int i = 0; i < list.size(); ++i) {
        Node* newNode = new Node;
        newNode->value = list[i];
        newNode->prev = prevNode;
        newNode->next = current;
        if (prevNode) {
            prevNode->next = newNode;
        } else {
            head = newNode; 
        }
        if (current) {
            current->prev = newNode;
        } else {
            end = newNode; 
        }
        prevNode = newNode;
        ++size;
    }
} 

    void erase(int index, int n) {
    

    Node* current = head;
    Node* prevNode = nullptr;
    for (int i = 0; i < index; ++i) {
        prevNode = current;
        current = current->next;
    }

    for (int i = 0; i < n; ++i) {
        if (current == nullptr) {
            break;
        }
        Node* nextNode = current->next;
        if (prevNode) {
            prevNode->next = nextNode;
        } else {
            head = nextNode;
        }
        if (nextNode) {
            nextNode->prev = prevNode;
        } else {
            end = prevNode;
        }
        delete current;
        current = nextNode;
        --size;
    }
}


    int getSize()
    {
        return size;
    }

    int get(int index)
    {
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current->value;
    }

    void set(int index, int value)
    {
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        current->value = value;
    }
    

    ostream& operator<<(ostream &os)
    {
        Node *current = head;
        while (current != nullptr)
        {
            os << current->value << ' ';
            current = current->next;
        }
        return os;
    }
};

int main()
{
    DoublyLinkedList list;

    int Q;

    cin >> Q;
    cin.ignore();

    string identifier ;

    for (size_t i = 0; i < Q; i++)
    {

        cin >> identifier;

        if (identifier == "insert")
        {
            int index{0}, N{0};
            vector<int> ar;
            cin >> index >> N;
            for (size_t i = 0; i < N; i++)
            {
                int a;
                cin >> a;
                ar.push_back(a);
            }
            list.insert(index, ar);
        }
        if (identifier == "erase")
        {
            int index{0}, n{0};
            cin >> index >> n;
            list.erase(index, n);
        }
        if (identifier == "size")
        {
            cout << list.getSize() << endl;
        }
        if (identifier == "get")
        {
            int index{0};
            cin >> index;
            cout<<list.get(index)<<endl;
        }
        if (identifier == "set")
        {
            int index{0}, newValue{0};
            cin >> index >> newValue;
            list.set(index, newValue);
        }
        if (identifier == "print")
        {
            
            list<<cout<<endl;
        }
    }

   
    return 0;
}