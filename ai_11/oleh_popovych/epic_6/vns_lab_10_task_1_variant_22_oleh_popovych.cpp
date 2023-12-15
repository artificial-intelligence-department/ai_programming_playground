//
// Created by olehio-p on 12/7/2023.
//
#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    explicit Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubleLinkedList {
    private:
        Node* head;
        Node* tail;

    public:
        DoubleLinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void deleteByKey(int key) {
            Node* current = head;
            while (current) {
                if (current->data == key) {
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

                    delete current;
                    break;
                }
                current = current->next;
            }
        }

        void addBeforeKey(int key, int k) {
            Node* current = head;
            while (current) {
                if (current->data == key) {
                    for (int i = 0; i < k; ++i) {
                        Node* newNode = new Node(0);
                        newNode->next = current;
                        newNode->prev = current->prev;

                        if (current->prev) {
                            current->prev->next = newNode;
                        } else {
                            head = newNode;
                        }

                        current->prev = newNode;
                    }
                    break;
                }
                current = current->next;
            }
        }

        void display() {
            Node* current = head;
            while (current) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
};

int main() {
    DoubleLinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    std::cout << "List: ";
    list.display();

    list.deleteByKey(3);
    std::cout << "List after deleting: ";
    list.display();

    list.addBeforeKey(4, 2);
    std::cout << "List after adding: ";
    list.display();

    return 0;
}