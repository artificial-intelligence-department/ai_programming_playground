#include <iostream>
#include <fstream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* previous;
};

void createList(Node*& head, Node*& tail, int size){
    head = nullptr, tail = nullptr;
    if (size == 0){
        return;
    }
    head = new Node;
    head->data = 1;
    Node* current = head;
    for (int i = 2; i <= size; i++){

        Node* NewNode = new Node;
        NewNode->data = i;

        NewNode->previous = current;
        current->next = NewNode;
        current = NewNode;
    }
    tail = current;
}

void printList(Node* node, Node* tail){
    while (node != tail->next){
        cout << node->data << " ";
        node = node->next; 
    }
    cout << endl;
}

void insertNode(Node*& head, Node*& tail, int position, int value){
    Node* current = head;
    for (int i = 1; i < position; i++){
        if (current == tail){
            cout << "Wrong position!" << endl;
            return;
        }
        current = current->next;
    }

    Node* newNode = new Node;
    newNode->data = value;

    newNode->next = current->next;
    newNode->previous = current;

    if (current->next != tail->next){
        (current->next)->previous = newNode;
    } 
    else{
        tail = newNode;
    }

    current->next = newNode;
}

void deleteElements(Node*& head, Node*& tail, int N) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* target = tail;
    for (int i = 1; i <= N && target != nullptr; i++) {
        Node* previous = target->previous;
        tail = previous;
        delete target;
        target = previous;
    }

    if (target == nullptr) {
        head = nullptr;
        tail = nullptr;
    }
}

void fillTheFile(Node* node, Node* tail, string path){
    ofstream file;
    file.open(path, ios_base::app);
    while (node != tail->next){
        file << node->data << " ";
        node = node->next;
    }
    file.close();
}

void deletelist(Node*& head, Node*& tail){
    while (head != tail->next){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

int main(){
    Node* head;
    Node* tail;
    int size = 7;
    createList(head, tail, size);
    printList(head, tail);

    insertNode(head, tail, 4, 10);
    printList(head, tail);

    deleteElements(head, tail, 2);
    printList(head, tail);

    string path = "C:/Users/Marko/Desktop/Study/Programming/Epic6/list.txt";
    fillTheFile(head, tail, path);

    deletelist(head, tail);

    return 0;
}