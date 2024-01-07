#include <iostream>
using namespace std;

struct Node {
    int data; //всі елементи списку є int
    Node* next; //вказівник на наступний елемент
    
    Node(int value) : data(value), next(nullptr) {} //конструктор data - значення елемента
};

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next; //next привласнює вказівник next, що знаходиться в current
        current->next = prev; //current отримав вказівник попереднього і записав його як вказівник наступного елементу
        prev = current; //вказівник current став prev
        current = next;
    }

    return prev; //новий початок списку після реверсу
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Input list: ";
    printList(head);
    head = reverse(head);

    cout << "Output list: ";
    printList(head);

    return 0;
}
