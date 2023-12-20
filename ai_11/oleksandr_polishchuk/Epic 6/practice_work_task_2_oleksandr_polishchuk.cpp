#include <iostream>
//#include <vector>

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
};
   
bool compare(List l1, List l2)
{ 
    if (l1.head ==NULL || l2.head ==NULL)
        {
            return false;
        }
    Node* n1 = l1.head -> next;
    Node* n2 = l2.head -> next;
    
    int count = 1, size1 = 0, size2 = 0;
    while (n1 != NULL)
        {
            n1 = n1 -> next;
            size1++;
        }
    while (n2 != NULL)
        {
            n2 = n2 -> next;
            size2++;
        }
    n1 = l1.head;
    n2 = l2.head;
    if (size1 != size2)
        return false;
    else
    {
        while (n1 != NULL && n2 != NULL)
            {
                if (n1 -> data > n2 -> data)
                    cout << "Node №" << count << "from first list is greater" << endl;
                else if (n1 -> data < n2 -> data)
                    cout << "Node №" << count << "from second list is greater" << endl;
                else cout << "Nodes №" << count << "are equal" << endl;
                n1 = n1 -> next;
                n2 = n2 -> next;
                count++;
            }
    }
    return true;
}
int main()
{
    int input;
    List l1, l2;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l2.push_back(4);
    l2.push_back(3);
    l2.push_back(2);
    l2.push_back(1);
    if (!compare(l1, l2))
        cout << "Lists cannot be fully compared";
    return 0;
}