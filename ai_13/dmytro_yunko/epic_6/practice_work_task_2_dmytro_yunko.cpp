#include <iostream>

using namespace std;

class Node {
    public:
        
        int data;
        Node* next;

        
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};


class LinkedList {
    private:
        
        Node* head;

    public:
        
        LinkedList() {
            head = nullptr;
        }

        
        void insert(int data) {
            
            Node* newNode = new Node(data);
            
            newNode->next = head;
            
            head = newNode;
        }

        
        bool compare(LinkedList& other) {
            
            Node* h1 = head;
            Node* h2 = other.head;

            
            while (h1 != nullptr && h2 != nullptr) {
                
                if (h1->data != h2->data) {
                    return false;
                }
                
                h1 = h1->next;
                h2 = h2->next;
            }
            
            return h1 == nullptr && h2 == nullptr;
        }
};

int main() {
    
    LinkedList list1;
    LinkedList list2;

    
    list1.insert(4);
    list1.insert(4);
    list1.insert(8);
    list1.insert(10);

    list2.insert(4);
    list2.insert(4);
    list2.insert(8);
    list2.insert(10);

    
    bool result = list1.compare(list2);

    
    if (result) {
        cout << "Lists are equal"<<endl;
    } else {
        cout << "Lists are not equal"<<endl;
    }

    return 0;
}
