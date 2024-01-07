#include <iostream>
#include <fstream>
#include <cstring>

struct Node {
    char* data;
    Node* prev;
    Node* next;
};

// Функція для створення нового елемента списку
Node* createNode(const char* data) {
    Node* newNode = new Node;
    
    newNode->data = new char[strlen(data) + 1];
    strcpy(newNode->data, data);
    
    newNode->prev = nullptr;
    newNode->next = nullptr;
    
    return newNode;
}

// Функція для додавання елемента в кінець списку
void addNode(Node*& head, const char* data) {
    Node* newNode = createNode(data);
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Функція для видалення елемента зі списку, з однаковими ключовими полями
void removeDuplicates(Node*& head, const char* key) {
    Node* current = head;
    
    while (current != nullptr) {
        if (strcmp(current->data, key) == 0) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            
            Node* temp = current;
            current = current->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

// Функція для додавання елемента після елемента з заданим ключовим полем
void insertAfter(Node*& head, const char* key, const char* data) {
    Node* current = head;
    
    while (current != nullptr) {
        if (strcmp(current->data, key) == 0) {
            Node* newNode = createNode(data);
            
            newNode->next = current->next;
            newNode->prev = current;
            
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            
            current->next = newNode;
            
            break;
        }
        
        current = current->next;
    }
}

// Функція для друку списку
void printList(const Node* head) {
    const Node* current = head;
    
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    
    std::cout << std::endl;
}

// Функція для запису списку у файл
void saveListToFile(const Node* head, const std::string& filename) {
    std::ofstream file(filename);
    const Node* current = head;
    
    while (current != nullptr) {
        file << current->data << std::endl;
        current = current->next;
    }
    
    file.close();
}

// Функція для знищення списку
void destroyList(Node*& head) {
    Node* current = head;
    
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete[] temp->data;
        delete temp;
    }
    
    head = nullptr;
}

// Функція для відновлення списку з файлу
void restoreListFromFile(Node*& head, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    
    destroyList(head);
    
    while (std::getline(file, line)) {
        addNode(head, line.c_str());
    }
    
    file.close();
}

int main() {
    Node* head = nullptr;
    
    // Створення списку
    addNode(head, "Hello");
    addNode(head, "World");
    
    // Додавання елемента "!" після елемента "World"
        insertAfter(head, "World", "!");
    
    // Друк списку
    std::cout << "List: ";
    printList(head);
    
    // Запис списку у файл
    saveListToFile(head, "list.txt");
    
    // Знищення списку
    destroyList(head);
    
    // Відновлення списку з файлу
    restoreListFromFile(head, "list.txt");
    
    // Видалення елементів з ключовим полем "World"
    removeDuplicates(head, "World");
    
    // Друк списку після видалення елементів
    std::cout << "List after deletion: ";
    printList(head);
    
    return 0;
}