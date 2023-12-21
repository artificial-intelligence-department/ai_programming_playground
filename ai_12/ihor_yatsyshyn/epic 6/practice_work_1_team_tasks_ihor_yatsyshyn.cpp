#include <iostream>

using namespace std;

struct Node
{
    Node *next;
    int data;

    Node(int data) : data(data), next(nullptr) 
    {}
};

class LinkedList
{
private:
    
public:
    Node *head;

    LinkedList() : head(nullptr)
    {}

    void push_back(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            
            current->next = newNode;
        }
    }

    void print(Node *head)
    {
        Node *current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        
        cout << endl;
    }

    Node* reverse(Node *head)
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

        return prev;
    }

    ~LinkedList()
    {
        Node *current = head;
        Node *next;

        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
        
        head = nullptr;
    }
};

bool compare(Node *h1, Node *h2)
{
    while (h1 != nullptr && h2 != nullptr)
    {
        if (h1->data != h2->data)
        {
            return false;
        }
        
        h1 = h1->next;
        h2 = h2->next;
    }

    return h1 == nullptr && h2 == nullptr;
}

Node* add(Node *n1, Node *n2)
{
    Node *result = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0)
    {
        int sum;

        if (n1)
        {
            sum = n1->data;
        }
        else
        {
            sum = 0;
        }

        if (n2)
        {
            sum += n2->data;
        }
        else
        {
            sum = 0;
        }

        sum += carry;

        carry = sum / 10;

        Node *newNode = new Node(sum % 10);
        newNode->next = result;
        result = newNode;

        if (n1)
        {
            n1 = n1->next;
        }

        if (n2)
        {
            n2 = n2->next;
        }
    }

    return result; 
}

int main()
{
    LinkedList linked_list;
    LinkedList linked_list_2;

    linked_list.push_back(9);
    linked_list.push_back(7);
    linked_list.push_back(3);
    linked_list.push_back(4);
    linked_list.push_back(5);

    linked_list_2.push_back(9);
    linked_list_2.push_back(7);
    linked_list_2.push_back(3);
    linked_list_2.push_back(4);
    linked_list_2.push_back(5);

    LinkedList result_linked_list;
    result_linked_list.head = add(linked_list.head, linked_list_2.head);
    result_linked_list.print(result_linked_list.head);

     bool comparing_result = compare(linked_list.head, linked_list_2.head);

    if (comparing_result)
    {
        cout << "Linked lists are simmilar" << endl;
    }
    else
    {
        cout << "Linked lists are different" << endl;
    }

    linked_list.print(linked_list.head);

    linked_list.head = linked_list.reverse(linked_list.head);

    linked_list.print(linked_list.head);

    return 0;
}