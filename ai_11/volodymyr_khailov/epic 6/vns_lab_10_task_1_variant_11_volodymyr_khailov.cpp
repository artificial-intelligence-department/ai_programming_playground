#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node {
public:
    string data;
    Node* prev;
    Node* next;

    Node(const string& value) : data(value), prev(nullptr), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addElement(const string& data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
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

    void printList() const {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void deleteElement(const string& key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Element with a key '" << key << "' not found" << endl;
    }

    void addElementAtPosition(const string& data, int position) {
        Node* newNode = new Node(data);
        if (head == nullptr || position <= 1) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Error: Invalid insertion position" << endl;
            } else {
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != nullptr) {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
            }
        }
    }

    void destroyList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void saveListToFile(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error with opening file for writing in" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            file << temp->data << endl;
            temp = temp->next;
        }

        file.close();
    }

    static LinkedList restoreListFromFile(const string& filename) {
        LinkedList newList;

        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error with opening file for reading" << endl;
            return newList;
        }

        string buffer;
        while (getline(file, buffer)) {
            newList.addElement(buffer);
        }

        file.close();
        return newList;
    }
};

int main() {
    LinkedList list;

    list.addElement("red");
    list.addElement("green");
    list.addElement("blue");

    cout << "Created list: ";
    list.printList();

    list.deleteElement("green");
    cout << "List after deleting the element with the key 'green': ";
    list.printList();

    list.addElementAtPosition("qwerty", 2);
    cout << "List after adding the 'qwerty' element at position 2: ";
    list.printList();

    string filename = "linkedlist.txt";
    list.saveListToFile(filename);
    list.destroyList();
    cout << "List after destruction: ";
    list.printList();

    list = LinkedList::restoreListFromFile(filename);
    cout << "Restored list: ";
    list.printList();

    list.destroyList();
    cout << "List after final destruction: ";
    list.printList();

    return 0;
}
