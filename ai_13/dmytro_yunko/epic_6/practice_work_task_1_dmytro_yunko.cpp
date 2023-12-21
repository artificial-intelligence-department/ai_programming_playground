#include <iostream>

using namespace std;

namespace list 
{
    class List; 

    struct Node 
    {
        int data; 
        Node *next; 

        Node(int value) : data(value), next(nullptr) {} 


        friend class List; 
    };

    class List 
    {
    private:
        Node *head; 

    public:
        List() : head(nullptr) {} 

        ~List() 
        {
            clear(); 
        }

        void append(int value) 
        {
            Node *newNode = new Node(value); 

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
        head=prev;
   
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

        friend ostream &operator<<(ostream &os, const List &list) 
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
                    os << current->data << " "; 
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
    using namespace list; 

    int n; 
    do 
    {
        cout << "Enter amount of nodes: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "Amount of nodes must be over zero." << endl;
        }
    } while (n <= 0);

    cout << "Enter values: ";
    List list; 
    for (int i = 0; i < n; i++) 
    {
        int value; 
        cin >> value;
        list.append(value); 
    }

    cout << "Original list: " << list; 

    list.reverse();


    
    cout << "Reversed list: "<<list  ; 
    
    return 0;
}
