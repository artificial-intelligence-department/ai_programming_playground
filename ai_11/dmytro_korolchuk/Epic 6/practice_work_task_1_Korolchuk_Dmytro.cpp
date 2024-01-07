#include <iostream>
using namespace std;

class DoublyLinkedList {
    private:
        struct Node {
            int data;
            Node* next;
            Node* prev;
        };

        Node* head;
        Node* tail;
        int size;

    public:
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr; 
            size = 0;
        }
        void addElementAtIndex(int index, int value) {

        Node* newNode = new Node{value, nullptr, nullptr};

        if (index == 0) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            if (size == 0) {
                tail = newNode;
            }
        } else if (index == size) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }

            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }

        size++;
    }
        void reverseList() {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            current = current->prev;
        }

        temp = head;
        head = tail;
        tail = temp;
    }
        void displayList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main(){
    DoublyLinkedList why;
    int size;
    cin>>size;
    for(int i = 0; i<size; i++){
        int value;
        cin>>value;
        why.addElementAtIndex(i, value);
    }
    why.displayList();
    why.reverseList();
    why.displayList();
}