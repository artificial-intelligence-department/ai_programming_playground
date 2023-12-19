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
        }
    }
    void erase(int index, int N){
        if(index != 0){
            Node* actual_pointer = Head;
                for (int i = 0; i < index; i++){
                    actual_pointer = actual_pointer->next;
                }
            Node* buffer1 = actual_pointer->prev;
            for (int i = 0; i < N; i++)
            {
                actual_pointer = actual_pointer->next;
            }
            actual_pointer->prev = buffer1;
            buffer1->next = actual_pointer;
        }else{
            Node* actual_pointer = Head;
            for (int i = 0; i < N; i++)
            {
                actual_pointer = actual_pointer->next;
            }
            Head = actual_pointer;
        }
    }
    void size(){    
        Node* actual_pointer = Head;
        int size =0;
        while(actual_pointer){
            size++;
            actual_pointer = actual_pointer->next;
        }
        cout<<size<<'\n';
    }
    void get(int index){
        Node* actual_pointer = Head;
        for (int i = 0; i < index; i++)
        {
            actual_pointer = actual_pointer->next;
        }
        cout<<actual_pointer->element<<'\n';
    }
    void set(int index, int value){
        Node* actual_pointer = Head;
        for (int i = 0; i < index; i++)
        {
            actual_pointer = actual_pointer->next;
        }
        actual_pointer->element = value;
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
        }
    }
};

int main(){
    doubly_linked_list list;
    int Q=0,index,N,value;
    cin>>Q;
    for (int i = 0; i < Q; i++)
    {
        string option;
        cin>>option;
        if(option == "insert"){
            cin>>index>>N;
            int a[N];
            for (int i = 0; i < N; i++)
            {
                cin>>a[i];
            }
            list.insert(index, N, a);
        }
        switch (option[0]){
            case 'e':
                cin>>index>>N;
                list.erase(index, N);
                break;
            case 's':
                if (option =="size"){
                    list.size();
                }else{
                    cin>>index>>value;
                    list.set(index, value);
                }
                break;
            case 'g':
                cin>>index;
                list.get(index);
                break;
            case 'p':
                list.print();
                break;
        }   
    }
    
    
    return 0;
}