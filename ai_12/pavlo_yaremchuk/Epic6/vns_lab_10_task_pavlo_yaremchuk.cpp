#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* CreateLinkedList()
{
    return nullptr;
}

void FillLinkedList(Node*& head, int data)
{
    Node* newNode = new Node{data, nullptr};
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node* currnt = head;
        while (currnt->next != nullptr)
        {
            currnt = currnt->next;
        }
        currnt->next = newNode;
    }
}

void DeleteFromLinkedList(Node*& head, int first, int K)
{
    Node* currnt = head;
    Node* prvs = nullptr;
    int n = 1;

    while (currnt != nullptr && n < first)
    {
        prvs = currnt;
        currnt = currnt->next;
        ++n;
    }

    for (int i = 0; i < K && currnt != nullptr; ++i)
    {
        Node* nxt = currnt->next;
        delete currnt;
        currnt = nxt;
    }

    if (prvs == nullptr)
    {
        head = currnt;
    }
    else
    {
        prvs->next = currnt;
    }
}

void AddToLinkedList(Node*& head, int first, int K)
{
    Node* currnt = head;
    Node* prvs = nullptr;
    int n = 1;

    while (currnt != nullptr && n < first)
    {
        prvs = currnt;
        currnt = currnt->next;
        ++n;
    }

    int addedEl[K];
    for (int i = 0; i < K; ++i)
    {
        cin >> addedEl[i];
    }

    for (int i = 0; i < K; ++i)
    {
        Node* newNode = new Node;
        newNode->data = addedEl[i];

        if (prvs == nullptr)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = currnt;
            prvs->next = newNode;
        }
        prvs = newNode;
        currnt = newNode->next;
    }
}

void PrintLinkedList(Node* head)
{
    if (head == nullptr)
    {
        cout << "Список порожній";
    }
    else
    {
        Node* currnt = head;
        while (currnt != nullptr) 
        {
            cout << currnt->data << " ";
            currnt = currnt->next;
        }
    }
    cout << endl;
}

void AddLlToFile(Node* head, string filename)
{
    ofstream file(filename);

    if (!file.is_open())
    {
        cout << "Помилка запису в файл" << endl;
        return;
    }

    Node* currnt = head;
    while(currnt != nullptr)
    {
        file << currnt->data << " ";
        currnt = currnt->next;
    }

    file.close();
}

void DeleteLinkedList(Node*& head)
{
    Node* currnt = head;
    while (currnt != nullptr)
    {
        Node* nxt = currnt->next;
        delete currnt;
        currnt = nxt;
    }
    head = currnt;
}

void returnLlFromFile(string filename, Node*& head)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Помилка читання файлу" << endl;
        return;
    }

    int dataFromFile;
    while (file >> dataFromFile)
    {
        Node* newNode = new Node{dataFromFile, nullptr};
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* currnt = head;
            while (currnt->next != nullptr)
            {
                currnt = currnt->next;
            }
            currnt->next = newNode;
        }
    }
    file.close();
}

int main()
{
    Node* head = CreateLinkedList();

    FillLinkedList(head, 11);
    FillLinkedList(head, 12);
    FillLinkedList(head, 13);
    FillLinkedList(head, 14);

    PrintLinkedList(head);

    DeleteFromLinkedList(head, 2, 2);

    PrintLinkedList(head);

    AddToLinkedList(head, 2, 2);

    PrintLinkedList(head);

    AddLlToFile(head, "Lab10.txt");

    DeleteLinkedList(head);

    PrintLinkedList(head);

    returnLlFromFile("Lab10.txt", head);

    PrintLinkedList(head);

    return 0;
}