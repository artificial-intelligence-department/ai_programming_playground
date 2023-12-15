#include <iostream>
#include <string>

using namespace std;


struct Node {
    char data;       
    Node* next;    
    Node* prev;     
};


class DoubleLinkedList {
    Node* head;      
    Node* tail;      

public:
    
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}


    void add(char value) {
        Node* newNode = new Node{value, nullptr, tail};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }


    void add_from_string(string value) {
        for (char ch : value) {
            add(ch);
        }
        reverse();
    }

    void print() {
        Node* current = tail;
        if (current == nullptr) {
            cout << "Empty list\n";
            return;
        }
        while (current != nullptr) {
            cout << current->data;
            current = current->prev;
        }
        cout << '\n';
    }

    void reverse() {
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

    void sum_of_lists(const DoubleLinkedList& list1, const DoubleLinkedList& list2, DoubleLinkedList& output) {
        Node* current1 = list1.head;
        Node* current2 = list2.head;
        int carry = 0;

        while (current1 != nullptr || current2 != nullptr) {
            int sum = carry;
            if (current1 != nullptr) {
                sum += current1->data - '0';
                current1 = current1->next;
            }
            if (current2 != nullptr) {
                sum += current2->data - '0';
                current2 = current2->next;
            }
            carry = sum / 10;
            output.add(sum % 10 + '0');
        }

        if (carry > 0) {
            output.add(carry + '0');
        }
    }
};

int main() {
    DoubleLinkedList list1;
    DoubleLinkedList list2;
    DoubleLinkedList output;


    list1.add_from_string("50000000000");
    list2.add_from_string("30000000");


    cout << "List 1: ";
    list1.print();
    cout << "List 2: ";
    list2.print();
    list1.sum_of_lists(list1, list2, output);

    cout << "Sum: ";
    output.print();

    return 0;
}