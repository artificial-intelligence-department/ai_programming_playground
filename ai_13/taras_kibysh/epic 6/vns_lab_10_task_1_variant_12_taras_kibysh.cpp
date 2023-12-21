#include <iostream>
#include <fstream>
#include <cstring>

struct Node {
    char* key;
    Node* next;
    Node* prev;
};

class LinkedList {
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        destroyList();
    }

    void createList() {
        
        head = tail = nullptr;
    }

    void addElement(const char* newKey) {
        Node* newNode = new Node;
        newNode->key = strdup(newKey);
        newNode->next = nullptr;

        if (!head) {
            head = tail = newNode;
            newNode->prev = nullptr;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteElement(const char* keyToDelete) {
        Node* current = head;
        while (current) {
            if (strcmp(current->key, keyToDelete) == 0) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete[] current->key;
                delete current;
                return;
            }

            current = current->next;
        }
    }

    void printList() {
        Node* current = head;
        while (current) {
            std::cout << current->key << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void writeToFile(const char* filename) {
        std::ofstream outFile(filename);
        Node* current = head;
        while (current) {
            outFile << current->key << std::endl;
            current = current->next;
        }
        outFile.close();
    }

    void destroyList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete[] current->key;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }

    void restoreFromFile(const char* filename) {
        std::ifstream inFile(filename);
        if (!inFile.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        char buffer[256];
        while (inFile.getline(buffer, sizeof(buffer))) {
            addElement(buffer);
        }

        inFile.close();
    }

   void deleteElementsByKey(const char* keyToDelete) {
    Node* current = head;
    while (current) {
        if (strcmp(current->key, keyToDelete) == 0) {
            Node* next = current->next;
            Node* prev = current->prev;

            if (prev) {
                prev->next = next;
            } else {
                head = next;
            }

            if (next) {
                next->prev = prev;
            } else {
                tail = prev;
            }

            delete[] current->key;
            delete current;
            current = next;  
        } else {
            current = current->next; 
        }

        }

    }



    void addElementAfterKey(const char* keyToFind, const char* newKey) {
        Node* current = head;
        while (current) {
            if (strcmp(current->key, keyToFind) == 0) {
                Node* newNode = new Node;
                newNode->key = strdup(newKey);

                newNode->next = current->next;
                newNode->prev = current;

                if (current->next) {
                    current->next->prev = newNode;
                } else {
                    tail = newNode;
                }

                current->next = newNode;
                return;
            }

            current = current->next;
        }
    }

private:
    Node* head;
    Node* tail;
};

int main() {
    LinkedList list;
    list.createList();

    list.addElement("One");
    list.addElement("Two");
    list.addElement("Three");
     list.addElement("Two");

    std::cout << "Початковий лист: ";
    list.printList();

    list.writeToFile("output.txt");

    LinkedList newList;
    newList.restoreFromFile("output.txt");


    newList.deleteElementsByKey("Two");
    std::cout << "лист після видалення 'Two': ";
    newList.printList();

    newList.addElementAfterKey("One", "Yuxu");
    std::cout << "лист з добавленим новим елементом: ";
    newList.printList();

    return 0;
}
