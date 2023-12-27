#include <iostream>

struct Node {
    int data;
    Node* next;
};
typedef Node* NodePtr;
void insert(NodePtr& head,int data)
{
    NodePtr tempPtr;
    tempPtr = new Node;
    tempPtr->data = data;
    tempPtr->next = head;
    head = tempPtr;
}

bool compare(Node *h1, Node *h2) {
    
    while (h1 != nullptr && h2 != nullptr) {
        
        if (h1->data != h2->data) {
            return false; 
        }

        h1 = h1->next;
        h2 = h2->next;
    }
        return h1 == nullptr && h2 == nullptr;
}

int main() {

    Node* list1 = nullptr;
    insert(list1,20);
    insert(list1,11);
    insert(list1,99);
    insert(list1,39);


    Node* list2 = nullptr;
    insert(list2,20);
    insert(list2,11);
    insert(list2,99);
    insert(list2,39);

    bool result = compare(list1, list2);

    if (result) {
        std::cout << "Lists are equal\n";
    } else {
        std::cout << "Lists are not equal\n";
    }

    return 0;
}