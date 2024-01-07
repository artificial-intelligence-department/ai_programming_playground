#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value),next(nullptr) {}
};
void add(Node* &head, int value){
    Node* m = new Node(value);
    m->next = head;
    head = m;}
bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    if (h1 != nullptr || h2 != nullptr) {
        return false;
    }
    return true;
}
int main() {
    int N;
    bool rez;
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    cout<<"How many numbers you want to add in first list?  ";
    cin>>N;
    cout<<"Enter a first list:  ";
    for(int i=0; i<N; i++) {
        int k;
        cin>>k;
        add(head1, k);
    }
    cout<<"How many numbers you want to add in second list?  ";
    cin>>N;
    cout<<"Enter a second list:  ";
    for(int i=0; i<N; i++) {
        int k;
        cin>>k;
        add(head2, k);
    }
    rez=compare(head1, head2);
    if(rez) cout<<"The lists are the same";
    else cout<<"The list are different";
}
