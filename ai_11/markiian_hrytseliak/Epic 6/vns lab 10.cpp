#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

struct Node 
{
    char* key;
    Node* next;
    Node* prev;

    Node(const char* k) : key(strdup(k)), next(nullptr), prev(nullptr) {}

    ~Node() {
        free(key);
    }
    int getIndex() const {
    int index = 0;
    const Node* current = this;

    while (current != nullptr) {
        if (strcmp(current->key, key) == 0) {
            return index;
        }

        current = current->next;
        index++;
    }
    return -1;
    }

};

class DoublyLinkedList 
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        destroyList();
    }

    void createList() {
        destroyList();
        head = tail = nullptr;
    }

    void addNode(const char* key) {
        Node* newNode = new Node(key);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeNodes(int* indices, int count) {
        vector<int> indicesToRemove;

        Node* current = head;
        int index = 0;

        while (current) {
            for (int i = 0; i < count; ++i) {
                if (indices[i] == index) {
                    indicesToRemove.push_back(index);
                }
            }
             current = current->next;
            ++index;
        }
    }
void removeNodeByIndex(int index) {
    Node* current = head;
    int currentIndex = 0;

    
    while (current && currentIndex < index) {
        current = current->next;
        ++currentIndex;
    }

    
    if (current && currentIndex == index) {
        removeNode(current);
    }
}
    void addToStart(int k, const char* key) 
    {
        for (int i = 0; i < k; ++i) 
        {
            Node* newNode = new Node(key);
            if (!head) 
            {
                head = tail = newNode;
            } 
            else 
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
    }

    void printList() const 
    {
        Node* current = head;
        while (current) 
        {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

    void writeToFile(const string& filename) const 
    {
        ofstream file(filename);
        if (!file.is_open()) 
        {
            cerr << "Error opening file " << filename << " for writing!" << endl;
            return;
        }

        Node* current = head;
        while (current) 
        {
            file << current->key << endl;
            current = current->next;
        }

        file.close();
    }

    void restoreFromFile(const string& filename) 
    {
        ifstream file(filename);
        if (!file.is_open()) 
        {
            cerr << "Error opening file " << filename << " for reading!" << endl;
            return;
        }

        destroyList();
        char buffer[256];
        while (file.getline(buffer, sizeof(buffer))) 
        {
            addNode(buffer);
        }

        file.close();
    }

private:
    void destroyList() 
    {
        Node* current = head;
        while (current) 
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
    }

    void removeNode(Node* node) 
    {
        if (node->prev) 
        {
            node->prev->next = node->next;
        } 
        else 
        {
            head = node->next;
        }

        if (node->next) 
        {
            node->next->prev = node->prev;
        } 
        else 
        {
            tail = node->prev;
        }

        delete node;
    }
};

int main() {
    DoublyLinkedList myList;
    const string path = "C:/Users/Gil/OneDrive/Documents/GitHub/desktop-tutorial/Programming/Code/Epic 6/";
    const string filename = "myList.txt";
    string file = path+filename;
    {"Oppenheimer", "Cristopher Nolan", "USA", 0.9},
        {"Titanic", "James Cameron", "USA", 0.5},
        {"Inglorious Basterds", "Quentin Tarantino", "France", 0.5},
        {"Killers of the flower moon", "Martin Scorseze", "Usa", 0.4},
        {"Napoleon", "Ridley Scott", "France", 0.4}


    myList.createList();
    myList.addNode("One");
    myList.addNode("Two");
    myList.addNode("Three");
    myList.addNode("Four");
    myList.addNode("Five");

    cout << "Original list:" << endl;
    myList.printList();

    int count1;
    cout<<"enter amount of elements you want to remove(no more than 5): ";
    cin>>count1;

    for(int i=0; i<count1; i++)
    {
        cout<<"Enter element you want to remove: ";
        int index;
        cin>>index;
        myList.removeNodeByIndex(index-1);
    }

    cout<<"Enter amount of elements 'Zero' you want to add :";
    int count2;
    cin>>count2;
    
    myList.addToStart(count2, "Zero");

    cout << "Modified list:" << endl;
    myList.printList();

    myList.writeToFile(file);

    myList.restoreFromFile(file);

    cout << "Restored list:" << endl;
    myList.printList();

    return 0;
}