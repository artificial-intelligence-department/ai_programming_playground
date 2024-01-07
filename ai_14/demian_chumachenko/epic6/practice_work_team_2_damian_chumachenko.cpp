#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);
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

    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool compare(Node* node1, Node* node2) {
        if (node1 == nullptr && node2 == nullptr) {
            return true;
        }

        if (node1 == nullptr || node2 == nullptr) {
            return false;
        }

        return node1->data == node2->data && compare(node1->next, node2->next);
    }

    bool compareLists(LinkedList& list1, LinkedList& list2) {
        return compare(list1.head, list2.head);
    }
};

int main() {
    LinkedList list;
    LinkedList list2;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    list2.insert(1);
    list2.insert(2);
    list2.insert(3);
    list2.insert(5);

    cout << (list.compareLists(list, list2) ? "true" : "false") << endl;

    list.print();
    list.print();

    return 0;
}