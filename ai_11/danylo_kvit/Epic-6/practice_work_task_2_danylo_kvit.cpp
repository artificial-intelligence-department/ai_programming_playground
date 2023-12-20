#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(){
        next = nullptr;
    }
};
Node* add(Node* n1, Node* n2){
    Node* sum = new Node;
    sum->data = 0;
    Node* result = sum;
    while(true){
        if(n1==nullptr&&n2 == nullptr) break;
        if(n1==nullptr){
            sum->next = new Node;
            sum->next->data = (sum->data+n2->data)/10;
            sum->data = (sum->data+n2->data)%10;
            n2 = n2->next;
            sum = sum->next;
            continue;
        }
        if(n2==nullptr){
            sum->next = new Node;
            sum->next->data = (sum->data+n1->data)/10;
            sum->data = (sum->data+n1->data)%10;
            n2 = n1->next;
            sum = sum->next;
            continue;
        }
        sum->data+=(n1->data+n2->data)%10;
        sum->next = new Node;
        sum->next->data =(n1->data+n2->data)/10;
        sum = sum->next;
        n1 = n1->next;
        n2 = n2->next;
    }
    return result;
}
int main(){
    Node* n1 = new Node;
    Node* n2 = new Node;
    n1->data = 5;
    n2->data = 5;
    n1->next = new Node;
    n2->next = new Node;
    n1->next->data = 6;
    n2->next->data = 6;
    Node* n3 = add(n1,n2);
    while(n1!=nullptr){cout << n1->data; n1 = n1->next;}
    cout << '\n';
    while(n2!=nullptr){cout << n2->data; n2 = n2->next;}
    cout << '\n';
    while(n3!=nullptr){cout << n3->data; n3 = n3->next;}
    return 0;
}