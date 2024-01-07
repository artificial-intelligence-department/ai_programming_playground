#include <iostream>
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
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
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);
    Node* list2 = new Node(1);
    list2->next = new Node(2);
    list2->next->next = new Node(3);
    Node* list3 = new Node(1);
    list3->next = new Node(2);
    if (compare(list1, list2)) {
        std::cout << "list1 і list2 однакові" << std::endl;
    } else {
        std::cout << "list1 і list2 різні" << std::endl;
    }
    if (compare(list1, list3)) {
        std::cout << "list1 і list3 однакові" << std::endl;
    } else {
        std::cout << "list1 і list3 різні" << std::endl;
    }
    while (list1 != nullptr) {
        Node* temp = list1;
        list1 = list1->next;
        delete temp;
    }
    while (list2 != nullptr) {
        Node* temp = list2;
        list2 = list2->next;
        delete temp;
    }
    while (list3 != nullptr) {
        Node* temp = list3;
        list3 = list3->next;
        delete temp;
    }
    return 0;
}
