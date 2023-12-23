#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteList(Node* head) {
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
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

    head = prev;  
    return head;
}

int main() {
    
    Node* head = new Node{7, nullptr};
    head->next = new Node{1, nullptr};
    head->next->next = new Node{2, nullptr};
    head->next->next->next = new Node{0, nullptr};
    head->next->next->next->next = new Node{3, nullptr};
    head = reverse (head);
    printList(head);
    deleteList(head);
    return 0;
}
