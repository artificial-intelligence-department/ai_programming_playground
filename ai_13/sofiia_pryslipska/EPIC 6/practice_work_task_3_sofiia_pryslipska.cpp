#include <iostream>
using namespace std;
//додаємо
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* add(Node* n1, Node* n2) { //вказівники на поч списків
    Node* result = nullptr;//список, що містить суму двох чисел 
    Node* current = nullptr;
    

    while (n1 != nullptr || n2 != nullptr  ) {
        int sum=0;
        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }


        if (result == nullptr) {
            result = new Node(sum);
            current = result;
        } else {
            current->next = new Node(sum);
            current = current->next;
        }
    }

    return result;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* num1 = new Node(1);
    num1->next = new Node(2);
    num1->next->next = new Node(3);

    Node* num2 = new Node(4);
    num2->next = new Node(5);
    num2->next->next = new Node(6);

    cout << "number 1: ";
    printList(num1);

    cout << "number 2: ";
    printList(num2);

    Node* sum = add(num1, num2);
    cout << "the sum of numbers: ";
    printList(sum);

    // Очищення пам'яті
    while (num1 != nullptr) {
        Node* temp = num1;
        num1 = num1->next;
        delete temp;
    }
    while (num2 != nullptr) {
        Node* temp = num2;
        num2 = num2->next;
        delete temp;
    }
    while (sum != nullptr) {
        Node* temp = sum;
        sum = sum->next;
        delete temp;
    }

    return 0;
}















