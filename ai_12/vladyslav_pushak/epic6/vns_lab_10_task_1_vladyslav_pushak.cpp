#include <iostream>
#include <fstream>
#include <string>
#include <memory>

using namespace std;

class Node {
public:
    string data;
    shared_ptr<Node> prev;
    shared_ptr<Node> next;

    Node(const string& value) : data(value), prev(nullptr), next(nullptr) {}
};

class LinkedList {
private:
    shared_ptr<Node> head;

public:
    LinkedList() : head(nullptr) {}

    void addElement(const string& data) {
        auto newNode = make_shared<Node>(data);
        if (!head) {
            head = newNode;
        } else {
            auto temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void printList() const {
        if (!head) {
            cout << "List is empty" << endl;
        } else {
            auto temp = head;
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void deleteElement(const string& key) {
        auto current = head;
        while (current) {
            if (current->data == key) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                return;
            }
            current = current->next;
        }
        cout << "Element with a key '" << key << "' not found" << endl;
    }

    void addElementAtPosition(const string& data, int position) {
        auto newNode = make_shared<Node>(data);
        if (!head || position <= 1) {
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
        } else {
            auto temp = head;
            for (int i = 1; i < position - 1 && temp; i++) {
                temp = temp->next;
            }
            if (!temp) {
                cout << "Error: Invalid insertion position" << endl;
            } else {
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next) {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
            }
        }
    }

    void destroyList() {
        while (head) {
            auto temp = head;
            head = head->next;
        }
    }

    void saveListToFile(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error with opening file for writing in" << endl;
            return;
        }

        auto temp = head;
        while (temp) {
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
