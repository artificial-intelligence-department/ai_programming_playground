#include <iostream>

using namespace std;
class Node{
public:
    int element;
    Node* left;
    Node* right;
    Node(int data) : element(data) , left(NULL) , right(NULL){}
};

class tree{
public:    
    Node* start;
tree(Node* start) : start(start){}  
    Node* mirror_flip(Node* start){
        if (start == NULL)
        return NULL;
        Node*  start2 = new Node(start->element);
        start2->left = mirror_flip(start->right);
        start2->right = mirror_flip(start->left);
        return start2;
    }
    void printl_2_r(Node* start){
    if(start != NULL){
        printl_2_r(start->left);
        cout<<start->element<<" ";
        printl_2_r(start->right);
    }
}


};
int main(){
    Node* start = new Node(1);
    start->left = new Node(2);
    start->right = new Node(3);
    start->left->left = new Node(4);
    start->left->right = new Node(5);
    tree origin(start);
    origin.printl_2_r(start);
    cout<<'\n';
    Node* newtree = origin.mirror_flip(start);
    origin.printl_2_r(newtree);
    return 0;
}