#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    int key;
    Node* next;
    Node* prev;
};
struct DblLinkedList {
    size_t size;
    Node* head;
    Node* tail;
};
// Функція для створення порожнього списку
DblLinkedList* nullDblLinkedList() {
    DblLinkedList* tmp = new DblLinkedList;
    tmp->size = 0;
    tmp->head = tmp->tail = nullptr;
    return tmp;
}
// Функція для додавання елемента в кінець списку
void addElement(DblLinkedList* list, int value) {
    Node* tmp = new Node;
    tmp->key = value;
    tmp->next = nullptr;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
    if (list->head == nullptr) {
        list->head = tmp;
    }
    list->size++;
}

// Функція для друку списку
void printList(const DblLinkedList* list) {
    Node* current = list->head;
    if (current == nullptr) {
        cout << "The list is empty" << endl;
    } else {
        while (current != nullptr) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }
}

// Функція для знищення елемента після елемента із заданим номером та додавання К елементів у початок списку
void manipulateList(DblLinkedList* list, size_t indexToDeleteAfter, int K) {
    Node* current = list->head;
    size_t currentIndex = 0;
    while (current != nullptr && currentIndex < indexToDeleteAfter) {
        current = current->next;
        currentIndex++;
    }
    if (current != nullptr && current->next != nullptr) {
        Node* toDelete = current->next;
        current->next = toDelete->next;
        if (toDelete->next) {
            toDelete->next->prev = current;
        }
        delete toDelete;
        list->size--;
    }
    for (int i = 0; i < K; i++) {
        Node* newElement = new Node;
        newElement->key = i + 1;
        newElement->next = list->head;
        newElement->prev = nullptr;
        if (list->head) {
            list->head->prev = newElement;
        }
        list->head = newElement;
        if (list->tail == nullptr) {
            list->tail = newElement;
        }
        list->size++;
    }
}
// Функція для знищення списку
void deleteList(DblLinkedList*& list) {
    Node* current = list->head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    delete list;
    list = nullptr;
}
// Функція для запису списку у файл
void writeToFile(const DblLinkedList* list, const std::string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        Node* current = list->head;
        while (current != nullptr) {
            file << current->key << " ";
            current = current->next;
        }
        file.close();
    } else {
        cout << "Error opening file for writing." << endl;
    }
}
// Функція для відновлення списку з файлу
void restoreFromFile(DblLinkedList* list, const std::string& filename) {
    deleteList(list);
    ifstream file(filename);
    if (file.is_open()) {
        int value;
        while (file >> value) {
            addElement(list, value);
        }
        file.close();
    } else {
        cout << "Error opening file for reading." << endl;
    }
}
int main() {
    DblLinkedList* my_list = nullDblLinkedList();
    int num;
    cout << "Enter the number of elements: ";
    cin >> num;
    for (int i = 0; i < num; i++) {
        int value;
        cout << "Enter element " << (i + 1) << ": ";
        cin >> value;
        addElement(my_list, value);
    }
    cout << "Initial list: ";
    printList(my_list);
    int indexToDeleteAfter;
    cout << "Enter the index after which to delete an element: ";
    cin >> indexToDeleteAfter;
    int numElementsToAdd;
    cout << "Enter the number of elements to add to the beginning: ";
    cin >> numElementsToAdd;
    manipulateList(my_list, indexToDeleteAfter, numElementsToAdd);
    cout << "List after operations: ";
    printList(my_list);
    writeToFile(my_list, "output.txt");
    deleteList(my_list);
    restoreFromFile(my_list, "output.txt");
    cout << "Restored list: ";
    printList(my_list);
    deleteList(my_list);

    return 0;
}
