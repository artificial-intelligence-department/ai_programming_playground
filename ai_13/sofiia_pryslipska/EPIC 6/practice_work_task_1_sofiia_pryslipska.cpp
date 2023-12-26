//Реверс списку
#include <iostream>
using namespace std;

// Вузол однозв'язного списку
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Клас для роботи зі списком
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Метод додавання елемента в кінець списку
    void addNode(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Метод виведення списку
    void printList(Node* start) {
        while (start != nullptr) {
            cout << start->data << " ";
            start = start->next;
        }
        cout << endl;
    }

    // Метод реверсу списку
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

        return prev; // Нова голова списку (після реверсу)
    }

    // Метод реверсування списку та виведення його на екран
    void reverseAndPrint() {
        cout << "Incoming list: ";
        printList(head);

        head = reverse(head);

        cout << "reversed list: ";
        printList(head);
    }
};

int main() {
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    list.reverseAndPrint();

    return 0;
}
