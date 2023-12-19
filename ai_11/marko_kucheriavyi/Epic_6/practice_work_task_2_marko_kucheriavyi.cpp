#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* sum(Node* head1, Node* head2){
    Node* sum = new Node(0); 
    Node* current = sum;
    int ost = 0;

    while (head1 != nullptr || head2 != nullptr || ost != 0){
        int value1 = (head1 != nullptr) ? head1->data : 0;
        int value2 = (head2 != nullptr) ? head2->data : 0;

        int sum = value1 + value2 + ost;
        ost = sum / 10;

        current->next = new Node(sum % 10);
        current = current->next;

        if (head1 != nullptr) head1 = head1->next;
        if (head2 != nullptr) head2 = head2->next;
    }

    return sum->next;
}

void printList(Node* node){
    while (node != nullptr){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main(){
    Node* head1 = new Node(9);
    head1->next = new Node(7);
    head1->next->next = new Node(3);

    Node* head2 = new Node(4);
    head2->next = new Node(2);
    head2->next->next = new Node(1);

    Node* sumResult = sum(head1, head2);
    printList(sumResult);

    return 0;
}