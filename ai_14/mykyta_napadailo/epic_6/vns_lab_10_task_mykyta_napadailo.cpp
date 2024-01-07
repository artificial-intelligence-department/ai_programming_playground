#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Node 
{
    char* key;
    Node* prev;
    Node* next;
};
struct DLL 
{
    Node* head;
    Node* tail;
};

DLL* create_List();
void AddNode(DLL* list, const char* data);
void DeleteNode(DLL* list, const char* target);
void PrintList(DLL* list);
void Write2File(DLL* list, const char* name);
void DeleteList(DLL* list);
DLL* RestoreFromFile(const char* filename);

int main()
{
    DLL* list_ptr = create_List();
    AddNode(list_ptr, "programming");
    AddNode(list_ptr, "like");
    AddNode(list_ptr, "not");
    AddNode(list_ptr, "do");
    AddNode(list_ptr, "I");

    DeleteNode(list_ptr, "not");
    Write2File(list_ptr, "list_backup.txt");
    DeleteList(list_ptr);
    DLL* list = RestoreFromFile("list_backup.txt");
    DeleteList(list);
}

DLL* create_List()
{
    DLL* list = new DLL;
    list -> head = list -> tail = nullptr;
    return list;
}

void AddNode(DLL* list, const char* data)
{
    Node* new_Node = new Node;
    new_Node -> key = new char[strlen(data) + 1];
    strcpy(new_Node -> key, data);
    new_Node -> prev = nullptr;
    new_Node -> next = list -> head;

    if (list -> head != nullptr) {
    list -> head -> prev = new_Node;
    }
    list -> head = new_Node;
    if (list -> tail == nullptr) 
    {
        list -> tail = new_Node;
    }
    PrintList(list);
}

void DeleteNode(DLL* list, const char* target)
{
    Node* current = list -> head;
    while (current != nullptr)
    {
        if (strcmp(current -> key, target) == 0)
        {
            if (current == list -> head)
            {
                list -> head = current -> next;
            }
            else
            {
                current -> prev -> next = current -> next;
                if (current -> next != nullptr)
                {
                    current -> next -> prev = current -> prev;
                }
            }
            delete[] current -> key;
            delete current;
            PrintList(list);
            return;
        }
        
        current = current -> next;
    }
    PrintList(list);
}

void PrintList(DLL* list)
{
    Node* current = list -> head;
    if (current == nullptr)
    {
        cout << "Ooops, this list is empty...\n";
        return;
    }
    while (current != nullptr)
    {
        cout << current -> key << ' ';
        current = current -> next;
    }
    cout << endl;
}

void Write2File(DLL* list, const char* name)
{
    ofstream fout(name);
    if (!fout)
    {
        cerr << "Failed to write a list into the file\n";
        return;
    }
    Node* current = list -> head;
    while (current != nullptr)
    {
        fout << current -> key << endl;
        current = current -> next;
    }
    fout.close();
}

void DeleteList(DLL* list)
{
    Node* current = list -> head;
    while (current != nullptr)
    {
        Node* tmp = current;
        current = current -> next;
        delete tmp;
    }
    list -> head = list -> tail = nullptr;
    PrintList(list);
}

DLL* RestoreFromFile(const char* filename)
{
    ifstream fin (filename);
    if (!fin)
    {
        cerr << "Failed to open the file\n";
        return nullptr;
    }
    DLL* list = create_List();
    char line[256];
    while (fin.getline(line, 256))
    {
        AddNode(list, line);
    }
    fin.close();

    Node* current = list -> head;
    Node* tmp = nullptr;
    while (current != nullptr)
    {
        tmp = current -> prev;
        current -> prev = current -> next;
        current -> next = tmp;

        current = current -> prev;
    }
    if (tmp != nullptr)
    {
        list -> head = tmp -> prev;
    }
    PrintList(list);
    return list;
}