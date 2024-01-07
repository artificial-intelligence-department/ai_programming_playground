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

Node* createList(int numElements) {
    Node* head = nullptr;
    Node* temp = nullptr;
    int val;

    for (int i = 0; i < numElements; ++i) {
        cout << "Enter a number: ";
        cin >> val;

        if (head == nullptr) {
            head = new Node(val);
            temp = head;
        } else {
            temp->next = new Node(val);
            temp = temp->next;
        }
    }

    return head;
}

int main() {
    int num1, num2;

    cout << "Enter the number of elements for the first list: ";
    cin >> num1;
    Node* head1 = createList(num1);

    cout << "\nEnter the number of elements for the second list: ";
    cin >> num2;
    Node* head2 = createList(num2);

    cout << "\nComparison result: " << boolalpha << compare(head1, head2) << endl;

    return 0;
}
