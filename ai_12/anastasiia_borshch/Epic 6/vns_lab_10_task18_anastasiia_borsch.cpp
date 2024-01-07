#include <iostream>
#include <cstring>

struct Node {
    char* data;
    Node* prev;
    Node* next;
};

void add(Node*& head, Node*& tail, const char* value);
void deleteNode(Node*& head, Node*& tail, const char* key);
void print(const Node* head);
Node* createList(const char* values[], int size);
void destroyList(Node*& head);

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    const char* initialValues[] = {"sun", "sky", "sea"};
    int initialSize = sizeof(initialValues) / sizeof(initialValues[0]);
    head = createList(initialValues, initialSize);

    std::cout << "Initial list of elements: ";
    print(head);

    std::cout << "Enter the number of elements to add: ";
    int k;
    std::cin >> k;

    for (int i = 0; i < k; ++i) {
        char value[50]; 
        std::cout << "Enter the value for element " << i + 1 << ": ";
        std::cin >> value;
        add(head, tail, value);
    }

    std::cout << "List of elements: ";
    print(head);

    char key[50];
    std::cout << "Enter the key to delete an element: ";
    std::cin >> key;

    deleteNode(head, tail, key);

    std::cout << "Updated list of elements after deletion: ";
    print(head);

    destroyList(head);

    return 0;
}

void add(Node*& head, Node*& tail, const char* value) {
    char* newValue = new char[strlen(value) + 1];
    strcpy(newValue, value);

    Node* newNode = new Node{newValue, nullptr, nullptr};
    if (!head) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void deleteNode(Node*& head, Node*& tail, const char* key) {
    Node* current = head;
    while (current) {
        if (strcmp(current->data, key) == 0) {
            if (current->prev)
                current->prev->next = current->next;
            else
                head = current->next;

            if (current->next)
                current->next->prev = current->prev;
            else
                tail = current->prev;

            delete[] current->data;
            delete current;
            return;
        }
        current = current->next;
    }

    std::cout << "Element with key '" << key << "' not found." << std::endl;
}

void print(const Node* head) {
    if (!head) {
        std::cout << "The list is empty" << std::endl;
        return;
    }
    const Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node* createList(const char* values[], int size) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < size; ++i) {
        add(head, tail, values[i]);
    }

    return head;
}

void destroyList(Node*& head) {
    while (head) {
        Node* next = head->next;
        delete[] head->data;
        delete head;
        head = next;
    }
}
