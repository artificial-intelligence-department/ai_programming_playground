#include <iostream>
using namespace std;
struct Node {
    int key;
    Node* prev;
    Node* next;
    Node(int val) : key(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}
    void addToFront(int key) {
        Node* newNode = new Node(key);
        if (head == nullptr) 
            head = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void deleteNode(int position) {
        if (head == nullptr) {
            cout << "empty list" << endl;
            return;
        }
        Node* current = head;
        int currentPosition = 1;
        while (current != nullptr && currentPosition < position) {
            current = current->next;
            currentPosition++;
        }
        if (current == nullptr) {
            cout << "element wasn`t found." << endl;
            return;
        }
        if (current->prev != nullptr) 
            current->prev->next = current->next;
        else 
            head = current->next;
        if (current->next != nullptr) 
            current->next->prev = current->prev;
        delete current;
        cout << "element number of " << position << " deleted" << endl;
    }
    void displayList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main() {
    DoublyLinkedList list;

    list.addToFront(3);
    list.addToFront(5);
    list.addToFront(7);
    list.addToFront(9);

    cout << "list: ";
    list.displayList();

    list.deleteNode(2);
    list.addToFront(1);

    cout << "list: ";
    list.displayList();

    return 0;
}
