#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Node
{
    const char* data;
    Node *next;
    Node *prev;

    Node(const char* data) : data(data), next(nullptr), prev(nullptr)
    {}
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList(): head(nullptr), tail(nullptr)
    {}

    void push_back(const char* value) 
    {
        Node* newNode = new Node(value);
        if (tail == nullptr) 
        {
            head = tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void print(Node *head)
    {
        Node *current = head;

        if (current == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        
        cout << endl;
    }

    void delete_element(const char* key)
    {
        Node *current = head;

        while (current != nullptr) 
        {
            Node* nextNode = current->next;

            if (strcmp(current->data, key) == 0)
            {
                if (current->prev != nullptr)
                {
                    current->prev->next = current->next;
                }
                else
                {
                    head = current->next;
                    if (head != nullptr)
                    {
                        head->prev = nullptr;
                    }
                }

                if (current->next != nullptr)
                {
                    current->next->prev = current->prev;
                }
                else
                {
                    tail = current->prev;
                    if (tail != nullptr)
                    {
                        tail->next = nullptr;
                    }
                }

                delete current;
            }

            current = nextNode;
        }
    }

    void add_element(const char* data, int number)
    {
        Node* newNode = new Node(data);

        if(number == 0)
        {
            newNode->next = head;

            if(head != nullptr)
            {
                head->prev = newNode;
            }
            head = newNode;

            if(tail == nullptr)
            {
                tail = newNode;
            }
        }
        else
        {
            Node* current = head;

            for(int i = 0; i < number; i++)
            {
                current = current->next;
            }

            if (current != nullptr)
            {
                newNode->prev = current;
                newNode->next = current->next;

                if (current->next != nullptr)
                {
                    current->next->prev = newNode;
                }
                else
                {
                    tail = newNode;
                }

                current->next = newNode;
            }
        }
    }

    void write(const char* file)
    {
        ofstream file_1(file);
        Node *current = head;

        while (current != nullptr)
        {
            file_1.write(current->data, strlen(current->data) + 1);
            //file_1.put('\n');
            current = current->next;
        }
        
        file_1.close();
    }

    void read(const char* file)
    {
        ifstream file_1(file);
        string line;

        while (getline(file_1, line))
        {
            push_back(line.c_str());
        }

        file_1.close();
    }

    ~DoublyLinkedList()
    {
        Node *current = head;
        Node *next;

        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
        
        head = tail = nullptr;
    }
};

int main()
{
    DoublyLinkedList linked_list;

    linked_list.push_back("hi");
    linked_list.push_back("C++");
    linked_list.push_back("programming");
    linked_list.push_back("language");

    cout << "Linked List:" << endl;
    linked_list.print(linked_list.head);

    linked_list.delete_element("programming");

    cout << "Linked List after deleting:" << endl;
    linked_list.print(linked_list.head);

    linked_list.add_element("the best", 1);

    cout << "Linked List after adding:" << endl;
    linked_list.print(linked_list.head);

    linked_list.write("list.txt");

    linked_list.~DoublyLinkedList();

    cout << "Linked List after destroying:" << endl;
    linked_list.print(linked_list.head);

    linked_list.read("list.txt");

    cout << "Linked List after restoring:" << endl;
    linked_list.print(linked_list.head);

    return 0;
}