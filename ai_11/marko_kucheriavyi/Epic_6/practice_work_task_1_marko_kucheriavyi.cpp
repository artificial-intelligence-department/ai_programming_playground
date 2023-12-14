#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

bool compare(Node* node1, Node* node2){
    if (node1 == nullptr && node2 == nullptr) return true;
    if (node1 == nullptr || node2 == nullptr) return false;
    else if (node1->data != node2->data) return false;
    else return compare(node1->next, node2->next);
}

Node* reverseList(Node* head){
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

Node* createList(int size){
    Node* head = new Node (1);

    Node* current = head;

    for (int i = 2; i <= size; i++){
        Node* NewNode = new Node(i);
        current->next = NewNode;
        current = current->next;
    }
    return head;
}

void printlist(Node* node){
    while (node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main(){
    Node* head1 = createList(3);
    printlist(head1);

    // head1 = reverseList(head1); 
    // printlist(head);

    Node* head2 = new Node (1);
    head2->next = new Node (2);
    head2->next->next = new Node (3);
    head2->next->next->next = new Node (4);

    printlist(head2);

    cout << (compare(head1, head2) ? "Lists are equal" : "Lists are different");
    return 0;
}