#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;//взагалі мала б бути в private зі слів чатагпт, але так проблем вроді теж нема

    LinkedList() : head(nullptr) {}

    // Додавання елемента в кінець списку
    void addElement(int value) {
        Node* newNode = new Node(value);
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

    // Метод реверсу
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;  // новий початок списку
    }

    // Виведення списку
    void printList(Node* list) {
        while (list) {
            std::cout << list->data << " ";
            list = list->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList linkedList;

    linkedList.addElement(1);
    linkedList.addElement(2);
    linkedList.addElement(3);
    linkedList.addElement(4);

    std::cout << "Вихідний список: ";
    linkedList.printList(linkedList.reverse(linkedList.head));

    return 0;
}