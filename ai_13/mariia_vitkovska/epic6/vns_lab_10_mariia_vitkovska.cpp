#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct ListNode {
    char data[100];
    ListNode* prev;
    ListNode* next;
};

ListNode* createList() {
    return nullptr;
}

void appendNode(ListNode*& head, const char* data) {
    ListNode* newNode = new ListNode;
    strcpy(newNode->data, data);
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
    } else {
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteByIndex(ListNode*& head, int index) {
    if (head == nullptr) {
        cout << "The list is empty\n";
        return;
    }

    ListNode* temp = head;

    for (int i = 0; i < index && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node with index " << index << " does not exist\n";
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

void printList(ListNode* head) {
    if (head == nullptr) {
        cout << "The list is empty\n";
        return;
    }

    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void writeListToFile(ListNode* head, const char* filename) {
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cout << "Error opening the file\n";
        return;
    }

    ListNode* temp = head;
    while (temp != nullptr) {
        outFile << temp->data << endl;
        temp = temp->next;
    }

    outFile.close();
}

void deleteList(ListNode*& head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

ListNode* restoreFromFile(const char* filename) {
    ListNode* head = nullptr;
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cout << "Error opening the file\n";
        return nullptr;
    }

    char data[100];
    while (inFile.getline(data, sizeof(data))) {
        appendNode(head, data);
    }

    inFile.close();
    return head;
}

int main() {
    ListNode* myList = createList();

    appendNode(myList, "Data1");
    appendNode(myList, "Data2");
    appendNode(myList, "Data3");

    cout << "List before changes:\n";
    printList(myList);

    deleteByIndex(myList, 1);
    cout << "List after deletion:\n";
    printList(myList);

    appendNode(myList, "Data4");
    cout << "List after adding a node:\n";
    printList(myList);

    writeListToFile(myList, "myList.txt");
    deleteList(myList);
    cout << "List after deletion (should be empty):\n";
    printList(myList);

    myList = restoreFromFile("myList.txt");
    cout << "Restored list:\n";
    printList(myList);

    deleteList(myList);

    return 0;
}
