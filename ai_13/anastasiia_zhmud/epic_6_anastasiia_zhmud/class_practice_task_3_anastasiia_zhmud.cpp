#include <iostream>
#include<cmath>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value),next(nullptr) {}
};
void push(Node* &head, int value){
    Node* m = new Node(value);
    m->next = head;
    head = m;
}
int convert(Node* h, int N){
    int rez = 0;
    Node* current = h;
    
    for(int i = 0; i < N; i++){
        rez = rez * 10 + current->data;
        current = current->next;
    }
    return rez;
}
int main(){
    int N,n, rez=0;
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    cout<<"How many numbers you want to add in first list?  ";
    cin>>N;
    cout<<"Enter a first list:  ";
    for(int i=0; i<N; i++) {
        int k;
        cin>>k;
        push(head1, k);
    }
    cout<<"How many numbers you want to add in second list?  ";
    cin>>n;
    cout<<"Enter a second list:  ";
    for(int i=0; i<n; i++) {
        int k;
        cin>>k;
        push(head2, k);
    }
    rez=convert(head1, N)+convert(head2, n);
    cout<<rez;
}