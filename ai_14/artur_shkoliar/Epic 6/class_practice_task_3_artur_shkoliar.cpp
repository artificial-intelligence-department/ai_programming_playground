#include <iostream>

using namespace std;

class Node 
{
public:
    int value;
    Node* next;

    Node(int val, Node* node = nullptr) 
    {
        value = val;
        next = node;
    }
};


void outputList(Node* head) 
{
    Node* current = head;
    while (current != nullptr) 
    {
        cout << current->value;
        if (current->next != nullptr) 
        {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}


Node* add(Node* n1, Node* n2) 
{
    Node* resultHead = nullptr;
    Node* currentResult = nullptr;

    int carry = 0; 

    while (n1 != nullptr || n2 != nullptr || carry != 0) 
    {
        int sum = carry;

        if (n1 != nullptr) 
        {
            sum += n1->value;
            n1 = n1->next;
        }

        if (n2 != nullptr) 
        {
            sum += n2->value;
            n2 = n2->next;
        }

        int digit = sum % 10;
        carry = sum / 10;     

        Node* newNode = new Node(digit);
        if (resultHead == nullptr)
        {
            resultHead = newNode;
            currentResult = newNode;
        } 

        else 
        {
            currentResult->next = newNode;
            currentResult = newNode;
        }
    }

    return resultHead;
}

int main() 
{
    Node* number1 = new Node(3, new Node(7, new Node(9)));
    Node* number2 = new Node(8, new Node(6, new Node(3)));

    cout << "Число 1: ";
    outputList(number1);

    cout << "Число 2: ";
    outputList(number2);

    
    Node* result = add(number1, number2);

    cout << "Сума: ";
    outputList(result);

   
    while (number1 != nullptr) 
    {
        Node* temp = number1;
        number1 = number1->next;
        delete temp;
    }

    while (number2 != nullptr) 
    {
        Node* temp = number2;
        number2 = number2->next;
        delete temp;
    }

    while (result != nullptr) 
    {
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
