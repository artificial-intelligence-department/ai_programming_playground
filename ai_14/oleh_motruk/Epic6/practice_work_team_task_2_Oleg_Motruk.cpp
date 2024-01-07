#include <iostream>

using namespace std;

class Node{
    private:
        int data;
        Node* next;
    public:
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }

        int get_data(){
            return data;
        }

        Node* get_next(){
            return next;
        }

        void setNext(Node* nextNode){
            next = nextNode;
        }

        static bool compare(Node* h1 , Node* h2){
            while(h1 != NULL && h2 != NULL){
                if(h1 -> data != h2 -> data){
                    return false;
                }
                h1 = h1 -> next;
                h2 = h2 -> next;
            }

            if(h1 != NULL || h2 != NULL){
                return false;
            }
            return true;
        }
};

int main(){

    Node* head = new Node(1);
    head -> setNext(new Node(2));
    head -> get_next() -> setNext(new Node(3));

    Node* head2 = new Node(1);
    head2 -> setNext(new Node(2));
    head2 -> get_next() -> setNext(new Node(3));
    head2 -> get_next() -> get_next() -> setNext(new Node(4));

    if(Node::compare(head , head2)){
        cout << "Lists are qual";
    }
    else{
        cout << "Lists are diffetent";
    }


    return 0;
}