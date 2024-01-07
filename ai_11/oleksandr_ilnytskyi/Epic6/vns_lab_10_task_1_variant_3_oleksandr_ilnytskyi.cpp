#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node {
    int value;
    node* next;
    explicit node(int num) {
        value = num;
        next = nullptr;
    }
};

class LinkedList {
public:
    node* head = nullptr;
    int size = 0;

    void push(int index, int value) {
        if (index == 0) {
            if (head != nullptr) {
                node* newNode = new node(value);
                newNode->next = head;
                head = newNode;
                size += 1;
            }
            else {
                node* newNode = new node(value);
                head = newNode;
                size += 1;
            }
        }
        else {
            node* current = head;
            for (int i = 1; i < index; i++) {
                current = current->next;
            }
            node* newNode = new node(value);
            newNode->next = current->next;
            current->next = newNode;
            size += 1;
        }
    }

    void erase(int index, int deepness) {
        if (index == 0) {
            for (int i = 0; i < deepness; i++) {
                head = head->next;
                size -= 1;
            }
        }
        else {
            node* current = head;
            for (int i = 1; i < index; i++) {
                current = current->next;
            }
            for (int j = 0; j < deepness; j++) {
                current->next = current->next->next;
                size -= 1;
            }
        }
    }

    void writeFile(string fileName) {
        ofstream file(fileName);
        if (file.is_open()) {
            if (size > 0) {
                node* current = head;
                for (int i = 0; i < size; i++) {
                    node* temp = current->next;
                    file << current->value << " ";
                    erase(0, 1);
                    current = temp;
                    i--;
                }
            }
            else { cout << "Error: List is empty" << endl; }
        }
        else { cout << "Error: An error occurred while accessing file!" << endl; }
        file.close();
    }

    void restoreFromFile(string fileName) {
        ifstream file(fileName);
        if (file.is_open()) {
            if (size == 0) {
                int value;
                while (file >> value) {
                    push((size == 0) ? 0 : size, value);
                }
            }
            else { cout << "Error: Your list already contains elements, make it empty" << endl; }
        }
        else { cout << "Error: An error occurred while accessing file!" << endl; }
        file.close();
    }

    void print() {
        if (size > 0) {
            node* current = head;
            for (int i = 0; i < size; i++) {
                cout << current->value << " ";
                current = current->next;
            }
            cout << endl;
        }
        else {
            cout << "Error: List is empty" << endl;
        }
    }
};

int main() {
    LinkedList list1;
    list1.push(0, 2);
    list1.push(0, 3);
    list1.push(0, 1);
    list1.push(0, 6);
    list1.print();
    list1.erase(3, 1);
    list1.print();
    list1.erase(0, 2);
    list1.print();
    list1.push(0, 3);
    list1.push(0, 1);
    list1.push(0, 6);
    list1.print();
    list1.writeFile(string("list1.txt"));
    list1.print();
    list1.restoreFromFile(string("list1.txt"));
    list1.print();

    return 0;
}
