#include <iostream>

using namespace std;

namespace linkedlist 
{
    class LinkedList; 

    struct Node 
    {
        int value; 
        Node *next; 

        Node(int val) : value(val), next(nullptr) {} 

        friend class LinkedList; 
    };

    class LinkedList 
    {
    private:
        Node *head; 

    public:
        LinkedList() : head(nullptr) {} 

        ~LinkedList() 
        {
            clear(); 
        }

        void addNode(int val) 
        {
            Node *newNode = new Node(val); 

            if (head == nullptr) 
            {
                head = newNode; 
            }
            else 
            {
                Node *temp = head; 
                while (temp->next != nullptr) 
                {
                    temp = temp->next; 
                }
                temp->next = newNode; 
            }
        }

        void reverse() 
        {
            Node* prev = nullptr;
            Node* current = head;
            Node* next = nullptr;

            while (current != nullptr) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }

        void clear() 
        {
            Node *current = head; 
            while (current != nullptr) 
            {
                Node *temp = current; 
                current = current->next; 
                delete temp; 
            }
            head = nullptr; 
        }

        friend ostream &operator<<(ostream &os, const LinkedList &list) 
        {
            Node *current = list.head; 
            if (current == nullptr) 
            {
                os << "List is empty" << endl;
            }
            else 
            {
                while (current != nullptr) 
                {
                    os << current->value << " "; 
                    current = current->next; 
                }
                os << endl;
            }
            return os; 
        }
    };
}

int main()
{
    using namespace linkedlist; 

    int numNodes; 
    do 
    {
        cout << "Enter the number of nodes: ";
        cin >> numNodes;
        if (numNodes <= 0)
        {
            cout << "Number of nodes must be greater than zero." << endl;
        }
    } while (numNodes <= 0);

    cout << "Enter values: ";
    LinkedList list; 
    for (int i = 0; i < numNodes; i++) 
    {
        int val; 
        cin >> val;
        list.addNode(val); 
    }

    cout << "Original list: " << list; 

    list.reverse();

    cout << "Reversed list: " << list; 
    
    return 0;
}
