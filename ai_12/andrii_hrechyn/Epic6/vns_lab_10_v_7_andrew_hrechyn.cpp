#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

void add_node(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void delete_first_node(Node*& head) {
    if (head) {
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete temp;
    }
}

void show_list(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << '\n'; 
        temp = temp->next;
    }
    cout << '\n';
}

int main() {
    Node* myList = nullptr;

    add_node(myList, 1);
    add_node(myList, 2);
    add_node(myList, 3);

    show_list(myList);

    delete_first_node(myList);
    add_node(myList, 4);

    show_list(myList);

    return 0;
}
