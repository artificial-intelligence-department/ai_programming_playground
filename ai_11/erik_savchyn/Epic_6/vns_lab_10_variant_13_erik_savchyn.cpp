#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Node {
    char data[50];
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void createList();
    void printList();
    void destroyFirstKElements(int k);
    void addElementAfter(char key);
    void addElement(const char* newData);
    void writeToFile(const string& filename);
    void destroyList();
    void restoreFromFile(const string& filename);
};

void DoublyLinkedList::createList() {
    addElement("Apple");
    addElement("Banana");
    addElement("Cherry");
    addElement("Dog");
    addElement("Elephant");
    addElement("Grape");
    addElement("Horse");
}

void DoublyLinkedList::printList() {
    if (head == nullptr) {
        cout << "Список порожній" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void DoublyLinkedList::destroyFirstKElements(int k) {
    Node* current = head;
    for (int i = 0; i < k && current != nullptr; ++i) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    if (current != nullptr) {
        current->prev = nullptr;
        head = current;
    } else {
        head = nullptr;
        tail = nullptr;
    }
}

void DoublyLinkedList::addElementAfter(char key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data[0] == key) {
            Node* newNode = new Node;
            strcpy(newNode->data, "NewElement");
            newNode->prev = current;
            newNode->next = current->next;

            if (current->next != nullptr) {
                current->next->prev = newNode;
            } else {
                tail = newNode;
            }

            current->next = newNode;
            break;
        }
        current = current->next;
    }
}

void DoublyLinkedList::addElement(const char* newData) {
    Node* newNode = new Node;
    strcpy(newNode->data, newData);
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr) {
        tail->next = newNode;
    }

    tail = newNode;

    if (head == nullptr) {
        head = newNode;
    }
}

void DoublyLinkedList::writeToFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Помилка відкриття файлу для запису" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        outFile << current->data << endl;
        current = current->next;
    }

    outFile.close();
}

void DoublyLinkedList::destroyList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
}

void DoublyLinkedList::restoreFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Помилка відкриття файлу для зчитування" << endl;
        return;
    }

    destroyList();

    string line;
    while (getline(inFile, line)) {
        addElement(line.c_str());
    }

    inFile.close();
}

int main() {
    DoublyLinkedList myList;
    myList.createList();

    cout << "Початковий список:" << endl;
    myList.printList();

    int K;
    char S;
    cout << "Скільки перших елементів видаляти?" << endl;
    cin >> K;
    cout << "Після слова з яким першим символом додавати елемент?" << endl;
    cin >> S;

    myList.destroyFirstKElements(K);
    myList.addElementAfter(S);

    cout << "Список після операцій:" << endl;
    myList.printList();

    myList.writeToFile("output.txt");

    myList.destroyList();
    cout << "Список після знищення:" << endl;
    myList.printList(); // Повинно вивести "Список порожній"

    myList.restoreFromFile("output.txt");
    cout << "Відновлений список:" << endl;
    myList.printList();

    myList.destroyList();

    return 0;
}
