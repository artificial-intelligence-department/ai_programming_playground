#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

vector<int> listIntoVector(Node* head) {
    vector<int> result;
    while (head != nullptr) {
        result.push_back(head->data);
        head = head->next;
    }
    return result;
}

Node* add(Node* n1, Node* n2) {
    vector<int> firstNumber = listIntoVector(n1);
    vector<int> secondNumber = listIntoVector(n2);
    int maxLength = max(firstNumber.size(), secondNumber.size());

    firstNumber.resize(maxLength, 0);
    secondNumber.resize(maxLength, 0);

    int a=0;
    vector<int> result;

    for (int i = 0; i < maxLength; ++i) {
        int sum = firstNumber[i] + secondNumber[i] + a;
        result.push_back(sum % 10); 
        a = sum / 10;
    }

    if (a > 0) {
        result.push_back(a);
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int number : result) {
        Node* newNode = new Node{number, nullptr};
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) {
            cout << " ";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* firstNumber = new Node{1, nullptr};
    firstNumber->next = new Node{4, nullptr};
    firstNumber->next->next = new Node{5, nullptr};

    Node* secondNumber = new Node{3, nullptr};
    secondNumber->next = new Node{0, nullptr};
    secondNumber->next->next = new Node{2, nullptr};
    secondNumber->next->next->next = new Node{7, nullptr};
    Node* sum = add(firstNumber, secondNumber);
    printList(sum);

    while (firstNumber != nullptr) {
        Node* temp = firstNumber;
        firstNumber = firstNumber->next;
        delete temp;
    }

    while (secondNumber != nullptr) {
        Node* temp = secondNumber;
        secondNumber = secondNumber->next;
        delete temp;
    }

    while (sum != nullptr) {
        Node* temp = sum;
        sum = sum->next;
        delete temp;
    }

    return 0;
}