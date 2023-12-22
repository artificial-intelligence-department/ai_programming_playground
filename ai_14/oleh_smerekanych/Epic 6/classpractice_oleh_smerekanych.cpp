#include <iostream>

using namespace std;

// Визначення структури для вузла списку
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Визначення класу для однонаправленого списку
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Метод для додавання елемента у кінець списку
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Метод для реверсу списку
    Node* reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;

        return head;
    }

    // Метод для виведення списку
    void print_now_list() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Додавання елементів у список
    for (int i = 1; i <= 5; ++i) {
        list.append(i);
    }

    cout << "Original List: ";
    list.print_now_list();

    // Реверс списку
    list.reverse();

    cout << "Reversed List: ";
    list.print_now_list();

    return 0;
}
