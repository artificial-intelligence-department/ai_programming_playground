#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Node {
    char* data;
    Node* next;
    Node* prev;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addElement(const char* data) {
        Node* newNode = new Node{strdup(data), nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void printList() const {
        if (head == nullptr) {
            cout << "The list is empty" << endl;
        } else {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    void destroyList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete[] current->data;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void writeToFile(const char* filename) const {
       ofstream file(filename);
        Node* current = head;
        while (current != nullptr) {
            file << current->data << endl;
            current = current->next;
        }
        file.close();
    }

    void restoreFromFile(const char* filename) {
        destroyList(); 
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            addElement(line.c_str());
        }
        file.close();
    }

    void deleteElementByNumber(int position) {
        if (head == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }

        Node* current = head;
        for (int i = 1; i < position && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Element with position " << position << " does not exist" << endl;
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }

        delete[] current->data;
        delete current;
    }

    void addKElementsToBeginning(int k) {
        for (int i = 0; i < k; ++i) {
            cout << "Enter a string for a new element: ";
            string input;
            getline(cin, input);

            addElement(input.c_str());
        }
    }

    ~LinkedList() {
        destroyList();
    }
};

int main() {
    LinkedList list;

    list.addElement("One");
    list.addElement("Two");
    list.addElement("Three");

   
    cout << "List after adding elements:" << endl;
    list.printList();

    list.writeToFile("list.txt");

    list.destroyList();

    cout << "List after destruction:" << endl;
    list.printList();

    list.restoreFromFile("list.txt");

    cout << "Restored list:" << endl;
    list.printList();

    list.destroyList();

    LinkedList doublyList;

    doublyList.addElement("A");
    doublyList.addElement("B");
    doublyList.addElement("C");
    doublyList.addElement("D");

   cout << "Doubly linked list before changes:" << endl;
    doublyList.printList();

    doublyList.deleteElementByNumber(2);
    cout << "Doubly linked list after deleting element with number 2:" << endl;
    doublyList.printList();

    int k = 2;
    doublyList.addKElementsToBeginning(k);
    cout << "Doubly linked list after adding " << k << " elements to the beginning:" << endl;
    doublyList.printList();

    return 0;
}
