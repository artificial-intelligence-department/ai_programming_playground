#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* Insert(Node* head, int data) {
    if (data < 0 || data > 9) {
        cout << "Invalid input. Please enter a number between 0 and 9." << endl;
        return head;
    }

    Node* temp1 = new Node;
    temp1->data = data;
    temp1->next = nullptr;

    if (head == nullptr)
        head = temp1;
    else {
        Node* temp2 = head;
        while (temp2->next != nullptr) {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
    return head;
}

Node* add(Node* n1, Node* n2) {
    Node* result = nullptr;
    Node* ostNodeInResult = nullptr;
    int perenis = 0;

    for (; n1 || n2 || perenis; n1 = n1 ? n1->next : n1, n2 = n2 ? n2->next : n2) {
    int sum = (n1 ? n1->data : 0) + (n2 ? n2->data : 0) + perenis;
    perenis = sum / 10;

    Node* newNode = new Node;
    newNode->data = sum % 10;
    newNode->next = nullptr;

    if (!result) {
        result = newNode;
        ostNodeInResult = result;
    } else {
        ostNodeInResult->next = newNode;
        ostNodeInResult = ostNodeInResult->next;
    }
}


    return result;
}

void PrintList(Node *p) {  // Node *p is a local variable
    if (p==nullptr) return;  //Exit condition
    cout << p->data << " ";       // First print the value in the node
    PrintList(p->next);              // Recursive call
    
};

int main() {
    Node* num1 = nullptr;
    Node* num2 = nullptr;

   
    num1 = Insert(num1, 9);
    num1 = Insert(num1, 7);
    num1 = Insert(num1, 3);

    num2 = Insert(num2, 1);
    num2 = Insert(num2, 6);
    num2 = Insert(num2, 9);

    cout << "Number 1: ";
    PrintList(num1);
    cout<<endl;
    cout << "Number 2: ";
    PrintList(num2);
    cout<<endl;
    Node* sum = add(num1, num2);

    cout << "Sum: ";
    PrintList(sum);

    return 0;
}

