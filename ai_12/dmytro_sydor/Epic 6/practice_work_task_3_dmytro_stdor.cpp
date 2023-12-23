#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int number) : data(number), next(nullptr) {}
};

Node *sum(Node *firstNum, Node *secondNum)
{
    Node *res = nullptr;
    Node *current = nullptr;
    int peren = 0;

    while (firstNum != nullptr || secondNum != nullptr || peren > 0)
    {
        int sum = peren;

        if (firstNum != nullptr)
        {
            sum += firstNum->data;
            firstNum = firstNum->next;
        }
        if (secondNum != nullptr)
        {
            sum += secondNum->data;
            secondNum = secondNum->next;
        }

        int digit = sum % 10;
        peren = sum / 10;

        Node *resultNode = new Node(digit);

        if (res == nullptr)
        {
            res = resultNode;
            current = res;
        }
        else
        {
            current->next = resultNode;
            current = resultNode;
        }
    }

    return res;
}

Node *reverseNumber(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next;
        current->next = prev;

        prev = current;
        current = nextNode;
    }

    return prev;
}

void CoutList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

int main()
{
    Node *firstNum = new Node(9);
    firstNum->next = new Node(7);
    firstNum->next->next = new Node(3);

    Node *firstNum2 = new Node(1);
    firstNum2->next = new Node(2);
    Node *result = sum(firstNum, firstNum2);

    Node *reversedResult = reverseNumber(result);
    std::cout << "Result: ";
    CoutList(reversedResult);

    return 0;
}