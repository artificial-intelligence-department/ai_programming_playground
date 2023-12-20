#include <iostream>
#include <cmath>

using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

void push(Node* &head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

int convert(Node* h, int N) {
    int result = 0;
    Node* current = h;

    for (int i = 0; i < N; i++) {
        result = result * 10 + current->data;
        current = current->next;
    }
    
    return result;
}

int main() {
    int N, n, result = 0;
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    cout << "How many numbers do you want to add in the first list? ";
    cin >> N;
    cout << "Enter the first list: ";
    
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        push(head1, k);
    }

    cout << "How many numbers do you want to add in the second list? ";
    cin >> n;
    cout << "Enter the second list: ";
    
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        push(head2, k);
    }

    result = convert(head1, N) + convert(head2, n);
    cout << "Sum of the two lists: " << result << endl;
    
    return 0;
}
