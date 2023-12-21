#include <iostream>
#include <fstream>

using namespace std;

class Node{
public:
    char data;
    Node* next;
    Node* prev;
};

void createDLL(Node*& head, Node*& tail, int size) {
    head = nullptr;
    tail = nullptr;

    if (size == 0) {
        return;
    }

    head = new Node;
    head->data = 'a'; 
    Node* current = head;

    for (int i = 2; i <= size; i++) {
        Node* newNode = new Node;
        newNode->data = static_cast<char>('a' + i - 1); 

        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }

    tail = current;
}

void inNode(Node*& head, Node*& tail, int position, char value){
    Node* current = head;
    for (int i = 1; i < position; i++){
        if (current == tail){
            cout << "ERROR" << endl;
            return;
        }
        current = current->next;
    }

    Node* newNode = new Node;
    newNode->data = value;

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != tail->next){
        (current->next)->prev = newNode;
    } 
    else{
        tail = newNode;
    }

    current->next = newNode;
}

void delNode(Node*& head, Node*& tail, int position) {
    Node* current = head;
    for (int i = 1; i < position; i++) {
        if (current == tail) {
            cout << "ERROR" << endl;
            return;
        }
        current = current->next;
    }

    Node* nodeToDelete = current->next;

    if (nodeToDelete == tail) {
        tail = current;
    } else {
        (nodeToDelete->next)->prev = current;
    }

    current->next = nodeToDelete->next;

    delete nodeToDelete;
}

void writeToFile(Node* node, Node* tail, string path){
    ofstream file;
    file.open(path);
    while (node != tail->next){
        file << node->data << " ";
        node = node->next;
    }
    file.close();
}

void Print(Node* head){
    Node* traverser = head;
    while(traverser!=nullptr){
        cout<<traverser->data<<" ";
        traverser= traverser->next;
    }
    cout<<endl;
}

void delDLL(Node*& head) {
    while (head != nullptr) {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

int main(){
    Node* head;
    Node* tail;

    int size;
    cin>>size;

    createDLL(head, tail, size);
    Print(head);
    
    char insert;
    cin>>insert;
    
    int kAdd;
    cin>>kAdd;
    
    inNode(head, tail, kAdd, insert);
    inNode(head, tail, kAdd, insert);
    Print(head);
    
    int kDelete;
    cin>>kDelete;
    
    delNode(head, tail, kDelete);
    delNode(head, tail, kDelete);
    Print(head);
    
    string path = "vnsfile.txt";
    writeToFile(head, tail, path);
    
    delDLL(head);
}