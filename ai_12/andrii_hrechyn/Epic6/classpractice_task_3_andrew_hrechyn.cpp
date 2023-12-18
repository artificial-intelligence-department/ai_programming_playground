#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

Node* createnode(int val) {
    return new Node(val);
}

void insertnode(Node*& head, int val) {
    Node* newNode = createnode(val);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* current = nullptr;
    int carry = 0;

    while (n1 != nullptr ||  n2 != nullptr ||  carry != 0) {
        int sum = carry;
        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }

        carry = sum / 10;  
        sum %= 10;         

        insertnode(result, sum);  
        if (current == nullptr) {
            current = result;
        } else {
            current = current->next;
        }
    }

    return result;
}

void print_list(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* num_1 = new Node(9);
    num_1->next = new Node(7);
    num_1->next->next = new Node(3);

    Node* num_2 = new Node(5);
    num_2->next = new Node(8);
    num_2->next->next = new Node(2);

    Node* result = add(num_1, num_2);

    cout << "Results: ";
    print_list(result);

    delete num_1;
    delete num_2;
    delete result;

    return 0;
}