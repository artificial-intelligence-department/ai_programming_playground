#include <iostream>
#include <stack>
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

        
        LinkedList add(LinkedList& other) {
            
            LinkedList result;
            
            Node* head_1 = head;
            Node* head_2 = other.head;
            
            int carry = 0;

            
            while (head_1 != nullptr || head_2 != nullptr || carry != 0) {
                
                int sum = carry;

                
                if (head_1 != nullptr) {
                    sum += head_1->data;
                    head_1 = head_1->next;
                }

                
                if (head_2 != nullptr) {
                    sum += head_2->data;
                    head_2 = head_2->next;
                }

                
                int digit = sum % 10;
                
                carry = sum / 10;

                
                result.insert(digit);
            }

            
            return result;
        }

        
        void printList() {
            
            Node* current = head;
            
            while (current != nullptr) {
                
                cout << current->data << " ";
                
                current = current->next;
            }
            
            cout << endl;
        }
        void printReverse() {
            
            stack<int> s;
            
            Node* current = head;
            
            while (current != nullptr) {
                
                s.push(current->data);
                
                current = current->next;
            }
            
            while (!s.empty()) {
                
                cout << s.top() << " ";
                s.pop();
            }
            
            cout << endl;
        }
        
};

int main() {
    
    LinkedList num1;
    LinkedList num2;

    
    num1.insert(2);
    num1.insert(0);
    num1.insert(0);

    num2.insert(1);
    num2.insert(6);
    num2.insert(8);

    
    LinkedList result = num1.add(num2);

    
    cout << "Number 1: ";
    num1.printReverse();

    cout << "Number 2: ";
    num2.printReverse();

    cout << "Sum: ";
    result.printList();

    return 0;
}
