#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int key;
    Node* next;   
    Node(int k) : key(k), next(nullptr) {}
};

Node* createList() {
    return nullptr;
}

void addElements(Node*& head, int start, int K) {
    for (int i = 0; i < K; ++i) {
        Node* newNode = new Node(start + i);
        newNode->next = head;
        head = newNode;
    }
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "Empty list" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteElement(Node*& head, int position) {
    if (head == nullptr) {
        cout << "Empty list" << endl;
        return;
    }
    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    for (int i = 0; i < position - 1 && current->next != nullptr; ++i) {
        current = current->next;
    }
    if (current->next == nullptr || position < 0) {
        cout << "Element with current position not found" << endl;
        return;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

void writeToFile(Node* head, const char* filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "File don`t open" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        file << current->key << " ";
        current = current->next;
    }
    file.close();
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Node* restoreFromFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File don`t open" << endl;
        return nullptr;
    }
    Node* head = nullptr;
    int key;
    while (file >> key) {
        Node* newNode = new Node(key);
        newNode->next = head;
        head = newNode;
    }
    file.close();
    return head;
}

int main() {
    Node* list = createList();
    addElements(list, 1, 5);
    cout << "List after add elements: ";
    printList(list);
    deleteElement(list, 2);
    cout << "List after delete elements: ";
    printList(list);
    writeToFile(list, "list.txt");
    deleteList(list);
    cout << "List after delete: ";
    printList(list);
    list = restoreFromFile("list.txt");
    cout << "List after restore: ";
    printList(list);
    deleteList(list);
    return 0;
}
