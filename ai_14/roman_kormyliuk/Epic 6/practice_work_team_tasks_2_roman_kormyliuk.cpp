#include <iostream>
using namespace std;
// Структура вузла списку
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Функція порівняння списків
bool compare(Node* h1, Node* h2) {
    // Ітеративний обхід списків
    while (h1 != nullptr && h2 != nullptr) {
        // Порівнюємо дані в кожному вузлі
        if (h1->data != h2->data) {
            return false; // Якщо дані не рівні, повертаємо false
        }

        // Переходимо до наступного вузла
        h1 = h1->next;
        h2 = h2->next;
    }

    // Якщо довжина списків різна, повертаємо false
    return (h1 == nullptr && h2 == nullptr);
}

int main() {
    // Створення списків
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    // Порівняння списків
    if (compare(head1, head2)) {
        cout << "Списки рівні\n";
    } else {
        cout << "Списки не рівні\n";
    }

    // Звільнення пам'яті
    delete head1;
    delete head2;

    return 0;
}
