#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false; 
        }

        h1 = h1->next;
        h2 = h2->next;
    }
    if (h1 == nullptr && h2 == nullptr) {
        return true;
    }
    return false;
}

int main() {
    Node* h1 = new Node{7, nullptr};
    h1->next = new Node{1, nullptr};
    h1->next->next = new Node{2, nullptr};
    h1->next->next->next = new Node{0, nullptr};
    h1->next->next->next->next = new Node{3, nullptr};

    Node* h2 = new Node{7, nullptr};
    h2->next = new Node{1, nullptr};
    h2->next->next = new Node{2, nullptr};
    h2->next->next->next = new Node{0, nullptr};
    h2->next->next->next->next = new Node{3, nullptr};

    bool comparison = compare(h1, h2);

    if (comparison=true) {
        cout << "Lists are similar" << endl;
    } else {
        cout << "Lists are different" << endl;
    }
    return 0;
}