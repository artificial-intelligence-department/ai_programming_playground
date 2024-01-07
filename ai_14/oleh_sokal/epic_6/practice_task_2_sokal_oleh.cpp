#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    // Constructors
    Node() : value(0), next(nullptr) {}
    Node(int data) : value(data), next(nullptr) {}

    // Destructor for proper memory cleanup
    ~Node() {
        delete next;
    }
};

bool compare(const Node* a, const Node* b) {
    while (a != nullptr && b != nullptr) {
        if (a->value != b->value) {
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return (a == nullptr && b == nullptr);
}

int main() {
    // Initialize linked lists using constructors
    Node* head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(6);

    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(7);

    // Compare linked lists
    if (compare(head1, head2)) {
        cout << "Lists are equal" << endl;
    } else {
        cout << "Lists are not equal" << endl;
    }

    // Clean up memory
    delete head1;
    delete head2;

    return 0;
}
