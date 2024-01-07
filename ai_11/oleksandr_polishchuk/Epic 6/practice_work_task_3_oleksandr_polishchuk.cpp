#include <iostream>
#include <cmath>

using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;
    public:
    Node(int appendedData)
    {
        data = appendedData;
        prev = NULL;
        next = NULL;
    }
    
};
class List
{
    public:
    Node* head;
    Node* tail;
    public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    int size()
    {
        int size = 0;
        Node* n = head;
        while (n != NULL)
        {
            n = n -> next;
            size++;
        }
        return size;
    }
    Node* push_back(int pushData)
    {
        Node* newNode = new Node(pushData);
        newNode -> next = NULL;
        newNode -> prev = tail;
        if (head == NULL)
            head = newNode;
        if (tail != NULL)
            tail -> next = newNode;
        tail = newNode;
        return newNode;   
    }
    
    void printList (Node* head)
    {   
        if (head == NULL)
        {
            return;
        }  
        Node* ptr = head -> next;
        Node* temp = NULL;
        cout << head -> data << "\t";
        while (ptr != NULL)
        {
          
            cout << ptr -> data << "\t";
            ptr = ptr -> next;
        }
    }    
};

List add(List l1, List l2)
    {
        List finalList;
        int n1 = 0, n2 = 0, sum = 0, size1 = l1.size(), size2 = l2.size(), buff = 0;
        Node* ptr1 = l1.head;
        Node* ptr2 = l2.head;
        buff = size1;
        while (size1 != 0)
        {
            n1 += (ptr1 -> data) * pow(10, (buff - size1));
            ptr1 = ptr1 -> next;
            size1--;
        }
        buff = size2;
        while (size2 != 0)
        {
            n2 += (ptr2 -> data) * pow(10, (buff - size2));
            ptr2 = ptr2 -> next;
            size2--;
        }
        sum = n1 + n2;
        finalList.push_back(sum);
        return finalList;
    }

int main()
{
    List l1, l2, l3;
    Node* temp = NULL;
    Node* ptr;
    l1.push_back(9);
    l1.push_back(7);
    l1.push_back(3);
    l2.push_back(4);
    l2.push_back(2);
    l2.push_back(5);
    l3 = add(l1, l2);
    cout << "Final list:" << endl;
    l3.printList(l3.head);
    return 0;
}