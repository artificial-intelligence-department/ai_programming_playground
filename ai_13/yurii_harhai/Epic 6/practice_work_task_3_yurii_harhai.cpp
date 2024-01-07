#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int data);

Node* add(Node* n1, Node* n2);

void printList(Node *node);

void deleteList(Node* &head);


int main() {
    Node* n1 = newNode(0);
    n1->next = newNode(4);
    n1->next->next = newNode(8);
    n1->next->next->next = newNode(2);
    n1->next->next->next->next = newNode(6);
    cout << "First List is ";
    printList(n1);

    Node* n2 = newNode(5);
    n2->next = newNode(9);
    cout << "Second List is ";
    printList(n2);

    Node* final = add(n1, n2);
    cout << "Final list is ";
    printList(final);

    deleteList(n1);
    deleteList(n2);
    deleteList(final);

   return 0;
}

Node* newNode(int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
Node* add(Node* n1, Node* n2) {
    Node* result = NULL;
    Node* temp, *prev = NULL;
    int carry = 0, sum;

    while (n1 != NULL || n2 != NULL) {
        sum = carry + (n1? n1->data: 0) + (n2? n2->data: 0);
        carry = (sum >= 10)? 1 : 0;
        sum = sum % 10;
        temp = newNode(sum);

        if(result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }

        prev = temp;

        if(n1) n1 = n1->next;
        if(n2) n2 = n2->next;
    }

    if(carry > 0) {
        temp = newNode(carry);
        prev->next = temp;
    }

    return result;
}

void printList(Node *node) {
    while(node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void deleteList(Node* &head) {
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }

    head = NULL;
}