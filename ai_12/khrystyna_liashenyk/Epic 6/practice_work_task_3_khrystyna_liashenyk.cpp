#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* getHead() {
        return head;
    }
};

Node* add(Node *n1, Node *n2) {
    LinkedList result;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum = carry;

        if (n1 != nullptr) {
            sum += n1->data;
            n1 = n1->next;
        }

        if (n2 != nullptr) {
            sum += n2->data;
            n2 = n2->next;
        }

        carry = sum / 10;
        sum %= 10;

        result.append(sum);
    }

    return result.getHead();
}

int main() {
    LinkedList num1, num2;

    string number1, number2;
    cout << "Enter the first numbers: ";
    getline(cin, number1);
    istringstream iss1(number1);
    int digit;
    while (iss1 >> digit) {
        num1.append(digit);
    }

    cout << "Enter the second numbers: ";
    getline(cin, number2);
    istringstream iss2(number2);
    while (iss2 >> digit) {
        num2.append(digit);
    }


    Node* sum = add(num1.getHead(), num2.getHead());

    cout << "Sum: ";
    while (sum != nullptr) {
        cout << sum->data << " ";
        sum = sum->next;
    }
    cout << endl;

    return 0;
}
