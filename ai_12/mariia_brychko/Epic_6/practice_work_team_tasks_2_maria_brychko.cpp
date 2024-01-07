#include <iostream>
using namespace std;

struct Node {
    int numbers;
    Node* next;
    
    Node(int val) : numbers(val), next(nullptr) {}
};

// Функція для виведення списку
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->numbers << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Функція порівняння списків
bool compare(Node *h1, Node *h2) {  //списки передаються як вхідні аргументи h1 та h2, які є вказівниками на перший елемент кожного списку.
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->numbers != h2->numbers) {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return (h1 == nullptr && h2 == nullptr);
}

// Функція для створення списку з введених користувачем даних
Node* createList() {
    Node* head = nullptr;
    Node* temp = nullptr;
    int input;
    
    while (true) {
        cin >> input;
        if (input == -1) {
            break;
        }
        Node* newNode = new Node(input);  // Створює новий вузол типу Node з введеним користувачем значенням input.
        if (head == nullptr) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;          //Вказівник temp->next встановлюється на новий вузол
            temp = temp->next;             //temp переміщується на наступний вузол у списку.
        }
    }
    return head;    //повертається початок списку (head), який тепер містить усі введені користувачем елементи у вигляді зв'язаного списку
}

int main() {
    cout << "Enter elements for the first list (enter -1 to stop):" << endl;
    Node* head1 = createList();  //оголошення змінної head1, яка є вказівником на перший елемент списку типу Node. 
                                 //Вказівник head1 призначений для зберігання адреси першого елемента створеного списку.
 
    cout << "Enter elements for the second list (enter -1 to stop):" << endl;
    Node* head2 = createList();

    cout << "First list: ";
    printList(head1);   //head1 - Це вказівник на перший елемент списку

    cout << "Second list: ";
    printList(head2);

    cout << "Comparison result: " << compare(head1, head2) << endl;

    return 0;
}
