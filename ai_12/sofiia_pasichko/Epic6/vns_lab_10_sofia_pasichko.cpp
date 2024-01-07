#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Node {
    char* data;
    Node* next;
    Node* prev;

    Node(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        next = nullptr;
        prev = nullptr;
    }
};

Node* createList() {
    return nullptr;
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
        return;
    } else { 
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

Node* addElement(Node* head, const char* str, char symbol) { //додавання елементів після заданого символу
    Node* newNode = new Node(str);

    if (head == nullptr) {
        return newNode;
    }

    Node* current = head;
    while (current != nullptr && current->data[0] != symbol) {
        current = current->next;
    }

    if (current != nullptr) {
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    return head;
}

Node* addNode(Node* head, const char* str) { //додавання елементів у кінець списку
    Node* newNode = new Node(str);

    if (head == nullptr) {
        return newNode;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

Node* removeKElements(Node* head, int K) {
    for (int i = 0; i < K && head != nullptr; ++i) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    if (head != nullptr) {
        head->prev = nullptr; 
    }
    return head;
}


void destroyList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void writeToFile(Node* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Failure" << endl;
        return;
    }

    while (head != nullptr) {
        file << head->data << " ";
        head = head->next;
    }

    file.close();
}

Node* removeKFirstElements(Node* head, int k) {
    for (int i = 0; i < k && head != nullptr; ++i) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    if (head != nullptr) {
        head->prev = nullptr;
    }
    return head;
}

Node* restoreFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Failure" << endl;
        return nullptr;
    }

    Node* head = nullptr;
    char str[256];
    while (file >> str) {
        head = addNode(head, str);
    }

    file.close();
    return head;
}

int main() {
    Node* newList = createList();

    // Додавання елементів та друк списку
    newList = addNode(newList, "Monday");
    newList = addNode(newList, "Tuesday");
    newList = addNode(newList, "Friday");
    printList(newList);
    cout << endl;

    newList = removeKFirstElements(newList, 1);
    printList(newList);
    cout << endl;

    writeToFile(newList, "file.txt"); 

    newList = addElement(newList, "Wednesday", 'T');
    printList(newList);
    cout << endl;

    writeToFile(newList, "file.txt");
    destroyList(newList);
    printList(newList);
    cout << endl;

    newList = restoreFromFile("file.txt");
    printList(newList);
    cout << endl;

    destroyList(newList);
    printList(newList);

    return 0;
}