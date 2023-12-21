#include <iostream>

using namespace std;

class ListNode {
public:
    int value;
    ListNode* next;

    ListNode(int value) : value(value), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        ListNode* newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }

    bool isEqualTo(LinkedList& other) {
        ListNode* current1 = head;
        ListNode* current2 = other.head;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->value != current2->value) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }

        return current1 == nullptr && current2 == nullptr;
    }
};

int main() {
    LinkedList list1;
    LinkedList list2;

    list1.insert(4);
    list1.insert(4);
    list1.insert(8);
    list1.insert(10);

    list2.insert(4);
    list2.insert(4);
    list2.insert(8);
    list2.insert(10);

    bool result = list1.isEqualTo(list2);

    if (result) {
        cout << "Lists are equal" << endl;
    } else {
        cout << "Lists are not equal" << endl;
    }

    return 0;
}
