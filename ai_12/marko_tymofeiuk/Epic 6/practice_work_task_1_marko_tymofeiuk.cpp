#include <iostream>

class Node {
public:
    const char* data;
    Node* next;
};

void printLinkedList(Node* n) {
    while (n != nullptr) {
        std::cout << n->data << " ";
        n = n->next;
    }
    std::cout << std::endl;
}

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

bool compareLinkedLists(Node* list1, Node* list2) {
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data != list2->data) {
            return false;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    return (list1 == nullptr && list2 == nullptr);
}

int main() {
    Node* head1 = nullptr;
    Node* second1 = nullptr;
    Node* third1 = nullptr;

    head1 = new Node();
    second1 = new Node();
    third1 = new Node();

    head1->data = "apple";
    head1->next = second1;

    second1->data = "orange";
    second1->next = third1;

    third1->data = "banana";
    third1->next = nullptr;

    std::cout << "Original Linked List 1: ";
    printLinkedList(head1);

    Node* head2 = nullptr;
    Node* second2 = nullptr;
    Node* third2 = nullptr;

    head2 = new Node();
    second2 = new Node();
    third2 = new Node();

    head2->data = "apple";
    head2->next = second2;

    second2->data = "orange";
    second2->next = third2;

    third2->data = "banana";
    third2->next = nullptr;

    std::cout << "Original Linked List 2: ";
    printLinkedList(head2);

    head1 = reverseLinkedList(head1);
    std::cout << "Reversed Linked List 2: ";
    printLinkedList(head1);

    bool areIdentical = compareLinkedLists(head1, head2);

    std::cout << "Are the linked lists identical? " << (areIdentical ? "Yes" : "No") << std::endl;

    return 0;
}
