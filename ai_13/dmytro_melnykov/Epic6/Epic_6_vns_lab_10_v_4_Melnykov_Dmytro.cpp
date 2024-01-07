#include <iostream>
#include <fstream>

struct Node {
    int key;
    Node* next;
};

struct LinkedList {
    Node* head;
};

// Function to create an empty linked list
void createList(LinkedList& list) {
    list.head = nullptr;
}

// Function to print the linked list
void printList(const LinkedList& list) {
    if (list.head == nullptr) {
        std::cout << "The list is empty." << std::endl;
    } else {
        Node* current = list.head;
        std::cout << "List elements:";
        while (current != nullptr) {
            std::cout << " " << current->key;
            current = current->next;
        }
        std::cout << std::endl;
    }
}

// Function to add an item to the linked list
void addItem(LinkedList& list, int item) {
    Node* newNode = new Node{item, nullptr};
    if (list.head == nullptr) {
        list.head = newNode;
    } else {
        Node* current = list.head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete an item from the linked list
void deleteItem(LinkedList& list, int item) {
    if (list.head == nullptr) {
        std::cout << "Cannot delete from an empty list." << std::endl;
        return;
    }

    Node* current = list.head;
    Node* prev = nullptr;

    while (current != nullptr && current->key != item) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << "Item " << item << " not found in the list." << std::endl;
    } else {
        if (prev == nullptr) {
            list.head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        std::cout << "Item " << item << " deleted from the list." << std::endl;
    }
}

// Function to save the linked list to a file
void saveListToFile(const LinkedList& list, const std::string& fileName) {
    std::ofstream outFile(fileName);
    Node* current = list.head;
    while (current != nullptr) {
        outFile << current->key << " ";
        current = current->next;
    }
    outFile.close();
    std::cout << "List saved to " << fileName << "." << std::endl;
}

// Function to delete the linked list
void deleteList(LinkedList& list) {
    Node* current = list.head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    list.head = nullptr;
    std::cout << "List deleted." << std::endl;
}

// Function to write the linked list to a file, destroy it, and print it with a message if it's empty
void writeListToFileAndDestroy(LinkedList& list, const std::string& fileName) {
    saveListToFile(list, fileName);
    deleteList(list);
    printList(list);
}

// Function to restore the linked list from a file
void restoreListFromFile(LinkedList& list, const std::string& fileName) {
    std::ifstream inFile(fileName);
    int item;
    deleteList(list); // Clear the existing list
    while (inFile >> item) {
        addItem(list, item);
    }
    inFile.close();
    std::cout << "List restored from " << fileName << "." << std::endl;
}

int main() {
    LinkedList myList;

    createList(myList);
    printList(myList);

    addItem(myList, 42);
    addItem(myList, 10);
    addItem(myList, 8);
    printList(myList);

    deleteItem(myList, 10);
    printList(myList);

    saveListToFile(myList, "myList.txt");

    writeListToFileAndDestroy(myList, "myList2.txt");

    restoreListFromFile(myList, "myList.txt");
    printList(myList);

    deleteList(myList);

    return 0;
}
