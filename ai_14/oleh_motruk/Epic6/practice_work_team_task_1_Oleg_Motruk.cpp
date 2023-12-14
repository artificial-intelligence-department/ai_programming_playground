#include <iostream>

using namespace std;

class Node{
    private:
        int data;
        Node* next;
    
    public:
        Node(int data){
            this->data = data;
            this->next = NULL;
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

        static Node* reverse(Node* head){
            Node* prev = NULL;
            Node* current = head;
            Node* next = NULL;

            while(current != NULL){
                next = current -> get_next();
                current -> setNext(prev);
                prev = current;
                current = next;
            }
            return prev;
        }

        static void print(Node* node){
            while(node != NULL){
                cout << node -> get_data() << " ";
                node = node -> get_next();
            }
            cout << endl;
        }
};



int main(){

    Node* head = new Node(1);
    head -> setNext(new Node(2));
    head -> get_next() -> setNext(new Node(3));
    head -> get_next() -> get_next() -> setNext(new Node(4));
    head -> get_next() -> get_next() -> get_next() -> setNext(new Node(5));

    cout << "Before reverse: ";

    Node::print(head);

    Node* reserve = Node::reverse(head);

    cout << "After reverse: ";
    Node::print(reserve);






    return 0;
}