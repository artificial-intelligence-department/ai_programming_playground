#include <iostream>

using namespace std;

class Node{
public:
    int element;
    Node* next;
    Node* prev;
    Node(int data) : element(data) , prev(NULL) , next(NULL){} 
};

class doubly_linked_list{
private:
    Node* Head;
    Node* Tail;
public:
    doubly_linked_list(): Head(NULL){}
    void print(){
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
    bool compare(Node* head1, Node* head2){
        while((head1 != NULL) && (head2 != NULL)){
            if (head1->element != head2->element) 
            {
                cout<<"false";
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        if((head1 != NULL) || (head2 != NULL))
        {
            cout<<"false";
            return false;
        }
        cout<<"true";
        return true;
    }
};

int main(){
    doubly_linked_list list1;
    doubly_linked_list list2;
    Node* Head1 = new Node(1);
    Head1->next = new Node(2);
    Head1->next->next = new Node(3);
    Node* Head2 = new Node(1);
    Head2->next = new Node(2);
    Head2->next->next = new Node(3);
    list1.compare(Head1 , Head2);
    return 0;
}