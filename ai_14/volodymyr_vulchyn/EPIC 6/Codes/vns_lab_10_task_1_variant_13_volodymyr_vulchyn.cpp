#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Node {
    char* key;
    Node* prev;
    Node* next;
};

Node* createNode(const char* str) {
    Node* newNode = new Node;
    newNode->key = strdup(str);
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

Node* createList(const char* keys[], int n) {
    if (n == 0) return nullptr;
    
    Node* head = createNode(keys[0]);
    Node* tail = head;

    for (int i = 1; i < n; ++i) {
        Node* newNode = createNode(keys[i]);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

void destroyList(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        free(current->key);
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

void removeKElements(Node*& head, int k) {
    for (int i = 0; i < k && head != nullptr; ++i) {
        Node* nextNode = head->next;
        free(head->key);
        delete head;
        head = nextNode;
    }
}

void insertAfter(Node*& head, const char* target, const char* str) {
    Node* current = head;
    while (current != nullptr) {
        if (strncmp(current->key, target, strlen(target)) == 0) {
            Node* newNode = createNode(str);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}

void saveListToFile(const char* filename, Node* head) {
    ofstream file(filename);
    Node* current = head;
    while (current != nullptr) {
        file << current->key << endl;
        current = current->next;
    }
    file.close();
}

Node* loadListFromFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return nullptr;
    }

    Node* head = nullptr;
    string line;
    while (getline(file, line)) {
        const char* str = line.c_str();
        if (head == nullptr) {
            head = createNode(str);
        } else {
            Node* newNode = createNode(str);
            Node* tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->prev = tail;
        }
    }

    file.close();
    return head;
}

int main() {
    const char* keys[] = {"apple", "banana", "cherry", "date", "grape"};
    int n = sizeof(keys) / sizeof(keys[0]);

    Node* list = createList(keys, n);

    cout << "Original List: ";
    printList(list);

    int k = 2;
    removeKElements(list, k);
    cout << "List after removing " << k << " elements: ";
    printList(list);

    const char* target = "ch";
    const char* strToAdd = "chocolate";
    insertAfter(list, target, strToAdd);
    cout << "List after adding \"" << strToAdd << "\" after element starting with \"" << target << "\": ";
    printList(list);

    const char* filename = "list.txt";
    saveListToFile(filename, list);
    cout << "List saved to file: " << filename << endl;

    destroyList(list);

    list = loadListFromFile(filename);
    cout << "List loaded from file: ";
    printList(list);

    destroyList(list);

    return 0;
}
