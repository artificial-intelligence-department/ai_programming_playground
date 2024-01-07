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

        DoublyLinkedList sumLists(const DoublyLinkedList& list2) const {
        DoublyLinkedList result;

        Node* currentThis = head;
        Node* currentOther = list2.head;

        while (currentThis != nullptr && currentOther != nullptr) {
            int sum = currentThis->data + currentOther->data;
            result.addElementAtIndex(result.size, sum);

            currentThis = currentThis->next;
            currentOther = currentOther->next;
        }

        return result;
    }


        void displayList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
        void displaySum() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data;
            current = current->prev;
        }
        cout << endl;
    }
};

int main(){
    DoublyLinkedList list1;
    DoublyLinkedList list2;
    int size1;
    cin>>size1;
    for(int i = 0; i<size1; i++){
        int value;
        cin>>value;
        list1.addElementAtIndex(i, value);
    }
    int size2;
    cin>>size2;
    for(int i = 0; i<size2; i++){
        int value;
        cin>>value;
        list2.addElementAtIndex(i, value);
    }
    DoublyLinkedList sumResult = list1.sumLists(list2);
    sumResult.displaySum();
}