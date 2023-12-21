#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
};

class DoubleLinkedList {
    Node* head;
    Node* tail;
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void add(string value) {
        Node* newNode = new Node{value, nullptr, tail};
        if (head == nullptr) {
            head = tail = newNode;
        } 
        else {
        tail->next = newNode;  //(*tail).next = newNode;
            tail = newNode;
        }
    }

    void add_after(string value, string after) {
        Node* current = tail;
        while (current != nullptr) {
            if (current->data == after) {
                Node* newNode = new Node{value, current->next, current};
                if (current->next != nullptr) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                if (current == tail) {
                    tail = newNode;
                }
                return;
            }
            current = current->prev;
        }
    }
    
    void print(){
        Node* current = head;
        if (current == nullptr) {
            cout << "Empty list\n";
            return;
        }
        while (current != nullptr) {
            cout << current->data << ' ';
            current = current->next;
        }
        cout << '\n';
    }

    void deleteList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void deleteNode(int amount) {
        Node* current = tail;
        for (int i = 0; i < amount; ++i) {
            if (current == nullptr) {
                return;
            }
            Node* prev = current->prev;
            if (prev != nullptr) {
                prev->next = nullptr;
            }
            delete current;
            current = prev;
        }
        tail = current;
    }

    void copy_to_file(string filename){
        ofstream file(filename);
        Node* current = head;
        while(current != nullptr){
            file << current->data << endl;
            current = current->next;
        }
        file.close();
    }

    void copy_from_file(string filename){
        ifstream file(filename);
        string value;
        while(file >> value){
            add(value);
        }
        file.close();
    }
};

int main() {
    DoubleLinkedList list;
    list.add("ya");
    list.add("tu");
    list.add("te");
    list.add("tk");
    list.add("tg");
    list.add("ge");
    list.add("uu");
    list.add("mm");
    list.print(); 
    list.deleteNode(4);
    list.print(); 
    list.add_after("ro", "tk");
    list.print(); 
    list.copy_to_file("file.txt");
    list.deleteList();
    list.print(); 
    list.copy_from_file("file.txt");
    list.print(); 
    return 0;
}