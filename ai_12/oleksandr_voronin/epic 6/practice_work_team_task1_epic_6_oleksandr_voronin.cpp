#include <iostream>

using namespace std;

struct Node
{
    int x;
    Node* next;
};

Node* reverse(Node* head) {
    
    Node* cur = head;
    Node* next = nullptr;
    Node* prev = nullptr;

    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev; 
}


void printList(Node* head) {
    while (head != nullptr) {
        cout << head->x << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){

    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* tail = new Node();
    head->x=1;
    head ->next = second;
    second->x=2;
    second->next = third;
    third->x=3;
    third->next=tail;
    tail->x=4;
    tail->next=nullptr;

    printList(head);

    head = reverse(head);

    printList(head);

}