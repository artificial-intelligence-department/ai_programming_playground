#include <iostream>
using namespace std;

// Структура вузла
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Клас зв'язаного списку
class LinkedList {
public:
    Node* head;

    // Конструктор за замовчуванням
    LinkedList() : head(nullptr) {}

    // Додавання елемента в кінець списку
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Метод реверсу списку
    Node* reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    // Друкує елементи списку
    void printList(Node* list) {
        while (list) {
            cout << list->data << " ";
            list = list->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        linkedList.push_back(value);
    }

    cout << "Original List: ";
    linkedList.printList(linkedList.head);

    cout << "Reversed List: ";
    linkedList.printList(linkedList.reverse());

    return 0;
}
