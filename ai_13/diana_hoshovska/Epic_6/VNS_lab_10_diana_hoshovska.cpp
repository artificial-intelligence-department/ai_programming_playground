#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

void appendNode(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void processList(Node*& head, int targetIndex, int K) {
    if (!head) {
        cout << "The list is empty." << endl;
        return;
    }

    Node* temp = head;
    int currentIndex = 0;

    
    while (temp && currentIndex != targetIndex) { //пошук елемент зі заданим номером
        temp = temp->next;
        currentIndex++;
    }

    if (temp) { //елемент знайдено
        for (int i = 0; i < K && temp->prev; ++i) { //видалення К елементів перед елементом
            Node* toDelete = temp->prev;
            temp->prev = toDelete->prev;
            if (toDelete->prev) {
                toDelete->prev->next = temp;
            }
            delete toDelete;
        }
        for (int i = 0; i < K; ++i) { //додавання елементів у кінець списку
            int newValue;
            cout << "Enter a value for each element: ";
            cin >> newValue;
            appendNode(head, newValue);
        }
    } else {
        cout << "Element is not found." << endl;
    }
}

void printList(const Node* head) {
    const Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 10; ++i) {
        appendNode(head, i);
    }
    cout << "Output list: ";
    printList(head);

    int targetIndex, K;
    cout << "Enter a number of element and a quantity of elements to change: ";
    cin >> targetIndex >> K;

    processList(head, targetIndex, K);
    cout << "Result: ";
    printList(head);

    return 0;
}
