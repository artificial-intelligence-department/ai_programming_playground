#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int get_data()
{
    int data;
    cout << "Enter data: ";
    cin >> data;
    cout << endl;
    return data;
}

int get_size()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    cout << endl;
    return size;
}

Node* create_empty_list()
{
    return nullptr;
}

void add(Node*& head, int data)
{
    Node* new_node = new Node;
    new_node->data = data;
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
}

void fill_list(Node*& head)
{
    int size = get_size();
    for(int i = 0; i < size; i++)
    {
        add(head, get_data());
    }
}

void print(const Node* head)
{
    const Node* current = head;
    if(current == nullptr)
    {
        cout << "List is empty";
    }
    else
    {
        cout << "List: ";
        while(current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
    cout << endl << endl;
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

bool compare_lists(Node*& head_1, Node*& head_2)
{
    Node* current_1 = head_1;
    Node* current_2 = head_2;
    while(current_1 != nullptr && current_2 != nullptr)
    {
        if((current_1->next != nullptr && current_2->next == nullptr) || (current_1->next == nullptr && current_2->next != nullptr))
        {
            return false;
        }
        if(current_1->data != current_2->data)
        {
            return false;
        }
        current_1 = current_1->next;
        current_2 = current_2->next;
    }
    return true;
}

int get_list_number(Node* head)
{
    int number = 0;
    Node* reversed_list = reverse_list(head);
    if(head == nullptr)
    {
        return 0;
    }
    while(reversed_list != nullptr)
    {
        number = number * 10 + reversed_list->data;
        reversed_list = reversed_list->next;
    }
    return number;
}

Node* add_lists(Node* head_1, Node* head_2)
{
    Node* result_head = create_empty_list();
    int result = get_list_number(head_1) + get_list_number(head_2);
    while(result != 0)
    {
        add(result_head, result % 10);
        result /= 10;
    }
    return result_head;
}

int main()
{
    cout << "---Task 1: Reverse list---" << endl << endl;
    cout << "Enter first list: " << endl << endl;
    Node* head_1 = create_empty_list();
    fill_list(head_1);
    print(head_1);
    head_1 = reverse_list(head_1);
    cout << "Reversed ";
    print(head_1);
    cout << "---Task 2: Compare lists---" << endl << endl;
    cout << "Enter second list: " << endl << endl;
    Node* head_2 = create_empty_list();
    fill_list(head_2);
    print(head_2);
    if(compare_lists(head_1, head_2))
    {
        cout << "Lists are equal" << endl << endl;
    }
    else
    {
        cout << "Lists are not equal" << endl << endl;
    }
    cout << "---Task 3: Adding big numbers---" << endl << endl;
    Node* result = add_lists(head_1, head_2);
    print(result);
}
