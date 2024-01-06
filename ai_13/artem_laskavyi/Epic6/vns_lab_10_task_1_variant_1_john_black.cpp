#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    char* data;
    Node* next;
    Node* prev;

    Node(const char* str) : next(nullptr), prev(nullptr) {
        data = new char[strlen(str)];
        strcpy(data, str);
    }

    ~Node() {
        delete[] data;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void createList() {
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;
        cin.ignore(); 
        
        for (int i = 0; i < n; i++) {
            char* data = new char[256];
            cin.getline(data, 256);
            addToEnd(data);
        }
    }

    void printList() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void addToEnd(const char* data) {
        Node* newNode = new Node(data);

        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    void deleteNodeAtPosition(int position) {
        if (!head) {
            cout << "List is already empty." << endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            delete temp;
        } else {
            int count = 1;
            Node* current = head;
            while (count < position && current) {
                current = current->next;
                ++count;
            }

            if (!current) {
                cout << "Invalid position." << endl;
                return;
            }

            current->prev->next = current->next;
            if (current->next) {
                current->next->prev = current->prev;
            }

            delete current;
        }
    }

    void saveToFile(const char* fileName) {
        ofstream file(fileName);
        if (file.is_open()) {
            Node* current = head;
            while (current) {
                file << current->data << "\n";
                current = current->next;
            }
            file.close();
            cout << "List saved to file successfully." << endl;
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    void clearList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        cout << "List deleted successfully." << endl;
    }

    void restoreFromFile(const char* fileName) {

        ifstream file(fileName);
        if (file.is_open()) {
            string data;
            while (getline(file, data)) {
                addToEnd(data.c_str());
            }
            file.close();
            cout << "List restored from file successfully." << endl;
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};

int main() {

    DoublyLinkedList myList;

    myList.createList();
    cout << "List after creation: ";
    myList.printList();

    int positionToDelete;
    cout << "Enter position to delete: ";
    cin >> positionToDelete;
    myList.deleteNodeAtPosition(positionToDelete);
    cout << "List after deletion of node: ";
    myList.printList();

    myList.saveToFile("list.txt");

    myList.clearList();
    cout << "List after deletion: ";
    myList.printList(); 

    myList.restoreFromFile("list.txt");
    cout << "List after restoration: ";
    myList.printList();

    return 0;
}
