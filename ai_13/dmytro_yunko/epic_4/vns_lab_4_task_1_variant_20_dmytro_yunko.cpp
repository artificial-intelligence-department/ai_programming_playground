





#include <iostream>
using namespace std;



struct Node
    {
        int value;
        Node* next;
        Node* previous;
    };
    
    class LinkedList {
        private:
        Node* head;
        Node* end;
        public:
        void insert(int value) {
                Node* newNode = new Node;
                newNode->value = value;
                newNode->next = nullptr;
                 if(head==nullptr){
                    head = newNode;
                    end = newNode;
                    newNode->next = newNode;
                    newNode->previous = newNode;
                } else {
                    newNode->next = head;
                    newNode->previous = end;
                    end->next = newNode;
                    head->previous = newNode;
                    end = newNode;
                }

            }
            LinkedList(int size) {
                head = nullptr;
                end = nullptr;
            for (int i = 0; i <= size; i++)
            {
                insert(i+1);
                
                
            }
            
            }
            ~LinkedList() {
                Node* temp;
                while(head != nullptr){
                    temp= head;
                    head = head->next;
                    delete temp;
                    
                }
            }
            void insertZeroAfterFive() {
                Node* temp = head;
                int index = 0;
                do {
                    if (index % 5 == 0) {
                        Node* newNode = new Node;
                        newNode->value = 0;
                        newNode->next = temp->next;
                        newNode->previous = temp;
                        temp->next->previous = newNode;
                        temp->next = newNode;
                        temp = newNode->next;
                        index++;
                    } else {
                        temp = temp->next;
                    }
                    index++;
                } while (temp != head);
            }

            void displayFromKToKMinusOne(int K) {
                Node* temp = head;
                
                for (int i = 0; i < K; i++) {
                    temp = temp->next;
                }
                
                for (int i = 0; i < 2; i++) {
                    
                    cout << temp->value << " ";
                    temp = temp->previous;
                }
                cout << endl;
            }

            void displayFromKToKPlusOne(int K) {
                Node* temp = head;
                
                for (int i = 0; i < K; i++) {
                    temp = temp->next;
                }
                
                for (int i = 0; i < 2; i++) {
                    cout << temp->value << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
            
            
             void display() {
            Node* temp = head;

            while (temp != end) {
                cout << temp->value << " "; 
                temp = temp->next; 
            }
            // cout << temp->value<<" "<<temp -> previous->value;
            cout << endl;
        }


    };
    


int main(int argc, char const *argv[])
{
   
    LinkedList List{10};
    List.display();
    List.displayFromKToKPlusOne(5);
    
    List.displayFromKToKMinusOne(5);
    List.insertZeroAfterFive();
    List.display();
    return 0;
}
