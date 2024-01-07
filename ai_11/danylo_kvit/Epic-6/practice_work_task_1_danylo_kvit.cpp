#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int n): data(n), next(nullptr){}
};
bool equ(Node* n1,Node*n2){
    if(n1==nullptr&&n2==nullptr) return 1;
    if(n1==nullptr||n2==nullptr) return 0;
    if(n1->data!=n2->data) return 0;
    return equ(n1->next,n2->next);
};
Node* reverse(Node* h, Node* prev){
    if(h == nullptr) return prev;
    Node* p = h->next;
    h->next = prev;
    return reverse(p,h);
}
Node* reverse(Node* h){
    return reverse(h, nullptr);
}
Node* make(int size){
    cout << "Enter a_0:\n";
    int x;
    cin >> x;
    Node* head = new Node(x);
    Node* ans = head;
    for(int i=1;i<size;i++){
        cout << "Enter a_" << i << ":\n";
        cin >> x;
        Node* p = new Node(x);
        head->next = p;
        head = p;
    }
    return ans;
}
void print(Node* h){
    if(h == nullptr){
        cout << '\n';
        return;
    }
    cout << h->data << ' ';
    print(h->next);
}
int main(){
    Node* h1 = make(3);
    print(h1);
    h1 = reverse(h1);
    print(h1);
    Node* h2 = make(3);
    print(h2);
    cout << equ(h1,h2);
}