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
    Node* resultHead = nullptr;
    Node* resultTail = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0)
    {
        int sum = carry;
        if (n1 != nullptr)
        {
            sum += n1->data;
            n1 = n1->next;
        }

        if (n2 != nullptr)
        {
            sum += n2->data;
            n2 = n2->next;
        }

        carry = sum / 10;
        sum %= 10;

        Node* newNode = new Node(sum);
        if (resultHead == nullptr)
        {
            resultHead = resultTail = newNode;
        }
        else
        {
            resultTail->next = newNode;
            resultTail = newNode;
        }
    }

    return resultHead;
}

void printNum(Node* num)
{
    while (num != nullptr)
    {
        cout << num->data;
        num = num->next;
    }
}

int main()
{
    Node* num1 = new Node(9);
    num1->next = new Node(8);
    num1->next->next = new Node(1);

    Node* num2 = new Node(5);
    num2->next = new Node(1);
    num2->next->next = new Node(6);

    Node* result = add(num1, num2);

    cout << "Number 1: ";
    printNum(num1);
    cout << endl;

    cout << "Number 2: ";
    printNum(num2);
    cout << endl;

    cout << "The sum is: ";
    printNum(result);
    cout << endl;

    return 0;
}
