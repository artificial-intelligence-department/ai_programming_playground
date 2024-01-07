#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *nextnumber;

    Node(int number) : data(number), nextnumber(nullptr) {}
};

Node *sum(Node *firstNum, Node *secondNum)
{
    Node *res = nullptr;
    Node *currentnumber = nullptr;
    int number = 0;

    while (firstNum != nullptr || secondNum != nullptr || number > 0)
    {
        int sum = number;

        if (firstNum != nullptr)
        {
            sum += firstNum->data;
            firstNum = firstNum->nextnumber;
        }
        if (secondNum != nullptr)
        {
            sum += secondNum->data;
            secondNum = secondNum->nextnumber;
        }

        int digit = sum % 10;
        number = sum / 10;

        Node *resultNode = new Node(digit);

        if (res == nullptr)
        {
            res = resultNode;
            currentnumber = res;
        }
        else
        {
            currentnumber->nextnumber = resultNode;
            currentnumber = resultNode;
        }
    }

    return res;
}

Node *reverseNumber(Node *head)
{
    Node *previousnumber = nullptr;
    Node *currentnumber = head;
    Node *nextnumberNode = nullptr;

    while (currentnumber != nullptr)
    {
        nextnumberNode = currentnumber->nextnumber;
        currentnumber->nextnumber = previousnumber;

        previousnumber = currentnumber;
        currentnumber = nextnumberNode;
    }

    return previousnumber;
}

void CoutList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->nextnumber;
    }
    cout << "\n";
}

int main()
{
    Node *firstNum = new Node(6);
    firstNum->nextnumber = new Node(5);
    firstNum->nextnumber->nextnumber = new Node(3);

    Node *firstNum2 = new Node(8);
    firstNum2->nextnumber = new Node(9);
    firstNum2->nextnumber->nextnumber = new Node(5);
    Node *result = sum(firstNum, firstNum2);

    cout << "first number = 356" << endl;

    cout << "second number = 598" << endl;

    Node *reversedResult = reverseNumber(result);
    cout << "The sum equals: ";
    CoutList(reversedResult);

    return 0;
}