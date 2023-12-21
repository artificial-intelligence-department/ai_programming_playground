//
// Created by olehio-p on 12/7/2023.
//
#include <iostream>

struct Node {
    int data;
    Node* next;

    explicit Node(int val)  {
        data = val;
        next = nullptr;
    }
};

void append(Node*& head, int val) {
    Node* newNode = new Node(val);
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

void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

Node* reverse(Node* head) {
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

bool compare(Node* list1, Node* list2) {
    while (list1 && list2) {
        if (list1->data != list2->data) {
            return false;
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    return (list1 == nullptr && list2 == nullptr);
}

Node* addLists(Node* list1, Node* list2) {
    Node* result = nullptr;
    Node* current = nullptr;
    int carry = 0;

    while (list1 || list2 || carry) {
        int sum = (list1 ? list1->data : 0) + (list2 ? list2->data : 0) + carry;
        carry = sum / 10;

        if (result == nullptr) {
            result = new Node(sum % 10);
            current = result;
        } else {
            current->next = new Node(sum % 10);
            current = current->next;
        }

        if (list1) list1 = list1->next;
        if (list2) list2 = list2->next;
    }

    return result;
}


int main() {
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);

    std::cout << "Input List: ";
    printList(head);

    head = reverse(head);

    std::cout << "Reversed List: ";
    printList(head);

    Node* list1 = nullptr;
    append(list1, 1);
    append(list1, 2);
    append(list1, 3);
    std::cout << "List 1: ";
    printList(list1);

    Node* list2 = nullptr;
    append(list2, 1);
    append(list2, 2);
    append(list2, 3);
    std::cout << "List 2: ";
    printList(list2);

    bool result = compare(list1, list2);

    std::cout << "Lists are " << (result ? "equal" : "not equal") << std::endl;

    Node* list3 = nullptr;
    append(list3, 9);
    append(list3, 7);
    append(list3, 3);

    Node* list4 = nullptr;
    append(list4, 5);
    append(list4, 6);
    append(list4, 4);

    Node* sumList = addLists(list3, list4);

    std::cout << "List 3: ";
    list3 = reverse(list3);
    printList(list3);

    list4 = reverse(list4);
    std::cout << "List 4: ";
    printList(list4);

    std::cout << "Sum List: ";
    sumList = reverse(sumList);
    printList(sumList);

    return 0;
}