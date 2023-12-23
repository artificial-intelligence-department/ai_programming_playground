#include <iostream>
using namespace std;

// Структура вузла списку
struct Node {
    int numbers;    // Це поле numbers представляє число, яке зберігається у вузлі списку.
    Node* next;     // Вказівник next вказує на наступний елемент списку.
    
    Node(int val) : numbers(val), next(nullptr) {}  // Конструктор створює новий вузол з заданим числовим значенням val та встановлює вказівник next на nullptr.
};

// Функція для реверсу списку
Node* reverse(Node* head) {
    Node *prev = nullptr, *current = head, *next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// Допоміжна функція для виведення списку
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->numbers << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Створення зразка списку: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    cout << "Output list: ";
    printList(head);
    
    // Реверсія списку
    head = reverse(head);
    
    cout << "everted list: ";
    printList(head); 
    
    return 0;
}
