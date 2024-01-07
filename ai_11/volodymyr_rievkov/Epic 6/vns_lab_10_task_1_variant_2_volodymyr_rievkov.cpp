#include <iostream>
using namespace std;

const char* data_file_name = "data_file.txt";
const char* key_file_name = "key_file.txt";
int node_count = 0;

struct Node
{
    int data;
    int key;
    Node* next;        
};

Node* create_empty_linked_list()
{
    return nullptr;
}

void add_to_file(int data, int key)
{
    FILE* d_file = fopen(data_file_name, "ab");
    FILE* k_file = fopen(key_file_name, "ab");
    if(d_file != nullptr && k_file != nullptr)
    {
        if(fwrite(&data, sizeof(int), 1, d_file) != 1 || fwrite(&key, sizeof(int), 1, k_file) != 1)
        {
            cout << "Error: Files writing is failed" << endl << endl;
        }
        if(fclose(d_file) != 0 || fclose(k_file) != 0)
        {
            cout << "Error: Files closing is failed" << endl << endl;
        }
    }
    else
    {
        cout << "Error: Files opening is failed" << endl << endl;
    }
}

void remove_from_file(int data, int key)
{
    const char* temp_d_file_name = "temp_data_file.txt";
    const char* temp_k_file_name = "temp_key_file.txt";
    FILE* d_file = fopen(data_file_name, "rb");
    FILE* k_file = fopen(key_file_name, "rb");
    FILE* temp_d_file = fopen(temp_d_file_name, "wb");
    FILE* temp_k_file = fopen(temp_k_file_name, "wb");
    int f_data;
    int f_key;
    if(d_file != nullptr && k_file != nullptr && temp_d_file != nullptr && temp_k_file != nullptr)
    {
        while(fread(&f_data, sizeof(int), 1, d_file) == 1 && fread(&f_key, sizeof(int), 1, k_file) == 1)
        {
            if(f_data != data && f_key != key)
            {
                if(!fwrite(&f_data, sizeof(int), 1, temp_d_file) || !fwrite(&f_key, sizeof(int), 1, temp_k_file))
                {
                    cout << "Error: File writing is failed" << endl << endl;
                }
            }
        }
        if(fclose(d_file) != 0 || fclose(k_file) != 0 || fclose(temp_d_file) != 0 || fclose(temp_k_file) != 0)
        {
            cout << "Error: File closing is failed" << endl << endl;
        }
    }
    else
    {
        cout << "Error: Files opening is failed" << endl << endl;
    }
    d_file = fopen(data_file_name, "wb");
    k_file = fopen(key_file_name, "wb");
    temp_d_file = fopen(temp_d_file_name, "rb");
    temp_k_file = fopen(temp_k_file_name, "rb");
    if(d_file != nullptr && k_file != nullptr && temp_d_file != nullptr && temp_k_file != nullptr)
    {
        while(fread(&f_data, sizeof(int), 1, temp_d_file) == 1 && fread(&f_key, sizeof(int), 1, temp_k_file) == 1)
        {
            if(!fwrite(&f_data, sizeof(int), 1, d_file) || !fwrite(&f_key, sizeof(int), 1, k_file))
            {
                cout << "Error: File writing is failed" << endl << endl;
            }
        }
        if(fclose(d_file) != 0 || fclose(k_file) != 0 || fclose(temp_d_file) != 0 || fclose(temp_k_file) != 0)
        {
            cout << "Error: File closing is failed" << endl << endl;
        }
    }
    else
    {
        cout << "Error: Files opening is failed" << endl << endl;
    }
    remove(temp_d_file_name);
    remove(temp_k_file_name);
}

void print_list(const Node* head) 
{
    const Node* current = head;
    if(current == nullptr)
    {
        cout << "List is empty";
    }
    else
    {
        cout << "List: ";
        while (current != nullptr) 
        {
            cout << current->data << "{" << current->key << "} ";
            current = current->next;
        }
    }   
    cout << endl << endl;
}

int get_data()
{
    int data;
    cout << "Enter data: ";
    cin >> data;
    cout << endl;
    return data;
}

int get_key()
{
    int key;
    cout << "Enter key: ";
    cin >> key;
    cout << endl;
    return key;
}

void add(Node*& head, int data, int key)
{
    Node* new_node = new Node;
    new_node->data = data;   
    new_node->key = key;
    new_node->next = nullptr;   
    if (head == nullptr) 
    {
        head = new_node;
    } 
    else 
    {
        Node* last = head;
        while (last->next != nullptr) 
        {
            last = last->next;
        }
        last->next = new_node;
    }  
    cout << "Element with data '" << data << "' and key '" << key << "' was successfully added" << endl << endl;
}

void add_before_key(Node*& head, int key, int new_data, int new_key)
{
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr && current->key != key)
    {
        prev = current;
        current = current->next;
    }
    if (current != nullptr)
    {
        Node* new_node = new Node;
        new_node->data = new_data;
        new_node->key = new_key;  
        new_node->next = current;
        if (prev == nullptr)
        {
            head = new_node;
        }
        else
        {
            prev->next = new_node;
        }
        add_to_file(new_data, new_key);
        cout << "Element with data '" << new_data << "' and key '" << new_key << "' was successfully added" << endl << endl;
    }
    else
    {
        cout << "Error: Element with key '" << key << "' wasn't found" << endl << endl;
    }
}

void remove_by_key(Node*& head, int key)
{
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr && current->key != key)
    {
        prev = current;
        current = current->next;
    }
    if (current != nullptr)
    {
        if (prev == nullptr)
        {
            head = current->next;
        }
        else
        {
            prev->next = current->next;
        }
        remove_from_file(current->data, current->key);
        cout << "Element '" << current->data << " with key '" << current->key << "' was successfully removed" << endl << endl;
        delete current;
    }
    else
    {
        cout << "Error: Element with key '" << key << "' wasn't found" << endl << endl;
    }
}

void clear_list(Node*& head) 
{
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "List was successfully cleared" << endl << endl;
}

Node* reverse_list(Node* head) 
{
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while (current != nullptr) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void restore_list(Node*& head)
{
    if(head != nullptr)
    {
        clear_list(head);
    }
    FILE* d_file = fopen(data_file_name, "rb");
    FILE* k_file = fopen(key_file_name, "rb");
    if(d_file != nullptr && k_file != nullptr)
    {
        int f_data;
        int f_key;
        while(fread(&f_data, sizeof(int), 1, d_file) == 1 && fread(&f_key, sizeof(int), 1, k_file) == 1)
        {
            add(head, f_data, f_key);
        }
        cout << "List has been restored" << endl << endl;
        head = reverse_list(head);
        if(fclose(d_file) != 0 || fclose(k_file) != 0)
        {
            cout << "Error: File closing is failed" << endl << endl;
        }
    }
    else
    {
        cout << "Error: File opening is failed" << endl << endl;
    }
}

int main()
{
    int data;
    int key;
    Node* head = create_empty_linked_list();
    cout << "Enter element" << endl << endl;
    data = get_data();
    key = get_key();
    add(head, data, key);
    add_to_file(data, key); 
    cout << "Enter element" << endl << endl;
    data = get_data();
    key = get_key();
    add(head, data, key);
    add_to_file(data, key); 
    print_list(head);
    cout << "Enter key to remove" << endl << endl;
    key = get_key();
    remove_by_key(head, key);
    print_list(head);
    cout << "Enter key to add element before" << endl << endl;
    key = get_key();
    cout << "New" << endl << endl;
    int new_data = get_data();
    cout << "New" << endl << endl;
    int new_key = get_key();
    add_before_key(head, key, new_data, new_key);
    print_list(head);
    clear_list(head);
    print_list(head);
    restore_list(head);
    print_list(head);
    clear_list(head);
    remove(data_file_name);
    remove(key_file_name);
}