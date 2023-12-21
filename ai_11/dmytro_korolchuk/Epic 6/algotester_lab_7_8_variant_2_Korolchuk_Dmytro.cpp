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
        void displayList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }   
        
        void removeElementAtIndex(int index) {

        Node* temp = nullptr;

        if (index == 0) {
            temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            if (size == 1) {
                tail = nullptr;
            }
        } else if (index == size - 1) {
            temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            temp = current;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete temp;
        }

        size--;
    }   
        void changeElementAtIndex(int index, int newValue) {

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        current->data = newValue;
    }
        void getValue(int index) {

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        cout<<current->data<<endl;
    }
        void Size() {
            cout<<size<<endl;
    }
};

int main(){
    DoublyLinkedList bebrochka;
    int Q;
    cin >> Q;
    for(int i = 0; i<Q; i++){
        string identifier;
        cin>> identifier;
        if(identifier == "insert"){
            int index, n;
            cin>>index>>n;
            int insert[n];
            for(int i = 0; i<n; i++){
                cin>>insert[i];
            }
            for (int i = n - 1; i >= 0; i--){
                bebrochka.addElementAtIndex(index,insert[i]);
            }
        }
        else if(identifier == "print"){
            bebrochka.displayList();
        }
        else if(identifier == "erase"){
            int index, n;
            cin >> index >> n;
            for(int i = 0; i<n; i++){
                bebrochka.removeElementAtIndex(index);
            }
        }
        else if(identifier == "size"){
            bebrochka.Size();
        }
        else if(identifier == "set"){
            int index, value;
            cin>>index>>value;
            bebrochka.changeElementAtIndex(index, value);
        }
        else if(identifier == "get"){
            int index;
            cin>>index;
            bebrochka.getValue(index);
        }
    }
    
}