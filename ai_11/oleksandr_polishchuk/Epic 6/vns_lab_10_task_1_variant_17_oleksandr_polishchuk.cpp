#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Node
{
    public:
    char* data;
    Node* prev;
    Node* next;
    public:
    Node(char* appendedData)
    {
        data = new char[strlen(appendedData) + 1];
        strcpy(data, appendedData);
        prev = NULL;
        next = NULL;
    }
    
};
class List
{
    public:
    Node* head;
    Node* tail;
    public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    Node* push_front(char* pushData)
    {
        Node* newNode = new Node(pushData);
        newNode -> next = head;
        if (head != NULL)   
            head -> prev = newNode;
        if (tail == NULL)
            tail = newNode;
        head = newNode;
        return newNode;
    }

    void printList (Node* head)
    {   
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }  
        Node* ptr = head -> next;
        cout << head -> data << "\t";
        while (ptr != NULL)
        {
            cout << ptr -> data << "\t";
            ptr = ptr -> next;
        }
    }
    void writeToFile(string filename)
        {
            ofstream outFile(filename);
            if (!outFile.is_open())
            {
                cout << "Opening error " << endl;
                return;
            }
            Node* current = head;
            while (current != NULL)
            {
                outFile << current -> data << " ";
                current = current -> next;
            }
            outFile.close();
        }
        void readFromFile(string filename)
        {
            ifstream inFile(filename);
            if (!inFile.is_open())
            {
                cout << "Opening error " << endl;
                return;
            }
            char data[512];
            while (inFile >> data)
            {
                push_front(data);
            }
            inFile.close();
        }
};

void deleteElement(List& list, int index)
{
    int count = 1;
        Node* ptr = list.head;
        while (ptr != NULL)
        {
            if(count == index)
            {
                if (ptr -> prev != NULL)
                    ptr -> prev -> next = ptr -> next;
                else list.head = ptr -> next;

                if (ptr ->next != NULL)
                    ptr -> next -> prev = ptr -> prev;
                else list.tail = ptr -> prev;
            
                delete ptr;
                break;
            }
            count++;
            ptr = ptr -> next;
        }
}
void deleteList(List& list)
{
    Node* node = list.head;
    Node* toDelete = NULL;

    while (node != NULL)
        {
            toDelete = node -> next;
            delete node;
            node = toDelete;
        }
    list.head = NULL;
    list.tail = NULL;
}


int main()
{
    int i, n;
    char input[512];
    string filename;
    List newList;
    cout << "Write a number of elements" << endl;
    cin >> n;
    
    cout << "Add the elements" << endl;
    while(n > 0)
    {
        cin >> input;
        newList.push_front(input);
        newList.printList(newList.head); 
        cout << endl;
        n--;
    }
    newList.writeToFile("lab10.txt");
    deleteList(newList);
    newList.printList(newList.head);
    cout << endl;
    newList.readFromFile("lab10.txt");
    newList.printList(newList.head);
    
    deleteList(newList);
    return 0;
}