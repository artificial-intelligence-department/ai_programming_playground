#include <iostream>
#include <vector>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr)
    {

    }
};

class List
{
    private:
    Node* head;

    public:
    List() : head(nullptr)
    {

    }

    void create_list(int amount, vector <int> data)
    {
        if (amount == 0 || data.empty()) 
        {
            return;
        }

        head = new Node(data[0]);
        Node* current = head;
        
        for(int i = 1; i < amount; ++i)
        {
            Node* new_node = new Node(data[i]);
            current -> next = new_node;
            current = new_node;
        }
    };

    void printList()
    {
        Node* current = head;

        while(current != nullptr)
        {
            cout << current -> data << " ";
            current = current -> next;
        }

        cout << endl;
    };

    Node* Head()
    {
        return head;
    }
};

bool compare(Node* h1, Node* h2)
{
    Node* current1 = h1;
    Node* current2 = h2;

    while(current1 != nullptr && current2 != nullptr)
    {   
        if(current1 -> data != current2 -> data)
        {
            return false;
        }

        current1 = current1 -> next;
        current2 = current2 -> next;
    }

    if(current1 != nullptr || current2 != nullptr)
    {
        return false;
    }

    return true;
};

int main()
{
    int amount1, amount2;
    vector <int> data1;
    vector <int> data2;
    cout << "Enter the amount of your numbers for list 1: " << endl;
    cin >> amount1;

    cout << "Enter numbers for list 1: " << endl;
    for(int i = 0; i < amount1; ++i)
    {
        int number;
        cin >> number;
        data1.push_back(number);
    }

    cout << "Enter the amount of your numbers for list 2: " << endl;
    cin >> amount2;

    cout << "Enter numbers for list 2: " << endl;
    for(int i = 0; i < amount2; ++i)
    {
        int number;
        cin >> number;
        data2.push_back(number);
    }

    List list1;
    List list2;

    list1.create_list(amount1, data1);
    list2.create_list(amount2, data2);

    if(compare(list1.Head(), list2.Head()))
    {
        cout << "List 1 and list 2 are similar" << endl;
    }
    else
    {
        cout << "They are different" << endl;
    }
    
    return 0;
}