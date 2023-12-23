#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int data;
    shared_ptr<Node> next;

    Node(int value) : data(value), next(nullptr) {}
};

shared_ptr<Node> createList() {
    cout << "Enter the number of elements in the list: ";
    int n;
    cin >> n;

    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> tail = nullptr;

    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << (i + 1) << ": ";
        int value;
        cin >> value;

        auto newNode = make_shared<Node>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    return head;
}

bool compare(const shared_ptr<Node>& h1, const shared_ptr<Node>& h2) {
    auto n1 = h1;
    auto n2 = h2;

    while (n1 != nullptr && n2 != nullptr) {
        if (n1->data != n2->data) {
            return false;  // Data mismatch detected
        }
        n1 = n1->next;
        n2 = n2->next;
    }

    // Check if both lists ended at the same time (lists are of equal length)
    return n1 == nullptr && n2 == nullptr;
}

int main() {
    // Example usage
    cout << "Creating the first list:\n";
    auto head1 = createList();

    cout << "Creating the second list:\n";
    auto head2 = createList();

    if (compare(head1, head2)) {
        cout << "The lists are identical." << endl;
    } else {
        cout << "The lists are different." << endl;
    }

    return 0;
}
