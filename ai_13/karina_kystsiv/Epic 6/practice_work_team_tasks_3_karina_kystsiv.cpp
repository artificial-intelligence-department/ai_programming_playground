#include <iostream>
#include <stack>
using namespace std;

class ListNode {
public:
    int value;
    ListNode* next;

    ListNode(int val) : value(val), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    LinkedList add(LinkedList& other) {
        LinkedList result;
        ListNode* current1 = head;
        ListNode* current2 = other.head;
        int carry = 0;

        while (current1 || current2 || carry) {
            int sum = carry + (current1 ? current1->value : 0) + (current2 ? current2->value : 0);
            carry = sum / 10;
            result.insert(sum % 10);

            if (current1) current1 = current1->next;
            if (current2) current2 = current2->next;
        }

        return result;
    }

    void print() {
        stack<int> s;
        ListNode* current = head;

        while (current) {
            s.push(current->value);
            current = current->next;
        }

        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }

        cout << endl;
    }
};

int main() {
    LinkedList num1;
    LinkedList num2;

    num1.insert(4);
    num1.insert(5);
    num1.insert(1);

    num2.insert(1);
    num2.insert(6);
    num2.insert(8);

    LinkedList result = num1.add(num2);

    cout << "Number 1: ";
    num1.print();

    cout << "Number 2: ";
    num2.print();

    cout << "Sum: ";
    result.print();

    return 0;
}
