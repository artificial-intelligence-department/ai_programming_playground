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

    void reverse()
    {
        Node* previous = nullptr;
        Node* current = head;
        Node* next_node = nullptr;

        while(current != nullptr)
        {
            next_node = current -> next;
            current -> next = previous;
            previous = current;
            current = next_node;
        }

        head = previous;
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
};

int main()
{
    int amount;
    vector <int> data;
    cout << "Enter the amount of your numbers: " << endl;
    cin >> amount;

    cout << "Enter numbers: " << endl;
    for(int i = 0; i < amount; ++i)
    {
        int number;
        cin >> number;
        data.push_back(number);
    }

    List new_list;

    new_list.create_list(amount, data);
    cout << "Start list: ";
    new_list.printList();
    new_list.reverse();
    cout << "Reverse list: ";
    new_list.printList();
    
    return 0;
}