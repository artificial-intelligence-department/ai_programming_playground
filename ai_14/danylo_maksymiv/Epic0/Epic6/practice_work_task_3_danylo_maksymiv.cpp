#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

void addToStart(Node *&head, int value) 
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void printList(Node *head) 
{
    while (head != nullptr) 
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* add(Node *n1, Node *n2)
{
    Node *result = nullptr;
    Node *current = nullptr;
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
        sum = sum % 10;

        addToStart(result, sum);
    }

    return result;
}

int main() 
{
    Node *num1 = nullptr;
    Node *num2 = nullptr;

    cout << "Enter the first number digit by digit (press Enter to stop): ";
    char digit;
    while (cin.get(digit) && digit != '\n') 
    {
        int value = digit - '0';
        addToStart(num1, value);
    }

    cout << "Enter the second number digit by digit (press Enter to stop): ";
    while (cin.get(digit) && digit != '\n') 
    {
        int value = digit - '0';
        addToStart(num2, value);
    }

    cout << "Number 1: ";
    printList(num1);

    cout << "\nNumber 2: ";
    printList(num2);

    Node *sum = add(num1, num2);

    cout << "\nSum: ";
    printList(sum);

    while (num1 != nullptr) 
    {
        Node *temp = num1;
        num1 = num1->next;
        delete temp;
    }

    while (num2 != nullptr) 
    {
        Node *temp = num2;
        num2 = num2->next;
        delete temp;
    }

    while (sum != nullptr) 
    {
        Node *temp = sum;
        sum = sum->next;
        delete temp;
    }

    return 0;
}
