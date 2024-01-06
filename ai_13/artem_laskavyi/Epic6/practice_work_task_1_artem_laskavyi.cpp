#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {} //конструктор
};

class LinkedList {
public:
    Node* head;
    // Конструктор за замовчуванням
    LinkedList() : head(nullptr) {}

    // Метод для додавання елемента в кінець списку
    void addNode(int val) {
        Node* newNode = new Node(val);
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

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool compare(Node* h2) {
        Node* h1 = head;

        while (h1 && h2) {
            if (h1->data != h2->data) {
                return false; // Якщо дані в вузлах не співпадають
            }
        h1 = h1->next;
        h2 = h2->next;
        }

        // Якщо один список закінчується раніше іншого, повертаємо false
        if (h1 || h2) {
        return false;
        }

        return true; // Всі елементи співпали, повертаємо true
    }

    Node* nodeSum(Node* n1, Node* n2) {
        LinkedList result;

        int rem = 0;
        while (n1 || n2 || rem) {
            int sum = (n1 ? n1->data : 0) + (n2 ? n2->data : 0) + rem;
            rem = sum / 10;

            result.addNode(sum % 10);

            if (n1) n1 = n1->next;
            if (n2) n2 = n2->next;
        }

        return result.head;
    }
};

int main() {

    LinkedList myList1;
    myList1.addNode(1);
    myList1.addNode(2);
    myList1.addNode(3);
    myList1.addNode(4);

    LinkedList myList2;
    myList2.addNode(4);
    myList2.addNode(3);
    myList2.addNode(2);
    myList2.addNode(1);

    cout << "Original List 1: ";
    myList1.printList();

    myList1.reverse();
    cout << "Reversed List 1: ";
    myList1.printList();

    if (myList1.compare(myList2.head)) {
    cout << "Lists are equal." << endl;
    }else {
    cout << "Lists are not equal." << endl;
    }

    LinkedList result1;
    result1.head = result1.nodeSum(myList1.head, myList2.head);

    cout << "Sum: ";
    result1.printList();

    
    return 0;
}
