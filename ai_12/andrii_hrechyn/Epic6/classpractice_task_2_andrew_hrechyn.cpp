#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false; 
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    if (h1 != nullptr || h2 != nullptr) {
        return false;
    }

    return true;  
}

int main() {
    Node* list1 = new Node(8);
    list1->next = new Node(2);
    list1->next->next = new Node(3);

    Node* list2 = new Node(1);
    list2->next = new Node(2);
    list2->next->next = new Node(3);

    if (compare(list1, list2)) {
        cout << "Lists are the same!\n";
    } else {
        cout << "Lists are different!\n";
    }

    delete list1;
    delete list2;

    return 0;
}