#include <iostream>

using namespace std;

struct Node{
    struct Node * prev;
    int data;
    struct Node * next;
};

void addToEnd(Node* & head, int value){

    Node* n = new Node{nullptr, value, nullptr};

    if (!head) { // якщо кільце пусте
        head = n;
        head->prev = head;
        head->next = head;
    } else {
        // поперeдній елемент <- новий елемент
        n->prev = head->prev;
        n->next = head;
        // попередній елемент -> новий
        head->prev->next = n;
        head->prev = n;
    }
}

void addToStart(Node* & head, int value){

    Node* n = new Node{nullptr, value, nullptr};

    if (!head) { // якщо кільце пусте
        head = n;
        head->prev = head;
        head->next = head;
    } else {
        n->next = head->next;
        head->next = n;
        
        n->next->prev = n;
        n->prev = head;
    }
}

void displayClockwise(const Node* head) { // по кільцю вліво

    const Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

void displayAntiClockwise(const Node* head) { // по кільцю вправо

    const Node* current = head;
    do {
        cout << current->data << " ";
        current = current->prev;
    } while (current != head);
    cout << endl;

}

int main()
{
    Node* myList = nullptr;

    addToEnd(myList, 5);
    addToEnd(myList, 10);
    addToEnd(myList, 3);
    addToEnd(myList, 7);
    addToEnd(myList, 1);

    displayClockwise(myList);
    
    addToStart(myList, 25);
    addToEnd(myList, 50);
    
    displayAntiClockwise(myList);


	return 0;
}