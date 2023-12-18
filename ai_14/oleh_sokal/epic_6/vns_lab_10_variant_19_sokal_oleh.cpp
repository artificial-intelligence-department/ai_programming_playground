#include <iostream>
using namespace std;


class DblLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };


    Node* head;
    Node* tail;
    size_t size;


public:
    // Constructor
    DblLinkedList() : head(nullptr), tail(nullptr), size(0) {}


    // Destructor to clean up memory
    ~DblLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }


    // Display the elements in the list
    void Show() const {
        if (size == 0) {
            cout << "List is empty" << endl;
            return;
        }


        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }


    // Add a node with the given value to the back of the list
    void PushBack(const int& value) {
        if (size == 0) {
            head = tail = new Node{value, nullptr, nullptr};
        } else {
            tail->next = new Node{value, tail, nullptr};
            tail = tail->next;
        }
        size++;
    }


    // Add a node with the given value to the front of the list
    void PushFront(const int& value) {
        if (size == 0) {
            head = tail = new Node{value, nullptr, nullptr};
        } else {
            Node* newHead = new Node{value, nullptr, head};
            head->prev = newHead;
            head = newHead;
        }
        size++;
    }


    // Remove nodes with the given value from the list
    void Remove(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                if (head == current) {
                    if (size == 1) {
                        delete head;
                        head = tail = nullptr;
                    } else {
                        Node* tmp = head;
                        head = head->next;
                        head->prev = nullptr;
                        delete tmp;
                    }
                } else if (tail == current) {
                    Node* tmp = tail;
                    tail = tail->prev;
                    tail->next = nullptr;
                    delete tmp;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                }
                size--;
                return;
            }
            current = current->next;
        }
    }
};


int main() {
    DblLinkedList list;


    cout << "List: ";
    for (int value = 0; value < 10; value++) {
        list.PushBack(value);
    }
    list.Show();


    cout << "List after deletion: ";
    for (int i = 0; i < 3; i++) {
        list.Remove(i);
    }
    list.Show();


    cout << "List after adding elements: ";
    for (int i = 0; i < 3; i++) {
        list.PushFront(i);
    }
    list.Show();


    return 0;
}
