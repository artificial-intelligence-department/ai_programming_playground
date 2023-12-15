#include <iostream>
using namespace std;

struct Node 
    {
        int value;
        int index;
        Node* next;
        Node* previous;
    };
    
    class LinkedList 
    {
        private:
        int sizeL {0};
        Node* head;
        Node* end;
        public:
        void insertLeft(int value) {
            sizeL++;
            Node* newNode = new Node;
            newNode->value = value;
                
                 if(head==nullptr) {
                    head = newNode;
                    end = newNode;
                    newNode->next = newNode;
                    newNode->previous = newNode;
                } else {
                    newNode->next = head;
                    head = newNode;
                }
        }
        void insert(int value){
            sizeL++;
            Node* newNode = new Node;
            newNode->value = value;
            newNode->next = nullptr;
                if(head==nullptr){
                    head = newNode;
                    end = newNode;
                    newNode->next = newNode;
                    newNode->previous = newNode;
                } else {
                    newNode->next = end;
                    newNode->previous = head;
                    end->next = newNode;
                   
                    end = newNode;
                    end->next = head;
                }
            }
            LinkedList(int size) {
                head = nullptr;
                end = nullptr;

            for (int i = 0; i < size; i++)
            {
                insert(i+1);
            }
            }
            ~LinkedList() {
                Node* temp;
                while(head != nullptr) {
                    temp= head;
                    head = head->next;
                    delete temp; 
                }
            }
            void displayFromKToKMinusOne(int K) {
    Node* temp = head;
    
    for (int i = 0; i < K; i++) {
        temp = temp->next;
    }
    
    for (int i = 0; i < sizeL; i++) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
    void delEven() {
    
    Node* tr = new Node;

    tr->value = -1;
    tr->next = head;
    tr->previous = end;
    head->previous = tr;
    end->next = tr;

    Node* temp = tr;
    
    do {
        
        if (temp->next->value % 2 == 0) {
            
            sizeL--;

            Node* toDelete = temp->next;

            temp->next = toDelete->next;
            toDelete = temp;

            if (toDelete == end) {
            end = temp;
            }
            delete toDelete;
        } else {
            temp = temp->next;
        }
    } while (temp != tr); 
    head = tr->next;

     delete tr;
}
            
         void display() {
            Node* temp = head;

            while (temp != end) {
                cout << temp->value << " "; 
                temp = temp->next; 
            }
            cout << endl;
        }
    };

int main(int argc, char const *argv[]) {
    LinkedList List{10};
   
    List.displayFromKToKMinusOne(5);
    List.insertLeft(5);
    List.insert(7);
    
    List.displayFromKToKMinusOne(0);
    List.delEven();
    List.displayFromKToKMinusOne(0);

    return 0;
}