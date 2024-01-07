#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};


void show(Node* head){
    Node* curent = head;
    
    while(curent != nullptr){
        cout << curent->data << " ";
        curent = curent->next;

    }
}

bool compare(Node* head, Node* head2) {
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
    Node* head = nullptr;

    head = new Node{3, nullptr};
    head->next = new Node{5, nullptr};
    head->next->next = new Node{45, nullptr};
    head->next->next->next = new Node{11, nullptr};

    Node* head2 = nullptr;    
    
    head2 = new Node{1, nullptr};
    head2->next = new Node{33, nullptr};
    head2->next->next = new Node{42, nullptr};
    head2->next->next->next = new Node{5, nullptr};
    
    cout << compare(head, head2);
    return 0;
}