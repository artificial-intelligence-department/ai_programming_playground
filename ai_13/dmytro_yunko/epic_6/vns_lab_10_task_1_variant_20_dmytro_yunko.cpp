#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

struct Node
{
    char* data;
    Node *next;
    Node *prev;
};
class DoublyLinkedList 
{
private:
    struct Node 
    {
        string data; 
        Node *prev;
        Node *next;

        Node(string data) 
        {
            this->data = data;
            this->prev = nullptr;
            this->next = nullptr;
        }

        
    };

    Node *head; 
    Node *end; 

public:
    DoublyLinkedList() 
    {
        head = nullptr;
        end = nullptr;
    }

    ~DoublyLinkedList() 
    {
        deleteList(); 
    }

    void printList() 
    {
        Node *current = head;
        if (current == nullptr) 
        {
            cout << "List is empty" << endl;
        }
        else 
        {
            while (current != nullptr) 
            {
                cout << current->data << " "; 
                current = current->next; 
            }
            cout << endl;
        }
    }

    void insert(string data) 
    {
        Node *newNode = new Node(data); 

        if (head == nullptr) 
        {
            head = newNode; 
            end = newNode; 
        }
        else 
        {
            end->next = newNode; 
            newNode->prev = end; 
            end = newNode; 
        }
    }

    void writeToFile(const string &filename) 
    {
        ofstream outFile(filename); 

        if (!outFile) 
        {
            cerr << "Unable to open the file: " << filename << endl;
            return;
        }

        Node *current = head; 

        while (current != nullptr) 
        {
            outFile << current->data << " "; 
            current = current->next; 
        }

        outFile.close(); 
    }

    DoublyLinkedList restoreFromFile(const string &filename) 
    {
        ifstream inFile(filename); 

        if (!inFile) 
        {
            cerr << "Unable to open the file: " << filename << endl;
            return DoublyLinkedList(); 
        }

        DoublyLinkedList list; 
        string data; 

        if (inFile.peek() == EOF) 
        {
            cout << "The file is empty." << endl;
            return list; 
        }

        while (inFile >> data) 
        {
            list.insert(data); 
        }

        inFile.close(); 
        return list; 
    }

    void deleteList() 
    {
        Node *current = head; 
        while (current != nullptr) 
        {
            Node *temp = current; 
            current = current->next; 
            delete temp; 
        }
        head = nullptr; 
        end = nullptr; 
    }

    void deleteNode(string key) 
    {
        Node *current = head; 

        while (current != nullptr && current->data != key) 
        {
            current = current->next; 
        }

        if (current == nullptr) 
        {
            cout << "Key not found in the list." << endl;
            return;
        }

        if (current->prev == nullptr) 
        {
            head = current->next; 
            if (head != nullptr) 
            {
                head->prev = nullptr; 
            }
            else 
            {
                end = nullptr; 
            }
        }
        else if (current->next == nullptr) 
        {
            end = current->prev; 
            if (end != nullptr) 
            {
                end->next = nullptr; 
            }
            else 
            {
                head = nullptr; 
            }
        }
        else 
        {
            current->prev->next = current->next; 
            current->next->prev = current->prev; 
        }

        delete current; 
    }

    void addKNodes(int K) 
    {
        srand(time(0)); 
        string alphabet = "abcdefghijklmnopqrstuvwxyz"; 
        int len = alphabet.length(); 

        for (int i = 0; i < K; i++) 
        {
            string data; 
            int n = rand() % 10 + 1; 
            for (int j = 0; j < n; j++) 
            {
                data += alphabet[rand() % len]; 
            }
            insert(data); 
        }

        Node *temp = end; 

        for (int i = 0; i < K; i++) 
        {
            string data; 
            int n = rand() % 10 + 1; 
            for (int j = 0; j < n; j++) 
            {
                data += alphabet[rand() % len]; 
            }
            insert(data); 
        }
    }
};

int main()
{
     

    int K;
    char* key = new char[20];
    cout<<"Enter the number of nodes to add at the beginning and at the end: ";
    cin>>K;
    
    cout<<"Enter the key to delete: ";
    cin>>key;
    DoublyLinkedList List;   
    
    List.insert("banana");
    
    List.insert("apple");
    List.printList();

    List.deleteNode( key);
    List.printList();

    List.addKNodes(K);
    List.printList();

    List.writeToFile("test.txt");
    List.deleteList();
    List.printList();

    DoublyLinkedList newList = List.restoreFromFile("test.txt");
    newList.printList();
    return 0;

   
   
}
