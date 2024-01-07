#include <iostream>
#include <fstream>
#include <string>
#include <cstring> 

using namespace std;

struct Node {
    char key[100]; 
    Node* prev;
    Node* next;
};

Node* createList() {
    return nullptr;
}

void appendNode(Node*& head, const char* key) {
    Node* newNode = new Node;
    strcpy(newNode->key, key);
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteNodeByIndex(Node*& head, int index) {
    if (head == nullptr) {
        cout << "Список порожній\n";
        return;
    }

    Node* temp = head;

    for (int i = 0; i < index && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Елемент з номером " << index << " не існує\n";
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "Список порожній\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}

void writeListToFile(Node* head, const char* filename) {
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cout << "Помилка відкриття файлу\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        outFile << temp->key << endl;
        temp = temp->next;
    }

    outFile.close();
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Node* restoreListFromFile(const char* filename) {
    Node* head = nullptr;
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cout << "Помилка відкриття файлу\n";
        return nullptr;
    }

    char key[100];
    while (inFile.getline(key, sizeof(key))) {
        appendNode(head, key);
    }

    inFile.close();
    return head;
}

int main() {
    Node* myList = createList();

    appendNode(myList, "Елемент1");
    appendNode(myList, "Елемент2");
    appendNode(myList, "Елемент3");

    cout << "Список до змін:\n";
    printList(myList);

    deleteNodeByIndex(myList, 1);
    cout << "Список після видалення:\n";
    printList(myList);

    appendNode(myList, "Елемент4");
    cout << "Список після додавання елемента:\n";
    printList(myList);

    writeListToFile(myList, "myList.txt");
    deleteList(myList);
    cout << "Список після видалення (повинно бути порожній):\n";
    printList(myList);

    myList = restoreListFromFile("myList.txt");
    cout << "Відновлений список:\n";
    printList(myList);

    deleteList(myList);

    return 0;
}
