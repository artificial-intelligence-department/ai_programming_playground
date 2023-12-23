#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class List {
public:
//    Constructors
    List()
        : head(nullptr)
    {};

    [[maybe_unused]] explicit List(const string& filename)
        : head(nullptr)
    {
        copyFromFile(filename);
    };
//    Add methods
    void pushBack(const int& value){
        if (head == nullptr){
            head = new Node{value, nullptr};
        } else{
            Node* current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = new Node{value, nullptr};
        }
    };
    void insertBefore(const int& value, const int& key){
        if (head == nullptr){
            head = new Node{value, nullptr};
        } else {
            Node *previous = nullptr;
            Node *current = head;
            while (current != nullptr) {
                if (current->data == key) {
                    if (previous == nullptr) {
                        head = new Node{value, current};
                    } else {
                        previous->next = new Node{value, current};
                    }
                    return;
                }
                previous = current;
                current = current->next;
            }
        }
    };
//    Remove methods
    void remove(const int& value){
        Node* previous = nullptr;
        Node* current = head;
        while(current != nullptr){
            if (current->data == value){
                if (previous == nullptr){
                    head = current->next;
                } else{
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    };
    void clear() {
        while(head != nullptr){
            Node* current = head;
            head = head->next;
            delete current;
        }
    };
//    Print method
    void print() const {
        if (head == nullptr){
            cout << "List is empty\n";
        } else{
            Node* current = head;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    };
//    Write to file method
    void writeToFile(const string& filename){
        if (head == nullptr){
            cout << "List is empty\n";
        } else{
            ofstream file(filename, ios::trunc);
            if (file.is_open()) {
                Node *current = head;
                while (current != nullptr) {
                    file << current->data << " ";
                    current = current->next;
                }
                file << endl;
                file.close();
            } else cout << "Error! File cannot be opened!" << endl;
        }
    };
//    Copy from file method
    void copyFromFile(const string& filename){
        clear();
        ifstream file(filename);
        if (file.is_open()){
            string text;
            getline(file, text);
            if(text.empty()) return;
            head = new Node{int(text[0]) - 48, nullptr};
            Node* current = head;
            for (int i = 1; i < text.length(); i++) {
                if(text[i] != ' ') {
                    string s;
                    for (int j = i; text[j] != ' ' && j < text.length(); ++j) {
                        s.push_back(text[j]);
                        i++;
                    }
                    current->next = new Node{stoi(s), nullptr};
                    current = current->next;
                }
            }
            file.close();
        } else cout << "Error! File cannot be opened!" << endl;
    }
private:
    struct Node{
        int data;
        Node* next;
    };
    Node* head;
};

int main() {
    List list;
    for (int i = 0; i < 10; ++i) {
        list.pushBack(i);
    }
    list.print();
    cout << "Remove 5\n";
    list.remove(5);
    list.print();
    cout << "Insert 103 before 7\n";
    list.insertBefore(103,7);
    list.print();
    cout << "Write to file, clear and print\n";
    list.writeToFile("list.txt");
    list.clear();
    list.print();
    cout << "Copy from file, print\n";
    list.copyFromFile("list.txt");
    list.print();
    list.clear();
    return 0;
}
