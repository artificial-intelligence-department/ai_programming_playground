#include <iostream>
#include <fstream>

struct Node {
    int data; 
    Node* next; 
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList {
private:
    Node* head; 
public:
    LinkedList() : head(nullptr) {}
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void print() {
        if (!head) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    void deleteElements(int startIdx, int K) {
        if (!head) {
            return;
        }
        if (startIdx == 0) {
            while (K > 0 && head) {
                Node* temp = head;
                head = head->next;
                delete temp;
                K--;
            }
        } else {
            Node* current = head;
            for (int i = 0; i < startIdx - 1 && current; i++) {
                current = current->next;
            }
            if (!current || !current->next) {
                return;
            }
            Node* prev = current;
            current = current->next;
            while (K > 0 && current) {
                prev->next = current->next;
                delete current;
                current = prev->next;
                K--;
            }
        }
    }
    void insertBefore(int key, int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        if (head->data == key) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            if (current->next->data == key) {
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
    }
    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file" << std::endl;
            return;
        }
        Node* current = head;
        while (current) {
            file << current->data << " ";
            current = current->next;
        }
        file.close();
    }
    void destroy() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    std::cout << "List:" << std::endl;
    list.print();
    int startIdx = 2; 
    int K = 2; 
    list.deleteElements(startIdx, K);
    std::cout << "List after deleting:" << std::endl;
    list.print();
    int key = 1; 
    int val = 6; 
    list.insertBefore(key, val);
    std::cout << "List after adding:" << std::endl;
    list.print();
    list.saveToFile("list.txt");
    list.destroy();
    std::cout << "List after removing:" << std::endl;
    list.print();
    LinkedList restoredList;
    std::ifstream file("list.txt");
    int value;
    while (file >> value) {
        restoredList.append(value);
    }
    std::cout << "Rebuild list:" << std::endl;
    restoredList.print();
    restoredList.destroy();
    return 0;
}
