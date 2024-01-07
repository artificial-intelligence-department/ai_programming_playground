// Реверс однозв'язного списку списку
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* reverse(Node* head) { // Функція проходить по списку та змінює напрям вказівників на протилежний
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

void printList(Node* head) { // Функція друку ліста
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "enter count of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "amount of nodes must be over zero." << endl;
        return 0;
    }

    cout << "enter values: ";
    int value;
    cin >> value;
    Node* head = new Node(value);

    Node* current = head;
    for (int i = 1; i < n; i++) {
        cin >> value;
        current->next = new Node(value);
        current = current->next;
    }

    cout << "Original list: ";
    printList(head);

    head = reverse(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
