#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* create_list() {
    return nullptr;
}

Node* reverse_list(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

bool compare(Node* list_1, Node* list_2) {
    while (list_1 != nullptr && list_2 != nullptr) {
        if (list_1->data != list_2->data)
            return false;
        list_1 = list_1->next;
        list_2 = list_2->next;
    }
    return (list_1 == nullptr && list_2 == nullptr);
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* list1 = create_list();
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        insertAtEnd(list1, a);
    }

    Node* list2 = create_list();
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        insertAtEnd(list2, a);
    }
    Node* reversedList1 = reverse_list(list1);
    cout<<"Reversed list: "<<endl;
    print(reversedList1);
    cout<<endl;
    int result1 = compare(reversedList1, list2);
    cout << result1 << endl;

    list1 = reverse_list(reversedList1);

    int result2 = compare(list1, list2);
    cout << result2 << endl;

    return 0;
}