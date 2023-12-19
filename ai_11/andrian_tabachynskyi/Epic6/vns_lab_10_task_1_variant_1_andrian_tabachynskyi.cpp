#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

struct spusok {
    char* key;
    spusok* next;
    spusok* prev;

    spusok(const char* k) {
        key = new char[strlen(k) + 1];
        strcpy_s(key, strlen(k) + 1, k);
        next = nullptr;
        prev = nullptr;
    }

    ~spusok() {
        delete[] key;
    }
};

void addElement(spusok*& head, const char* key);
void createSpusok(spusok*& head);
void deleteElementByKey(spusok*& head, const char* key);
void printSpusok(spusok* head);
void destroySpusok(spusok*& head);
void addElementsToEnd(spusok*& head, int k);

int main() {
    spusok* head = nullptr;

    createSpusok(head);
    cout << "List: ";
    printSpusok(head);

    char keyToDelete[100];
    cout << "Enter key to delete: ";
    cin >> keyToDelete;
    deleteElementByKey(head, keyToDelete);
    cout << "List after deleting: ";
    printSpusok(head);

    int k;
    cout << "Enter number of elements to add at the end: ";
    cin >> k;
    addElementsToEnd(head, k);
    cout << "List after adding elements: ";
    printSpusok(head);

    destroySpusok(head);

    return 0;
}

void createSpusok(spusok*& head) {
    int N;
    char key[100];
    cout << "Enter number of elements: ";
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cout << "Element ¹" << i + 1 << ": ";
        cin >> key;
        addElement(head, key);
    }
}

void addElement(spusok*& head, const char* key) {
    spusok* newElement = new spusok(key);
    if (!head) {
        head = newElement;
    }
    else {
        spusok* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newElement;
        newElement->prev = current;
    }
}


void deleteElementByKey(spusok*& head, const char* key) {
    spusok* current = head;
    while (current != nullptr && strcmp(current->key, key) != 0) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Element not found\n";
        return;
    }

    if (current->prev) {
        current->prev->next = current->next;
    }
    else {
        head = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    }

    delete current;
}

void printSpusok(spusok* head) {
    spusok* current = head;
    while (current != nullptr) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

void destroySpusok(spusok*& head) {
    while (head != nullptr) {
        spusok* temp = head;
        head = head->next;
        delete temp;
    }
}

void addElementsToEnd(spusok*& head, int k) {
    char key[100];
    for (int i = 0; i < k; ++i) {
        cout << "Enter key for new element: ";
        cin >> key;
        addElement(head, key); 
    }
}
