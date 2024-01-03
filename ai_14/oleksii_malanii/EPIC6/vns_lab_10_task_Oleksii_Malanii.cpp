#include <iostream>
#include <fstream>
using namespace std;
struct Node {
    int key;
    Node *next;
};
Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->next = nullptr;
    return newNode;
}
void addElements(Node** head, int start, int K) {
    Node* current;
    for (int i = 0; i < K; i++) {
        Node* newNode = new Node();
        newNode->key = start + i;
        newNode->next = nullptr;
        if (*head == nullptr) {
            *head = newNode;
        } else {
            current = *head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}
void deleteElements(Node** head, int start, int K) {
    if (*head == nullptr) return;

    Node *current = *head, *prev = nullptr;
    for (int i = 0; i < start; i++) {
        if (current == nullptr) return;
        prev = current;
        current = current->next;
    }

    for (int i = 0; i < K; i++) {
        if (current == nullptr) break;
        Node *temp = current;
        current = current->next;
        delete temp;
        if (prev != nullptr) prev->next = current;
    }
}
void printList(Node* node) {
    Node* current = node;
    while (current != nullptr) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}
void writeToFile(Node* head, const string& filename) {
    ofstream file;
    file.open(filename);
    Node* current = head;
    while (current != nullptr) {
        file << current->key << endl;
        current = current->next;
    }
    file.close();
}
void destroyList(Node** head) {
    Node *current = *head, *nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    *head = nullptr;
}
void readFromFile(Node** head, const string& filename) {
    ifstream file;
    file.open(filename);
    int key;
    while (file >> key) {
        Node* newNode = new Node();
        newNode->key = key;
        newNode->next = *head;
        *head = newNode;
    }
    file.close();
}
int main() {
    Node* list = nullptr;
    return 0;
}
