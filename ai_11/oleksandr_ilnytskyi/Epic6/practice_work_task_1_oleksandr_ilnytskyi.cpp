#include <iostream>
#include <string>

using namespace std;

struct node {
    int value;
    node* next;
    explicit node(int num) {
        value = num;
        next = nullptr;
    }
};

class LinkedList {
public:
    node* head;
    int size;
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    // task 1
    void reverse() {
        node* current = head;
        node* prev = nullptr;
        node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // task 2
    bool compare(LinkedList comparant) {
        if (size == comparant.size) {
            node* current = head;
            node* comparantCurrent = comparant.head;
            for (int i = 0; i < size; i++) {
                if (current->value == comparantCurrent->value) {
                    current = current->next;
                    comparantCurrent = comparantCurrent->next;
                }
                else { return false; }
            }
        }
        else { return false; }
        return true;
    }

    void print() const {
        node* current = head;
        for (int i = 0; i < size; i++) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void push(int value) {
        node* newNode = new node(value);
        if (head != nullptr) {
            newNode->next = head;
            head = newNode;
            size += 1;
        }
        else {
            head = newNode;
            size += 1;
        }
    }
};

LinkedList numToLL(int num) {
    LinkedList resultNode;
    string numS = to_string(num);
    for (int i = 0; i < numS.size(); i++) {
         resultNode.push(numS[i] - '0');
    }
    return resultNode;
}

LinkedList addLists(LinkedList ll1, LinkedList ll2) {
    LinkedList resultNode;
    node* curll1 = ll1.head;
    node* curll2 = ll2.head;
    int carry = 0;
    while (curll1 != nullptr || curll2 != nullptr) {
        int sum = carry + (curll1 ? curll1->value : 0) + (curll2 ? curll2->value : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum %= 10;
        resultNode.push(sum);
        if (curll1) curll1 = curll1->next;
        if (curll2) curll2 = curll2->next;
    }
    if (resultNode.head->value == 0) { resultNode.push(1); }
    return resultNode;
}

int main() {
    LinkedList ll;
    LinkedList ll2;

    ll.push(5);
    ll.push(6);
    ll.push(2);
    ll.push(3);

    ll2.push(5);
    ll2.push(6);
    ll2.push(2);
    ll2.push(3);

    // Tests for task 1
    ll.print();
    ll.reverse();
    ll.print();

    // Tests for task 2
    cout << ll.compare(ll2) << endl;
    ll2.reverse();
    cout << ll.compare(ll2) << endl;

    // Tests for task 3
    LinkedList ll3 = numToLL(379);
    LinkedList ll4 = numToLL(682);
    LinkedList ll5 = addLists(ll3, ll4);
    ll5.print();

    return 0;
}
