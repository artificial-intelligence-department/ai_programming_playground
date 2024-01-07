#include <iostream>
using namespace std;

struct Node {
    int numbers;
    Node* next;

    Node(int val) : numbers(val), next(nullptr) {}
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->numbers << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->numbers != h2->numbers) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return (h1 == nullptr && h2 == nullptr);
}

Node* createList() {
    Node* head = nullptr;
    Node* temp = nullptr;
    int input;

    while (true) {
        cin >> input;
        if (input == -1) {
            break;
        }
        Node* newNode = new Node(input);
        if (head == nullptr) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    cout << "Enter elements for the first list (enter -1 to stop):" << endl;
    Node* head1 = createList();

    cout << "Enter elements for the second list (enter -1 to stop):" << endl;
    Node* head2 = createList();

    cout << "First list: ";
    printList(head1);

    cout << "Second list: ";
    printList(head2);

    cout << "Comparison result: " << compare(head1, head2) << endl;

    return 0;
}
