#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

bool compare(Node* h1, Node* h2) {
    while (h1 && h2) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    return h1 == nullptr && h2 == nullptr;
}

// Функція для створення списку заданого розміру
Node* createList(int size) {
    if (size <= 0) {
        return nullptr;
    }

    Node* head = nullptr;
    Node* current = nullptr;

    for (int i = 0; i < size; ++i) {
        int value;
        std::cout << "Enter the value of the node " << i + 1 << ": ";
        std::cin >> value;

        if (head == nullptr) {
            head = new Node(value);
            current = head;
        } else {
            current->next = new Node(value);
            current = current->next;
        }
    }

    return head;
}

int main() {
    int size1, size2;

    std::cout << "Enter the number of nodes for the first list: ";
    std::cin >> size1;
    Node* head1 = createList(size1);

    std::cout << "Enter the number of nodes for the second list: ";
    std::cin >> size2;
    Node* head2 = createList(size2);

    bool result = compare(head1, head2);

    if (result) {
        std::cout << "The lists are identical.\n";
    } else {
        std::cout << "The lists differ.\n";
    }

    // Звільнення пам'яті
    while (head1 != nullptr) {
        Node* temp = head1;
        head1 = head1->next;
        delete temp;
    }

    while (head2 != nullptr) {
        Node* temp = head2;
        head2 = head2->next;
        delete temp;
    }

    return 0;
}
