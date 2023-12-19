#include<iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

void show(node* head){
    node* current = head;

    while(current != nullptr){
        cout << current->data << " ";
        current = current->next;

    }
}

node* reverse(node* head) {
    node *prev = nullptr, *current = head, *nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

int main(){
    node* head = new node;
    head->data = 0;
    node* second = new node;
    second->data = 2;
    head->next = second;
    node* third = new node;
    head->data = 3;
    second->next = third;
    third->next = nullptr;
    show(head);
    head = reverse(head);
    cout << endl;
    show(head);
    return 0;
}