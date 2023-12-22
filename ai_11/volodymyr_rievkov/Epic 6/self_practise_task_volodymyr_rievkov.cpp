#include<iostream>
using namespace std;

const char* file_name = "list_file.txt";
int elements_count;
bool app_exit = false;

struct Node 
{
    int data;           
    Node* next;         
};

void add(Node*& head, int number) 
{
    Node* new_node = new Node;
    new_node->data = number;   
    new_node->next = nullptr;   
    if (head == nullptr) 
    {
        head = new_node;
    } 
    else 
    {
        Node* current = head;
        while (current->next != nullptr) 
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void fill_list(Node*& head)
{
    FILE* file = fopen(file_name, "wb");
    if(file != nullptr)
    {
        int elements_number;
        int element;
        int count = 0;
        cout << "Enter number of elements: ";
        cin >> elements_number;
        for(int i = 0; i < elements_number; i++)
        {
            cout << ": ";
            cin >> element;
            add(head, element);
            if(fwrite(&element, sizeof(int), 1, file) != 1)
            {
                cout << "Error: File writing is failed" << endl;
            } 
            count++;
        }
        if(fclose(file) != 0)
        {
            cout << "Error: File closing is failed" << endl;
        }  
        elements_count = count; 
    }
    else
    {
        cout << "Error: File opening is failed" << endl;
    }
    cout << endl;
}

void print_list(const Node* head) 
{
    const Node* current = head;
    if(current == nullptr)
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
    }   
    cout << endl << endl;
}

void clear_list(Node*& head) 
{
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void restore_list(Node*& head)
{
    if(head != nullptr)
    {
        clear_list(head);
    }
    FILE* file = fopen(file_name, "rb");
    if(file != nullptr)
    {
        int element;
        for(int i = 0; i < elements_count; i++)
        {
            if(fread(&element, sizeof(int), 1, file) == 1)
            {
                add(head, element);
            }
            else
            {
                cout << "Error: File reading is failed" << endl << endl;
                break;
            }
        }
        if(fclose(file) != 0)
        {
            cout << "Error: File closing is failed" << endl << endl;
        }
    }
    else
    {
        cout << "Error: File reading is failed" << endl << endl;
    }
}

void swap_nodes_values(Node*& node_1, Node*& node_2) 
{
    int temp = node_1->data;
    node_1->data = node_2->data;
    node_2->data = temp;
}

void sort_list_by_asc(Node*& head)
{
    int swapped;    
    Node* current;     
    Node* last = nullptr; 
    if (head == nullptr)
    {
        return;
    }
    do {
        swapped = 0; 
        current = head;  
        while (current->next != last) 
        {
            if (current->data > current->next->data) 
            {
                swap_nodes_values(current, current->next);  
                swapped = 1;
            }
            current = current->next;  
        }
        last = current;  
    } while (swapped);
}

void sort_list_by_desc(Node*& head)
{
    int swapped;    
    Node* current;     
    Node* last = nullptr; 
    if (head == nullptr)
    {
        return;
    }
    do 
    {
        swapped = 0; 
        current = head;  
        while (current->next != last) 
        {
            if (current->data < current->next->data) 
            {
                swap_nodes_values(current, current->next);  
                swapped = 1;
            }
            current = current->next;  
        }
        last = current;  
    } while (swapped);
}

int get_action()
{
    int action;
    do
    {
        cout << " - Print list(1)" << endl
            << " - Sort list asc(2)" << endl
            << " - Sort list desc(3)" << endl 
            << " - Clear list(4)" << endl 
            << " - Restore list(5)" << endl 
            << " - Exit(6)" << endl 
            << "Enter action: ";
        cin >> action; 
    } while (action < 1 && action > 6);
    return action;
}

void list_managment()
{
    Node* head = nullptr;  
    fill_list(head);
    while(!app_exit)
    {
        switch(get_action())
        {
            case 1:
                print_list(head);
                break;
            case 2:
                sort_list_by_asc(head);
                cout << "List is sorted by asc" << endl << endl;
                break;
            case 3:
                sort_list_by_desc(head);
                cout << "List is sorted by desc" << endl << endl;
                break;
            case 4:
                clear_list(head);
                break;
            case 5:
                restore_list(head);
                break;
            case 6: 
                app_exit = true; 
                remove(file_name);
                break;
        }
    }
}

int main() 
{
    list_managment();
}