#include <iostream>
#include <fstream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addNode(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void deleteNode(int position) {
        if (head == nullptr) {
           
            return;
        }

        Node* temp = head;
        if (position == 0) {
            head = temp->next;
            delete temp;
            return;
        }

        for (int i = 0; temp != nullptr && i < position - 1; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            
            return;
        }

        Node* nextNode = temp->next->next;
        delete temp->next;
        temp->next = nextNode;
    }

    void addKElemsFromPosition(int value, int position, int k) {
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < position; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            
            return;
        }

        for (int i = 0; i < k; ++i) {
            Node* newNode = new Node(value + i);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode;
        }
    }

    void printList() {
        if (head == nullptr) {
            
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void writeToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            file << temp->data << " ";
            temp = temp->next;
        }
        file.close();
    }

    void deleteList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void restoreFromFile(const std::string& filename) {
        deleteList();

        std::ifstream file(filename);
        if (!file.is_open()) {
            
            return;
        }

        int value;
        while (file >> value) {
            addNode(value);
        }
        file.close();
    }
};

int main() {
    LinkedList list;

    for (int i = 10; i >= 1; --i) {
        list.addNode(i);
    }
    list.printList();

    list.deleteNode(5);
    list.printList();

    list.addKElemsFromPosition(7, 5, 3);
    list.printList();

    return 0;
}
