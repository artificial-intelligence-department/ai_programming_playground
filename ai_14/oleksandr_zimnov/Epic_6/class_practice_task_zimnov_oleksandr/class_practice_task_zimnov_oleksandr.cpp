#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void print(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverse(Node* head) {
    Node* temp = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = temp;
        temp = current;
        current = next;
    }
    
    return temp;
}

Node* createList(int arr[], int size) {
    if (size == 0) {
        return nullptr;
    }
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}
bool compare(Node *h1, Node *h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false; 
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1 == nullptr && h2 == nullptr;
}

int main() {
    cout<<"Task №1"<<endl;
    int arr[] = {99, 87, 68, 62, 55, 34, 22, 19, 9};
    Node *head = createList(arr, sizeof(arr) / sizeof(arr[0]));
    cout << "List: ";
    print(head);
    head = reverse(head);
    cout << "Reverse list: ";
    print(head);
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    cout<<"Task №2"<<endl;
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    Node *head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    cout << "List 1: ";
    print(head1);
    cout << "List 2: ";
    print(head2);
    bool result = compare(head1, head2);
    if (result) {
        cout << "Lists are equal." << endl;
    } else {
        cout << "Lists are not equal." << endl;
    }
    while (head1 != nullptr) {
        Node *temp = head1;
        head1 = head1->next;
        delete temp;
    }
    while (head2 != nullptr) {
        Node *temp = head2;
        head2 = head2->next;
        delete temp;
    }
    return 0;
}
