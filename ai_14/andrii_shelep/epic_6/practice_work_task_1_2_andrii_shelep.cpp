#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value): data(value), next(nullptr) {}
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

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* current = head;
    Node* next_el = nullptr;
    while(current!=nullptr){
        next_el = current->next;
        current->next = prev;
        prev=current;
        current=next_el;
    }
    return prev;
}

bool compare(Node* head1, Node* head2){
    Node* node1 = head1;
    Node* node2 = head2;
    while(node1 != nullptr && node2 != nullptr){
        if(node1->data!=node2->data || (node1->next==nullptr && node2->next!=nullptr) || (node1->next!=nullptr && node2->next==nullptr)){
            return false;
        }
        node1=node1->next;
        node2=node2->next;
    }
    return true;
}

void print(Node* head){
    if(head==nullptr){
        cout << "list is empty" << endl;
    } else{
        Node* current = head;
        while(current!=nullptr){
            cout << current->data << " ";
            current = current->next;
        }
    }
}

int main(){
    Node* list = createList(256);
    cout << "list: ";
    print(list);
    list = reverse(list);
    cout << endl << "reversed list: ";
    print(list);
    Node* list2 = createList(2652);
    cout << endl << "list2: ";
    print(list2);
    bool equal = compare(list, list2);
    cout << endl;
    if(equal == true){
        cout << "the lists are equal" << endl;
    } else{
        cout << "the lists are not equal" << endl;
    }
    return 0;
}