#include <iostream>

struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* add(Node *n1, Node *n2) { //У циклі обчислюється сума та перенос, створюється новий вузол з розрядом суми, і цей вузол додається до кінця результату.
    Node *result = nullptr;
    Node *current = nullptr;
    int carry = 0;

    while (n1 || n2 || carry) {
        int sum = (n1 ? n1->data : 0) + (n2 ? n2->data : 0) + carry; //використовується для переносу при додаванні розрядів.
        carry = sum / 10;

        Node *newNode = new Node(sum % 10);

        if (!result) {
            result = newNode;
            current = result;
        } else {
            current->next = newNode;
            current = newNode;
        }

        if (n1) n1 = n1->next;
        if (n2) n2 = n2->next;
    }

    return result;
}

void printList(Node *head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node *num1 = new Node(9);
    num1->next = new Node(7);
    num1->next->next = new Node(3);

    Node *num2 = new Node(2);
    num2->next = new Node(4);
    num2->next->next = new Node(8);

    std::cout << "Number 1: ";
    printList(num1);

    std::cout << "Number 2: ";
    printList(num2);

    Node *result = add(num1, num2);

    std::cout << "Sum: ";
    printList(result);

    delete num1;
    delete num2;
    delete result;

    return 0;
}
