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

bool compare(Node* h1, Node* h2) 
{
    while (h1 != nullptr && h2 != nullptr) 
    {
        if (h1->value != h2->value) 
        {
            return false;  
        }

        h1 = h1->next;
        h2 = h2->next;
    }

    
    return h1 == nullptr && h2 == nullptr;
}

int main() 
{
    Node* list1 = new Node(1, new Node(2, new Node(3)));
    Node* list2 = new Node(1, new Node(2, new Node(3)));

    
    list1->next->next->next = new Node(4);
    list2->next->next->next = new Node(5);

   
    if (compare(list1, list2)) 
    {
        cout << "Списки рівні." << endl;
    } 
    
    else 
    {
        cout << "Списки відрізняються." << endl;
    }


    while (list1 != nullptr) 
    {
        Node* temp = list1;
        list1 = list1->next;
        delete temp;
    }

    while (list2 != nullptr) 
    {
        Node* temp = list2;
        list2 = list2->next;
        delete temp;
    }

    return 0;
}
