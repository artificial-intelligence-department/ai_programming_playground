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
    void printl_2_r(Node* start){
        if(start != NULL){
            printl_2_r(start->left);
            cout<<start->element<<" ";
            printl_2_r(start->right);
        }
    }
    void sum(Node* start){
        if(start == NULL)
            return;
        sum(start->left);
        sum(start->right);
        if (start->left != NULL)
            start->element += start->left->element;
        if (start->right != NULL)
            start->element += start->right->element;
    }
};

int main(){
    Node* start = new Node(10);
    start->left = new Node(5);
    start->right = new Node(15);
    start->left->left = new Node(3);
    start->left->right = new Node(6);
    tree origin(start);
    origin.printl_2_r(start);
    cout<<'\n';
    origin.sum(start);
    origin.printl_2_r(start);
    return 0;
}