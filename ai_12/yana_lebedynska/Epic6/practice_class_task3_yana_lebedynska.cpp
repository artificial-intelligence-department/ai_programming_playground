#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* add(Node* n1, Node* n2)
{
    Node* current = nullptr;
    Node* result = nullptr;
    int extra = 0;

    while (n1 !=  nullptr || n2 != nullptr || extra != 0)
    {
        int sum = extra;
        if(n1 != nullptr)
        {
            sum += n1->data;
            n1 = n1->next;
        }

        if(n2 != nullptr)
        {
            sum += n2->data;
            n2 = n2->next;
        }

        extra = sum / 10;
        sum %= 10;

        Node* newNode = new Node(sum);
        if(result == nullptr)
        {
            result = newNode;
            current = result;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    return result;
}

void PrintReversedNum(Node* num)
{
    if(num == nullptr)
    {
        return;
    }

    PrintReversedNum(num->next);
    cout << num->data;
}

int main()
{
    Node* num1 = new Node(9);
    num1->next = new Node(7);
    num1->next->next =  new Node(3);

    Node* num2 = new Node(1);
    num2->next = new Node(1);
    num2->next->next = new Node(2);

    Node* result = add(num1, num2);

    cout << "Number 1: ";
    PrintReversedNum(num1);
    cout << endl;

    cout << "Number 2: ";
    PrintReversedNum(num2);
    cout << endl;

    cout << "The sum is: ";
    PrintReversedNum(result);
    cout << endl;

    return 0;
}
