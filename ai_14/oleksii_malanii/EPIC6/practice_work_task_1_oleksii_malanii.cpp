#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void reverseList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; 
    }
    Node *previousNode = NULL;
    Node *currentNode = *head;
    Node *nextNode;
    while (currentNode != NULL) {
        nextNode = currentNode->next; 
        currentNode->next = previousNode; 
        previousNode = currentNode; 
        currentNode = nextNode; 
    }
    *head = previousNode;
}
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node{1, new Node{2, new Node{3, nullptr}}};
    cout << "Original List: ";
    printList(head);
    reverseList(&head);
    cout << "Reversed List: ";
    printList(head);
    return 0;
}
