#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Метод для реверсу списку
Node* reverse(Node* head) {
    Node *prev = nullptr, *current = head, *nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

// Допоміжна функція для виведення списку
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. Number of nodes should be greater than 0." << endl;
        return 1; // Вихід з програми з помилкою
    }

    Node* head = nullptr;
    Node* current = nullptr;

    // Зчитуємо значення для кожного вузла
    for (int i = 0; i < n; ++i) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        if (i == 0) {
            head = new Node(value);
            current = head;
        } else {
            current->next = new Node(value);
            current = current->next;
        }
    }

    // Виведення вихідного списку
    cout << "Original List: ";
    printList(head);

    // Реверс списку
    head = reverse(head);

    // Виведення оберненого списку
    cout << "Reversed List: ";
    printList(head);

    return 0;
}       
