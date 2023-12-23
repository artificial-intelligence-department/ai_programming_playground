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
    void insert(int index, int N, int a[]){
        if(Head == NULL){
            Node* NextNode = new Node(a[0]);
            Head = NextNode;
            Node* actual_pointer = Head;
            for (int i = 1; i < N; i++)
            {
                Node* next_node = new Node(a[i]);
                actual_pointer->next = next_node;
                next_node->prev = actual_pointer;
                actual_pointer = next_node;
                next_node->next=nullptr;
                Tail = next_node;
            }
        }else{
            Node* actual_pointer = Head;
            for (int i = 0; i < index-1; i++){
                actual_pointer = actual_pointer->next;
            }
            Node* buffer1 = actual_pointer->next;
            for (int i = 0; i < N; i++){
                Node* NextNode = new Node(a[i]);
                NextNode->prev = actual_pointer;
                actual_pointer->next = NextNode;
                actual_pointer = NextNode;
            }
            actual_pointer->next = buffer1;
            buffer1->prev = actual_pointer;  
            while(actual_pointer){
                actual_pointer = actual_pointer->next;
            }
            Tail = actual_pointer->prev;
        }
    }
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
    void reverse(){
        Node* actual_pointer = Head;
        Node* Buffer = nullptr;
        while (actual_pointer != nullptr){
            Buffer = actual_pointer->prev;
            actual_pointer->prev = actual_pointer->next;
            actual_pointer->next = Buffer;
            actual_pointer = actual_pointer->prev;
        }
        Buffer = Head;
        Head = Tail;
        Tail = Buffer;
    }
    int size(){    
        Node* actual_pointer = Head;
        int size =0;
        while(actual_pointer){
            size++;
            actual_pointer = actual_pointer->next;
        }
        cout<<size<<'\n';
        return size;
    }
    bool compare(Node* head1, Node* head2){
        while((head1 != NULL) && (head2 != NULL)){
            if (head1->element != head2->element) 
            {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        if((head1 != NULL) || (head2 != NULL))
        {
            return false;
        }
        return true;
    }
};
int main(){
    doubly_linked_list list1;
    int index,N;
    cin>>index>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
    list1.insert(index, N, a);
    list1.print();
    list1.reverse();
    list1.print();

    return 0;
}