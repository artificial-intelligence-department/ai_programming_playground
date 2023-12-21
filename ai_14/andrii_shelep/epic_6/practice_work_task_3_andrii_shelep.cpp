#include <iostream>


using namespace std;


struct Node{
    int key;
    Node* next;


    Node(int val): key(val), next(nullptr){}
};


Node* createList(int num){
    Node* head = nullptr;
    Node* last = nullptr;
    int val;
    while(num!=0){
        val = num%10;
        Node* newNode = new Node(val);
        if(head==nullptr){
            head=newNode;
            last=newNode;
        } else{
            last->next=newNode;
            last=newNode;
        }
        num/=10;
    }
    return head;
}


Node* add(Node* n1, Node* n2){
    Node* node1 = n1;
    Node* node2 = n2;
    Node* head = nullptr;
    Node* last = nullptr;
    int dec = 0;
    while(node1!=nullptr || node2!=nullptr){
        int number;
        int num1, num2;
        if(node1!=nullptr){
            num1 = node1->key;
            node1=node1->next;
        } else {
            num1 = 0;
        }
        if(node2!=nullptr){
            num2 = node2->key;
            node2=node2->next;
        } else {
            num2 = 0;
        }
        number = num1 + num2 + dec;
        dec = number/10;
        Node* newNode = new Node(number%10);
        if(head==nullptr){
            head = newNode;
            last = newNode;
        } else {
            last->next=newNode;
            last = newNode;
        }
    }
    if(dec==1){
        Node* newNode = new Node(dec);
        last->next=newNode;
        last=newNode;
    }
    return head;
}


void showReverseList(Node* head){
    Node* prev = nullptr;
    Node* current = head;
    Node* next_el = nullptr;
    while(current!=nullptr){
        next_el = current->next;
        current->next = prev;
        prev=current;
        current=next_el;
    }
   
    Node* node = prev;
    while(node!=nullptr){
        cout << node->key;
        node=node->next;
    }
}


void showList(Node* head){
    Node* node = head;
    while(node!=nullptr){
        cout << node->key << " ";
        node=node->next;
    }
}


int main(){
    Node* list1 = createList(375);
    Node* list2 = createList(1858);
    cout << "list1: ";
    showList(list1);
    cout << endl;
    cout << "list2: ";
    showList(list2);
    Node* result=add(list1, list2);
    cout << endl;
    cout << "new list: ";
    showList(result);
    cout << endl;
    cout << "result: ";
    showReverseList(result);
    return 0;
}