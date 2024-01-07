#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* previous;

    Node (int value) : data(value), next(nullptr), previous(nullptr)
    {

    }
};

class List
{
    private:
    Node* head;
    Node* tail;

    public:
    List (): head(nullptr), tail(nullptr)
    {

    }

    void create_list()
    {
        head = tail = nullptr;
    };

    void add_element(int K, vector <int> data)
    {
        for(int i = 0; i < K; ++i)
        {
            Node* new_node = new Node(data[i]);
            
            if(head == nullptr)
            {
                head = tail = new_node;
            }
            else
            {
                new_node -> next = head;
                new_node -> previous = nullptr;
                head -> previous = new_node;
                head = new_node;
            }
        }

    };

    void print()
    {
        Node* current = head;

        if(current == nullptr)
        {
            cout << "The list is empty" << endl;
        }

        while(current != nullptr)
        {
            cout << current -> data << " ";
            current = current -> next;
        }

        cout << endl;
    };

    void erase_element(int K, int index)
    {
        Node* current = head;

        for(int i = 0; i < index && current; ++i)
        {
            current = current -> next;
        }

        for(int i = 0; i < K && current; ++i)
        {
            Node* next_node = current -> next;
            Node* previous_node = current -> previous;
            
            if(previous_node)
            {
                previous_node -> next = next_node;
            }
            else
            {
                head = next_node;
            }

            if(next_node)
            {
                next_node -> previous = previous_node;
            }
            else
            {
                tail = next_node;
            }

            delete current;
            current = next_node;
        }
    };

    void write_to_file()
    {
        ofstream outf("list.txt");

        Node* current = head;

        while(current != nullptr)
        {
            outf << current -> data << " ";
            current = current -> next;
        }

        outf.close();
    };

    void kill_list()
    {
        Node* current = head;
        Node* next;

        while(current != nullptr)
        {
            next = current -> next;
            delete current;
            current = next;
        }

        head = nullptr;
    };

    void staying_alive()
    {
        create_list();

        ifstream inf("list.txt");
        int number;
        vector <int> data;

        while(inf >> number)
        {
            data.push_back(number);
        }

        inf.close();

        reverse(data.begin(), data.end());
        add_element(data.size(), data);
    };
};

int main()
{
    List new_list;
    new_list.create_list();

    int K;
    int times;
    cout << "How many times do you want to add your numbers? \n It should be at least 2 times)" << endl;
    cin >> times;

    for(int i = 0; i < times; ++i)
    {
        cout << "How many numbers you want to add?" << endl;
        cin >> K;

        cout << "Please add your numbers" << endl;
        vector <int> data;
        for(int i = 0; i < K; ++i)
        {
            int number;
            cin >> number;
            data.push_back(number);
        }
    
        new_list.add_element(K, data);
        cout << "New list after adding: ";
        new_list.print();
    }

    int index;
    cout << "What is the index of the element, you want to delete?" << endl;
    cin >> index;
    cout << "Please enter how many elements, you want to delete" << endl;
    cin >> K;
    new_list.erase_element(K, index);
    cout << "New list after deleting : ";
    new_list.print();

    new_list.write_to_file();
    new_list.kill_list();
    cout << "list is R.I.P ((" << endl;
    new_list.print();

    new_list.staying_alive();
    cout << "I always come back..." << endl;
    new_list.print();

    new_list.kill_list();

    return 0;
}
