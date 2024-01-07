#include <iostream>
#include <fstream>
using namespace std;

class Node {    
public: 
    int value;
    Node* prev, * next;
};

class LinkedList{
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void frontpushList(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) 
            head->prev = newNode;
        head = newNode;
    }

    Node* getAt(int index) {
        Node* traverser = head;
        int counter = 0;
        while (counter != index) {
            if (traverser == nullptr) return traverser;
            counter++;
            traverser = traverser->next;
        }
        return traverser;
    }

    void removeNode(int index) {
        Node* traverser = getAt(index);
        if (traverser == nullptr) return;
        if (traverser->prev != nullptr) traverser->prev->next = traverser->next;
        if (traverser->next != nullptr) traverser->next->prev = traverser->prev;
        if (traverser == head) head = traverser->next;
        delete traverser;
    }
    

    void fillinfile(const char* filename) {
        ofstream fout(filename);
        if (!fout.is_open()) {
            cerr << "Error opening file" << endl;
            return;
        }

        Node* traverser = head;
        while (traverser != nullptr) {
            fout << traverser->value << " ";
            traverser = traverser->next;
        }
        fout.close();
    }

    void purifyList() {
        Node* temp = new Node();
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void printList() {
        if (head == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }
        Node* traverser = head;
        while (traverser != nullptr) {
            cout << traverser->value << " ";
            traverser = traverser->next;
        }
    }

    void outputFile(const char* filename) {
        ifstream fin(filename);
        if (!fin.is_open()) {
            cerr << "Error opening file" << endl;
            return;
        }

        int content;
        while (fin >> content) {
            frontpushList(content);
        }
        fin.close();
    }
    
};

int main() {
   LinkedList list;

   int nodenumber;
    cout << "Enter the number of nodes: ";
    cin >> nodenumber;
    for (int i = 0; i < nodenumber; i++) {
        int value;
        cout << "Enter the value of the node: ";
        cin >> value;
        list.frontpushList(value);
    }

    cout << "The list: ";
    list.printList();
    cout << endl;

    int nodeposition;
    cout << "Enter the position of the node to be deleted: ";
    cin >> nodeposition;
    list.removeNode(nodeposition);

    cout << "The list after deleting the node: ";
    list.printList();
    cout << endl;

    int additionalnode;
    cout << "Enter the value of the additional node: ";
    cin >> additionalnode;
    list.frontpushList(additionalnode);

    cout << "The list after adding the node: ";
    list.printList();
    cout << endl;

    const char* filename = "list.txt";
    list.fillinfile(filename);
    cout << "The list was written to the file" << endl;

    list.purifyList();

    cout << "The list after whole deleting: ";
    list.printList();
    cout << endl;

    list.outputFile(filename);
    cout << "The list was restored from the file" << endl;

    cout << "The list after restoring: ";
    list.printList();
    cout << endl;

    list.purifyList();

    return 0;
}