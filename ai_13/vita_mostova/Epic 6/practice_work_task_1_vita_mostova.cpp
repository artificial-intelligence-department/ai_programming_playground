#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* Insert(Node *head,int data) {
    Node *temp1 = new Node;
    temp1 -> data = data;
    temp1 -> next = nullptr;
    if (head == nullptr) head = temp1;
    else {
        Node *temp2= head;
        while(temp2 -> next != nullptr) {
            temp2 = temp2->next;
        }
        temp2 -> next = temp1;
    }
    return head;
};
Node *Reverse(Node *head) {
    Node *temp1 = new Node;
    Node *temp2 = new Node;
    if (head->next == nullptr) {
        return head;
    }
    else {
        temp1 =Reverse(head->next);
        temp2 =head->next;
        temp2->next = head;
        head->next = nullptr;
    }
    return temp1;
};
void PrintList(Node *p) {  // Node *p is a local variable
    if (p==nullptr) return;  //Exit condition
    cout << p->data << " ";       // First print the value in the node
    PrintList(p->next);              // Recursive call
};
int main(){
    Node *head = nullptr;   
    head = Insert(head,1);  
    head = Insert(head,2);
    head = Insert(head,3);
    head = Insert(head,4);
    PrintList(head);
    cout << endl;
    head = Reverse(head);
    PrintList(head);
    cout << endl;
    return 0;
}



