

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node* prev;
    Node* next;
public:
    Node(string input)
    {
        this->data = input;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
class DoubleLinkedList
{
public:
    Node* head;
    Node* tail;
    DoubleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~DoubleLinkedList()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }
    void push_front(string input)
    {
        Node* node = new Node(input);
        node->next = head;
        if (head != nullptr)
        {
            head->prev = node;
        }
        if (tail == nullptr)
        {
            tail = node;
        }
        head = node;
    }
    void push_back(string input)
    {
        Node* node = new Node(input);
        node->prev = tail;
        if (tail != nullptr)
        {
            tail->next = node;
        }
        if (head == nullptr)
        {
            head = node;
        }
        tail = node;
    }
    void pop_front()
    {
        if (head == nullptr)
        {
            return;
        }
        Node* node = head->next;
        if (node != nullptr)
        {
            node->prev = nullptr;
        }
        else
        {
            tail = node;
        }
        delete head;
        head = node;

    }
    void pop_back()
    {
        if (tail == nullptr)
        {
            return;
        }
        Node* node = tail->prev;
        if (node != nullptr)
        {
            node->next = nullptr;
        }
        else
        {
            head = node;
        }
        delete tail;
        tail = node;

    }
    Node* get(int index)
    {
        if (index < 0)
        {
            return nullptr;
        }
        Node* node = head;
        int N = 0;
        while (node != nullptr && N != index && node->next != nullptr)
        {
            node = node->next;
            N++;
        }
        if (N == index)
        {
            return node;
        }
        else
        {
            return nullptr;
        }

    }
    string getdata(int index)
    {
        if (get(index) == nullptr)
        {
            return "NONE";
        }
        return get(index)->data;

    }
    string operator [](int index)
    {
        if (get(index) == nullptr)
        {
            return "NONE";
        }
        return get(index)->data;
    }
    void insert(int index, string input)
    {
        Node* left = get(index);
        if (left == nullptr)
        {
            push_front(input);
        }
        Node* right = left->next;
        Node* node = new Node(input);
        left->next = node;
        node->next = right;
        node->prev = left;
        node->next = right;
        if (right == nullptr)
        {
            tail = node;
        }

    }
    void erase(int index)
    {
        Node* node = get(index);
        if (node == nullptr)
        {
            return;
        }
        if (node->prev == nullptr)
        {
            pop_front();
            return;
        }
        if (node->next == nullptr)
        {
            pop_back();
            return;
        }
        Node* left = node->prev;
        Node* right = node->next;
        left->next = right;
        right->prev = left;
        delete node;
        node = nullptr;
    }
    void print()
    {
        for (Node* node = head; node != nullptr; node = node->next)
        {
            cout << node->data << " ";
        }
        if (head == nullptr)
        {
            cout << "\033[31m" << "The list is empty" << endl << "\033[0m";
        }
    }

};
void writeinto(DoubleLinkedList test, int size)
{
    ofstream out("Lab10.txt");
    if (!out)
    {
        cout << "Can't create file for writing" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        out << test[i] << endl;
    }
    out.close();
}
void readfrom(DoubleLinkedList& mylist)
{
    ifstream input("Lab10.txt");
    if (!input)
    {
        cout << "Can't open file for reading" << endl;
        return;
    }
    string str;
    while (getline(input, str))
    {
        mylist.push_back(str);
    }
    input.close();

}

int main()
{
    DoubleLinkedList test;
    int Q;
    cout << "\033[32m" << "Enter the amount of elements: " << "\033[0m";
    cin >> Q;
    if (Q > 0)
    {
        cout << "\033[32m" << "Enter the words:" << endl << "\033[0m";
        for (int i = 0; i < Q; i++)
        {
            string x;
            cin >> x;
            test.push_back(x);
        }
    }
    cout << "\033[32m" << "The list is now: " << "\033[0m" << endl;
    test.print();
    cout << endl;
    int index1;
tryagain:
    cout << "\033[36m" << "Enter the element to erase: " << "\033[0m";
    cin >> index1;
    if (index1 >= Q)
    {
        cin.clear();
        goto tryagain;
    }
    test.erase(index1);
    cout << "\033[32m" << "The list is now: " << "\033[0m" << endl;
    test.print();
    cout << endl;
    int amount;
    cout << "\033[1m\033[32m" << "Enter the amount of elements to insert: " << "\033[0m";
    cin >> amount;
    cout << "\033[1m\033[32m" << "Enter the elements to insert: " << "\033[0m";
    string* input = new string[amount];
    for (int i = 0; i < amount; i++)
    {
        cin >> input[i];
    }
    int index2;
    
tryagain2:
    cout << "\033[1m\033[32m" << "Enter the element index to insert after: " << "\033[0m";
    cin >> index2;
    if (index2 >= Q - 1)
    {
        goto tryagain2;
    }
    for (int i = 0; i < amount; i++)
    {
        test.insert(index2 + i, input[i]);
    }
    cout << "\033[32m" << "The list is now: " << "\033[0m" << endl;
    test.print();
    cout << endl;
    writeinto(test, Q - 1 + amount);
    DoubleLinkedList test2;
    readfrom(test2);
    cout << "\033[36m" << "The list test 2 read from file is: " << "\033[0m" << endl;
    test2.print();
    


}

