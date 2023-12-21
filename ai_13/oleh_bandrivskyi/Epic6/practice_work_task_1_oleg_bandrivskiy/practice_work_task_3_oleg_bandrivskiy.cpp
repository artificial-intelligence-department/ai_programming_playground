#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* add(Node* n1, Node* n2) {
    std::stack<int> stack1, stack2;

    while (n1 != nullptr) {
        stack1.push(n1->data);
        n1 = n1->next;
    }

    while (n2 != nullptr) {
        stack2.push(n2->data);
        n2 = n2->next;
    }

    int carry = 0;
    Node* result = nullptr;

    while (!stack1.empty() || !stack2.empty() || carry != 0) {
        int sum = carry;
        
        if (!stack1.empty()) {
            sum += stack1.top();
            stack1.pop();
        }

        if (!stack2.empty()) {
            sum += stack2.top();
            stack2.pop();
        }

        carry = sum / 10;
        sum %= 10;

        Node* newNode = new Node(sum);
        newNode->next = result;
        result = newNode;
    }

    return result;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        head = head->next;
        if (head != nullptr) {
            cout << " -> ";
        }
    }
    cout << endl;
}

int main() {
    Node* num1 = new Node(7);
    num1->next = new Node(1);
    num1->next->next = new Node(6);

    Node* num2 = new Node(5);
    num2->next = new Node(9);
    num2->next->next = new Node(2);

    Node* result = add(num1, num2);

    cout << "Sum: ";
    printList(result);

    return 0;
}
