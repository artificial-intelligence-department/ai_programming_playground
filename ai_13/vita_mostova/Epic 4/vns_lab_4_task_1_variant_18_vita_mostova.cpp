#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
    Node *end;

public:
    LinkedList()
    {
        head = NULL;
        end = NULL;
    }

    void insertStart(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;

        if (head == NULL)
        {
            newNode->next = newNode;
            head = newNode;
            end = newNode;
        }
        else
        {
            newNode->next = head;
            end->next = newNode;
            head = newNode;
        }
    }
void insertLast(int data)
{
    Node *newNode = new Node();
    newNode->data = data;

    if (head == NULL)
    {
       
        newNode->next = newNode;
        head = newNode;
        end = newNode;
    }
    else
    {
        end->next = newNode; 
        end = newNode;       
        end->next = head;   
    }
}

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty \n";
            return;
        }

        Node *node = head;

        do 
        {
            cout << node->data << " ";
            node = node->next;
        } while (node != head);

        cout <<"\n";
    }

    void displayFromK(int k)
    {
        if (head == NULL)
        {
            cout << "List is empty \n";
            return;
        }

        Node *firstNode = head;

        for (int i = 0; i < k; ++i) 
        {
            firstNode = firstNode->next;
            if (firstNode == head)
            {
                display();
                return;
            }
        }

        Node *node = firstNode; 
        do
        {
            cout << node->data << " ";
            node = node->next;
        } while (node != head);

        node = head; 
        while (node != firstNode) 
        {
            cout << node->data << " ";
            node = node->next;
        }

        cout << "\n";
    }

    void deleteNode(Node *del) 
    {
        if (del == head)
        {
            if (head->next == head) 
            {
                delete del; 
                head = NULL; 
                end = NULL;
                return;
            }

            head = head->next; 
            end->next = head; 
        }
        else
        {
            Node *temp = head;
            while (temp->next != head && temp->next != del) 
            {
                temp = temp->next;
            }

            if (temp->next == head) 
            {
                return;
            }

            temp->next = del->next; 

            if (del == end){
                end = temp;}
        }

        delete del;
    }

    void deleteEvenNodes(){
        Node *ptr = head;
        while (ptr != NULL){
            Node *next = ptr->next;
            if (ptr->data % 2 == 0) {
                deleteNode(ptr); }
            ptr = next;
            if (ptr == head){
                break;}
        }
    }
};

int main()
{
    LinkedList *list = new LinkedList();
    list->insertStart(5);
    list->insertStart(10);
    list->insertStart(15);
    list->insertStart(20);
    list->insertStart(25);
    list->insertStart(30);
    list->insertStart(35);
    cout << "Original List: ";
    list->display();
    cout << "Original List from K to (K-1): ";
    list->displayFromK(3);
    cout << "List after deleting even nodes: ";
    list->deleteEvenNodes();
    list->displayFromK(2);
    list->insertLast(40);
    list->insertLast(45);
    list->insertStart(6);
    cout << "List after appending elements to the end: ";
    list->display();
    return 0;
}
