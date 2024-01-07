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
    head = m;
}
void print(Node* m) {
    while (m != nullptr) {
        cout << m->data << " ";
        m = m->next;
    }
    cout << endl;
}
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
int main() {
    int N;
    Node* head = nullptr;
    cout<<"How many numbers you want to add?  ";
    cin>>N;
    cout<<"Enter a numbers:  ";
    for(int i=0; i<N; i++) {
        int k;
        cin>>k;
        add(head, k);}
    head = reverse(head);
    cout<<"Initial list:  ";
    print(head);
    head = reverse(head);
    cout << "Revered list:  ";
    print(head);
}