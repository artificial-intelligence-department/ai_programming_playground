#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}


    void addToStart(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }

        head = newNode;
    }


    void deleteElements(int k, int* positions, int size) {
        Node* current = head;
        while (current != nullptr && k > 0) {
            Node* temp = current;
            current = current->next;

            for (int i = 0; i < size; ++i) {
                if (temp != nullptr && temp->data == positions[i]) {
                    if (temp->prev != nullptr) {
                        temp->prev->next = temp->next;
                    } else {
                        head = temp->next;
                    }

                    if (temp->next != nullptr) {
                        temp->next->prev = temp->prev;
                    } else {
                        tail = temp->prev;
                    }

                    delete temp;
                    k--;
                }
            }
        }
    }


    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }


    void deleteList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    DoublyLinkedList myList;


    for (int i = 5; i > 0; --i) {
        myList.addToStart(i);
    }

    cout << "Список перед видаленням: ";
    myList.printList();


    int positionsToDelete[] = {2, 4};
    int k = sizeof(positionsToDelete) / sizeof(positionsToDelete[0]);

 
    myList.deleteElements(k, positionsToDelete, k);


    int newElements[] = {9, 8};
    int numNewElements = sizeof(newElements) / sizeof(newElements[0]);
    for (int i = 0; i < numNewElements; ++i) {
        myList.addToStart(newElements[i]);
    }

    cout << "Список після видалення та додавання: ";
    myList.printList();


    myList.deleteList();

    return 0;
}