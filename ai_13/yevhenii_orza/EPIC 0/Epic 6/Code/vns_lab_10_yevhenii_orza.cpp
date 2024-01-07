#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>

using namespace std;

struct Node {
    string key;
    shared_ptr<Node> next;
    weak_ptr<Node> prev;

    Node(const string& value) : key(value), next(nullptr) {}
};

shared_ptr<Node> createList() {
    cout << "Enter the number of elements in the list: ";
    int n;
    cin >> n;

    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> tail = nullptr;

    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << (i + 1) << ": ";
        string value;
        cin >> value;

        auto newNode = make_shared<Node>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
        }
        tail = newNode;
    }

    return head;
}

shared_ptr<Node> addAfter(shared_ptr<Node> head, const string& targetKey, const string& newKey) {
    auto temp = head;
    while (temp != nullptr && temp->key != targetKey) {
        temp = temp->next;
    }

    if (temp != nullptr) {
        auto newNode = make_shared<Node>(newKey);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    return head;
}

shared_ptr<Node> removeDuplicates(shared_ptr<Node> head) {
    unordered_set<string> seen;
    auto current = head;
    shared_ptr<Node> prev = nullptr;

    while (current != nullptr) {
        if (seen.find(current->key) != seen.end()) {
            auto next = current->next;
            if (current->next != nullptr) {
                current->next->prev = prev;
            }
            if (prev != nullptr) {
                prev->next = next;
            } else {
                head = next;
            }
            current = next;
        } else {
            seen.insert(current->key);
            prev = current;
            current = current->next;
        }
    }

    return head;
}

void printList(shared_ptr<Node> head) {
    auto temp = head;
    while (temp != nullptr) {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a doubly linked list
    cout << "Creating the list:\n";
    auto head = createList();

    cout << "Original list: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    string targetKey, newKey;
    cout << "Enter the target key: ";
    cin >> targetKey;
    cout << "Enter the new key to add after the target key: ";
    cin >> newKey;
    head = addAfter(head, targetKey, newKey);

    cout << "List after adding '" << newKey << "' after '" << targetKey << "': ";
    printList(head);

    return 0;
}
