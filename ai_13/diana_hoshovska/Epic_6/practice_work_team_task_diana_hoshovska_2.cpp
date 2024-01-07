#include <iostream>
using namespace std;

struct Node {
    int data; // всі елементи списку є int
    Node* next; // вказівник на наступний елемент
    
    Node(int value) : data(value), next(nullptr) {} // конструктор data - значення елемента
};

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

bool compare(Node* h1, Node* h2) {
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    if (h1 != nullptr || h2 != nullptr) {//один список більший за інший
        return false;
    }
    return true;
}
int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    int n, m, value;

    cout << "Enter the number of elements for list 1: ";
    cin >> n;
    cout << "Enter the elements for list 1: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        if (head1 == nullptr) { //перевірка, чи список порожній
            head1 = new Node(value);
        } else {
            Node* temp = head1;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node(value);
        }
    }
    cout << "Enter the number of elements for list 2: ";
    cin >> m;
    cout << "Enter the elements for list 2: ";
    for (int i = 0; i < m; i++) {
        cin >> value;
        if (head2 == nullptr) {
            head2 = new Node(value);
        } else {
            Node* temp = head2;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node(value);
        }
    }

    cout << "List 1: ";
    printList(head1);
    cout << "List 2: ";
    printList(head2);

    if (compare(head1, head2)) {
        cout << "Lists are equal." << endl;
    } else {
        cout << "Lists are not equal." << endl;
    }

    return 0;
}
