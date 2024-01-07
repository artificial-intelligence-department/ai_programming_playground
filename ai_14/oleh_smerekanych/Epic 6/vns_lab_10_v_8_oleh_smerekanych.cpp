#include <iostream>

using namespace std;

struct Node {
    int data;         
    Node* prev;       
    Node* next;       
};

Node* create2LinkedList(int keys[], int n) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        newNode->data = keys[i];
        newNode->prev = tail;
        newNode->next = nullptr;

        if (tail != nullptr) {
            tail->next = newNode;
        }

        tail = newNode;

        if (head == nullptr) {
            head = newNode;
        }
    }

    return head;
}

void print2LinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

void deleteNodeByIndex(Node*& head, int index) {
    Node* current = head;
    int currentIndex = 0;

    while (current != nullptr && currentIndex < index) {
        current = current->next;
        ++currentIndex;
    }

    if (current != nullptr) {
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }

        delete current;
    }
}

void addElementsToBeginning(Node*& head, int k) {
    for (int i = 0; i < k; i++) {
        Node* newNode = new Node;
        newNode->data = i + 1;  
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
    }
}

int main() {
    int keys[] = {1, 2, 3, 4, 5};
    int n = sizeof(keys) / sizeof(keys[0]);

    Node* doublyLinkedList = create2LinkedList(keys, n);

    cout << "Original Doubly Linked List: ";
    print2LinkedList(doublyLinkedList);

    int indexToDelete = 2; 
    deleteNodeByIndex(doublyLinkedList, indexToDelete);

    cout << "Doubly Linked List after deleting element at index " << indexToDelete << ": ";
    print2LinkedList(doublyLinkedList);

    int k = 3; 
    addElementsToBeginning(doublyLinkedList, k);

    cout << "Doubly Linked List after adding " << k << " elements to the beginning: ";
    print2LinkedList(doublyLinkedList);

    while (doublyLinkedList != nullptr) {
        Node* temp = doublyLinkedList;
        doublyLinkedList = doublyLinkedList->next;
        delete temp;
    }

    return 0;
}
