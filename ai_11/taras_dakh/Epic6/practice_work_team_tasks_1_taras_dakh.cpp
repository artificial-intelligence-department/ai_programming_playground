#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value),next(nullptr) {}
};

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

    return prev;
}

void printList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

int main() {
    Node* originalList = new Node(1);
    originalList->next = new Node(2);
    originalList->next->next = new Node(3);
    originalList->next->next->next = new Node(4);

    std::cout << "Вихідний список: ";
    printList(originalList);

    Node* reversedList = reverse(originalList);

    std::cout << "Обернений список: ";
    printList(reversedList);

    // Очищення пам'яті
    while (reversedList != nullptr) {
        Node* temp = reversedList;
        reversedList = reversedList->next;
        delete temp;
    }

    return 0;
}
    