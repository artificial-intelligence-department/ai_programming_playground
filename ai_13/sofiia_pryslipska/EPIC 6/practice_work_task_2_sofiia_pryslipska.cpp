#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false; // Якщо дані в вузлах не співпадають
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    // Якщо довжина списків різна, повертаємо false
    if (h1 != nullptr || h2 != nullptr) {
        return false;
    }
    return true; // Якщо всі елементи співпадають і списки однакової довжини, повертаємо true
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    //створити два списки по три вузла
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    // Додати додатковий вузол до другого списку, щоб довжини були різні
    head2->next->next->next = new Node(4);

    cout << "list 1: ";
    printList(head1);

    cout << "list 2: ";
    printList(head2);

    bool result = compare(head1, head2);

    if (result) {
        cout << "The lists are the same." << endl;
    } else {
        cout << "The lists are different." << endl;
    }

    // Очищення пам'яті
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
