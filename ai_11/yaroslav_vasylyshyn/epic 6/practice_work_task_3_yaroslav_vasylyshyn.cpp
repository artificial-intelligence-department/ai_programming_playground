#include <iostream>

using namespace std;

class Node{
public:
    int element;
    Node* next;
    Node* prev;
    Node(int data) : element(data) , prev(NULL) , next(NULL){} 
};

Node* dodavanya(Node* head1, Node* head2){
    Node* Head = NULL;
    Node* Tail = NULL;
    int sum_10 = 0;
    while((head1 != NULL) || (head2 != NULL) || (sum_10 != 0)){
        int sum = sum_10;
        if(head1 != NULL){
            sum += head1->element;
            head1 = head1->next;
        }
        if(head2 != NULL){
            sum += head2->element;
            head2 = head2->next;
        }
        int ostacha = sum%10;
        sum_10 = sum/10;
        Node* node = new Node(ostacha);
        if(Head == NULL)
            Head = Tail = node;
        else{
            Tail->next = node;
            Tail = node;
        }
    }
    return Head;
}

void print(Node* Head){
    if(Head == NULL)
        cout<<"список порожній:(";
    else{
        Node* actual_pointer = Head;
        while(actual_pointer){
        cout<<actual_pointer->element<<" ";
        actual_pointer = actual_pointer->next;
        }
        cout<<'\n';
    }
}

int main() {
    Node* num1 = new Node(4);
    num1->next = new Node(4);
    num1->next->next = new Node(4);

    Node* num2 = new Node(4);
    num2->next = new Node(4);
    num2->next->next = new Node(4);
    num2->next->next->next = new Node(1);

    Node* res = dodavanya(num1, num2);
    print(res);

    return 0;
}