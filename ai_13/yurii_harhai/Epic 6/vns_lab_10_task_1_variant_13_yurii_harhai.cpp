#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Node {
    string key;
    Node* next;
    Node* prev;
};

Node* createNode(string key) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory Error\n";
        return NULL;
    }
    newNode->key = key;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* insertNode(Node* head, string key) {
    if (head == NULL) {
        head = createNode(key);
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        Node* newNode = createNode(key);
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}


Node* deleteFirstKNodes(Node* head, int K) {
    Node* temp = head;
    Node* nextNode;
    for (int i = 0; i < K && temp != NULL; i++) {
        nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    if (temp != NULL) {
        temp->prev = NULL;
    }
    return temp;
}

Node* insertAfterKey(Node* head, char symbol, string newKey) {
    Node* temp = head;
    while (temp != NULL && temp->key[0] != symbol) {
        temp = temp->next;
    }
    if (temp != NULL) {
        Node* newNode = createNode(newKey);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
    return head;
}


Node* readListFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Can't open the file\n";
        return NULL;
    }
    Node* head = NULL;
    string key;
    while (getline(file, key)) {
        head = insertNode(head, key);
    }
    file.close();
    return head;
}
void printList(Node* head);
void deleteList(Node* &head);
void writeListToFile(Node* head, const string& filename);

int main() {
    Node* head = NULL;
    string key;
    char symbol;
    int K;

    // Введення елементів
    cout << "Enter elements, enter 'stop' when finish:\n";
    while (true) {
        cin >> key;
        if (key == "stop") break;
        head = insertNode(head, key);
    }

    printList(head);

    // Введення K
    cout << "Enter K:\n";
    cin >> K;
    head = deleteFirstKNodes(head, K);

    printList(head);

    // Введення символу і нового ключа
    cout << "Enter symbol:\n";
    cin >> symbol;
    cout << "Enter new key:\n";
    cin >> key;
    head = insertAfterKey(head, symbol, key);


    writeListToFile(head, "listss.txt");

    deleteList(head);

    head = readListFromFile("listss.txt");

    printList(head);

    deleteList(head);

    return 0;
}

void printList(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->key << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void writeListToFile(Node* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Can't open the file\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        file << temp->key << "\n";
        temp = temp->next;
    }
    file.close();
}

void deleteList(Node* &head) {
    Node* nextNode;
    while (head != NULL) {
        nextNode = head->next;
        delete head;
        head = nextNode;
    }
}