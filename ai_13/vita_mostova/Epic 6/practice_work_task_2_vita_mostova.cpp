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

void PrintList(Node *p) {  // Node *p is a local variable
    if (p==nullptr) return;  //Exit condition
    cout << p->data << " ";       // First print the value in the node
    PrintList(p->next);              // Recursive call
};
bool Compare(Node *head1, Node *head2){
    Node* h1=head1;
    Node* h2=head2;
    while(h1 || h2){
        if(!h1 || !h2) return false;
        if(h1 ->data != h2 ->data)return false;
        h1=h1->next;
        h2=h2->next;
    }
return true;
}
int main(){
    Node* head1 = nullptr;
    head1 = Insert(head1, 2);
    head1 = Insert(head1, 4);
    head1 = Insert(head1, 6);

    Node* head2 = nullptr;
    head2 = Insert(head2, 1);
    head2 = Insert(head2, 2);
    head2 = Insert(head2, 6);

    cout << "List 1: ";
    PrintList(head1);
    cout << endl;

    cout << "List 2: ";
    PrintList(head2);
    cout << endl;

    if (Compare(head1, head2)) {
        cout << "Lists are equal." << endl;
    } else {
        cout << "Lists are not equal." << endl;
    }

    return 0;
}