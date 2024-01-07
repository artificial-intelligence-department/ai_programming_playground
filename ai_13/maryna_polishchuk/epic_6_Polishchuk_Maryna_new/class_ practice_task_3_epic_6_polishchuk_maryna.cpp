#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

//для додавання вузолу з початок списку
void push(Node** head_ref, //передаємо адресу вказівника head, а не сам вказівник head
                          int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    //(*head_ref) = new_node; - ця операція має значення за адресою head_ref, тобто ми
    //змінюємо сам вказівник head на новий вузол, що створений у цій функції.
}

//виведення на екран
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

//функція для обміну двома вказівниками на вузли.
void swapPointer(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

int getSize(Node* node) {
    int size = 0;
    while (node != NULL) {
        node = node->next;
        size++;
    }
    return size;
}

//додає два списки того ж розміру разом
Node* addSameSize(Node* head1, Node* head2, int* carry) {
    if (head1 == NULL)
        return NULL;
    int sum;
    
    // Створюємо новий вузол для результату
    Node* result = new Node();

    result->next = addSameSize(head1->next, head2->next, carry);

    sum = head1->data + head2->data + *carry;
    *carry = sum / 10; //обчислює "перенос" для наступного розряду
    sum = sum % 10; //обмежує значення sum до одиниць

    result->data = sum; //присвоюємо вузлу result (який представляє результат додавання вузлів) значення sum

    return result;
}

//викликається після додавання меншого списку до підсписку більшого списку того ж розміру.
void addCarryToRemaining(Node* head1, Node* cur, int* carry, Node** result) {
    int sum;

    if (head1 != cur) { //cur - це вказівник на останній вузол у потрібній частині списку, яку ми додаємо до результату.
        addCarryToRemaining(head1->next, cur, carry, result);
        //просуваємося вперед у списку до останнього вузла, який потрібно додати до результату.

        sum = head1->data + *carry; //*carry. Ми додаємо значення поточного вузла до значення "переносу"
        *carry = sum / 10;
        sum %= 10;

        push(result, sum);
    }
}

//визначає, який список довший, а потім викликає addSameSize для додавання списків 
//того ж розміру та addCarryToRemaining для обробки залишкових елементів.
void addList(Node* head1, Node* head2, Node** result) {
    Node* cur;

    //Перевірка, чи один зі списків є порожнім:
    if (head1 == NULL) {
        *result = head2;
        return;
    } else if (head2 == NULL) {
        *result = head1;
        return;
    }

    //функція getSize підраховує кількість вузлів у списку.
    int size1 = getSize(head1);
    int size2 = getSize(head2);

    int carry = 0;

    if (size1 == size2)
        *result = addSameSize(head1, head2, &carry);
    else {
        //обчислення кількості вузлів, що залишилося в більшому списку після додавання рівних розміром частин.
        int diff = abs(size1 - size2);

        //Якщо один список коротший за інший, вони обмінюються.
        if (size1 < size2)
            swapPointer(&head1, &head2);

        for (cur = head1; diff--; cur = cur->next);

        *result = addSameSize(cur, head2, &carry);

        addCarryToRemaining(head1, cur, &carry, result);
    }

    //Якщо carry не дорівнює нулю, це означає, що в останньому додаванні відбувся перенос. Тут він додається до результату.
    if (carry)
        push(result, carry);
}

int main() {
    Node *head1 = NULL, *head2 = NULL, *result = NULL;

    int arr1[] = { 9, 9, 9 };
    int arr2[] = { 1, 8 };

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    for (int i = size1 - 1; i >= 0; --i)
        push(&head1, arr1[i]);

    for (int i = size2 - 1; i >= 0; --i)
        push(&head2, arr2[i]);

    addList(head1, head2, &result);

    printList(result);

    return 0;
}