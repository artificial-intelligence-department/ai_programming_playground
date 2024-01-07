#include<iostream>
#include<string>

using namespace std;
class Node 
{
    public: 
    string element;
    Node* next;
};

void printFUNC(Node* el)
{
    while(el != NULL)
    {
        cout<<el -> element<<"  ";
        el = el -> next;
    }
}

bool comparedFUNC (Node* link_list, Node* link_list2)
{   
    if(link_list == link_list2)
    {
        return true;
    }
    
    while(link_list != NULL && link_list2 != NULL)
    {
        if(link_list -> element != link_list2 ->element)
        {
        return true;
        }
        link_list = link_list -> next;
        link_list2 = link_list2 -> next;
    }
    return false;
}

int main()
{
    Node* head = NULL;
    Node* middle = NULL;
    Node* tail = NULL;

    head = new Node();
    middle = new Node();
    tail = new Node();

    head -> element = "BMW"; 
    head -> next = middle;

    middle -> element = "Audi";
    middle -> next = tail;

    tail -> element = "Mercedes-Benz";
    tail -> next = NULL;

    printFUNC(head);

    cout<<endl<<endl;

    Node* head2 = NULL;
    Node* middle2 = NULL;
    Node* tail2 = NULL;

    head2 = new Node();
    middle2 = new Node();
    tail2 = new Node();
    
    head2 -> element = "Mercedes-Benz";
    head2 -> next = middle2;

    middle2 -> element = "Audi";
    middle2 -> next = tail2;

    tail2 -> element = "BMW";
    tail2 -> next = NULL;

    printFUNC(head2);

    cout<<endl<<endl;

    bool final = comparedFUNC(head, head2);

    if(final == true)
    {
        cout<<"These list are not similar!"<<endl;
    }
    else
    {
        cout<<"These lsit are similar!"<<endl;
    }
    
    return 0;
}