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
        for(int i = 0; i < amount; ++i)
        {
            Node* new_node = new Node(data[i]);

            if(head == nullptr)
            {
                head = new_node;
            }
            else
            {
                new_node -> next = head;
                head = new_node;
            }
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
};

vector <int> add(Node* n1, Node* n2)
{
    Node* current1 = n1;
    Node* current2 = n2;
    vector <int> result;
    int carry = 0;

    while(current1 != nullptr || current2 != nullptr || carry != 0)
    {
        int sum = carry;
        
        if(current1 != nullptr)
        {
            sum += current1 -> data;
            current1 = current1 -> next;
        }

        if(current2 != nullptr)
        {
            sum += current2 -> data;
            current2 = current2 -> next;
        }

        int digit = sum % 10;
        carry = sum / 10;

        result.insert(result.begin(), digit);
    };

    return result;
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

    List number1;
    List number2;
    List final;

    number1.create_list(amount1, data1);
    number2.create_list(amount2, data2);
    cout << "List with number 1: ";
    number1.printList();
    cout << "List with number 2: ";
    number2.printList();
    final.create_list(add(number1.Head(), number2.Head()).size(), add(number1.Head(), number2.Head()));
    cout << "List with the result: ";
    final.printList();

    cout << "List with the result, showed normally: " << endl;
    final.reverse();
    final.printList();

    return 0;
}