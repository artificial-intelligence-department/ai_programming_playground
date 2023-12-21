#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;
public:
    Node(int input)
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
    void push_front(int input)
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
    void push_back(int input)
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
    int getdata(int index)
    {
        if (get(index) == nullptr)
        {
            return NAN;
        }
        return get(index)->data;

    }
    int operator [](int index)
    {
        if (get(index) == nullptr)
        {
            return NAN;
        }
        return get(index)->data;
    }
    void insert(int index, int input)
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
    int get_front()
    {
        if (head == nullptr)
        {
            return NAN;
        }
        int x = head->data;
        return x;
    }
    int get_back()
    {
        if (tail == nullptr)
        {
            return NAN;
        }
        int x = tail->data;
        return x;
    }


};
bool compare(DoubleLinkedList first, DoubleLinkedList second)
{
    while (first.tail != nullptr)
    {
        if (first.get_back() != second.get_back())
        {
            return false;
        }
        if (first.get_back() == second.get_back())
        {
            first.pop_back();
            second.pop_back();
        }
    }
    if (first.tail == nullptr && second.tail == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    DoubleLinkedList test;
    int Q;
    cout << "\033[32m" << "Enter the amount of elements: " << "\033[0m";
    cin >> Q;
    if (Q > 0)
    {
        cout << "\033[32m" << "Enter the numbers:" << endl << "\033[0m";
        for (int i = 0; i < Q; i++)
        {
            int x;
            cin >> x;
            test.push_back(x);
        }
    }
    DoubleLinkedList test2;
    int Q2;
    cout << "\033[32m" << "Enter the amount of elements: " << "\033[0m";
    cin >> Q2;
    if (Q2 > 0)
    {
        cout << "\033[32m" << "Enter the numbers:" << endl << "\033[0m";
        for (int i = 0; i < Q2; i++)
        {
            int x;
            cin >> x;
            test2.push_back(x);
        }
    }
    cout << boolalpha;
    cout << compare(test, test2);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
