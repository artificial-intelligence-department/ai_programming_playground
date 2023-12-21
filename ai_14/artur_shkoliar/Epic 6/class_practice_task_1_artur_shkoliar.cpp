#include <iostream>

using namespace std;

class Node 
{
public:
    int value;
    Node* next;

    Node(int val, Node* node = nullptr) 
    {
        value = val;
        next = node;
    }
};

class LinkedList 
{
private:
    Node* head;

public:
    LinkedList() 
    {
        head = nullptr;
    }

    void append(int val) 
    {
        Node* newNode = new Node(val);
        if (!head) 
        {
            head = newNode;
        } 
        
        else 
        {
            Node* current = head;
            while (current->next) 
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    
    void reverseAndOutput() 
    {
        head = reverse(head);
        outputList();
    }

private:
   
    Node* reverse(Node* head) 
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

   
    void outputList() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() 
{
    LinkedList list;


    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    
    list.reverseAndOutput();

    return 0;
}
