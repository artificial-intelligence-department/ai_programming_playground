#include<iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};


void show(node* head){
    node* curent = head;

    while(curent != nullptr){
        cout << curent->data << " ";
        curent = curent->next;

    }
}

bool compare(node* head, node* head2) {
    while (head != nullptr && head2 != nullptr) {
        if (head->data != head2->data) {
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }

    if (head != nullptr || head2 != nullptr) {
        return false;
    }

    return true;
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

    node* head2 = new node;
    head2->data = 8;
    node* second2 = new node;
    second2->data = 9;
    head2->next = second2;
    node* third2 = new node;
    head2->data = 10;
    second2->next = third2;
    third2->next = nullptr;

    cout << compare(head, head2);
    return 0;
}