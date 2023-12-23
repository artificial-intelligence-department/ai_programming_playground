#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Doubly linked list

typedef struct IntListNode {
    int value;
    struct IntListNode* next;
    struct IntListNode* prev;
} Node;

Node* create_node(int value) {
    Node* node = (Node*)calloc(sizeof(Node), 1);
    node->value = value;
    return node;
}

void printList(Node* head);

void insert(Node** head, int value, int index);
void push_front(Node** head, int value);
void push_back(Node** tail, int value);

void remove_elem(Node** head, int index);
void delete_list(Node** head);

Node* get_elem(Node* head, int index);
Node* get_tail(Node* head);

int get_length(Node* head);

// End doubly linked list

// Task 1
Node* reverseList(Node* head, Node* tail);
void Task1();

// Task 2
bool compare(Node *h1, Node *h2);
void Task2();

// Task 3
Node* add(Node* h1, Node* h2);
void Task3();

int main() {
    Task1();
    printf("\n");
    Task2();
    printf("\n");
    Task3();

    return 0;
}
void Task1() {
    printf("Task 1:\n");
    Node* head = (Node*)calloc(sizeof(Node), 1);
    Node* tail = head;

    for (int i = 1; i < 10; i++) {
        push_back(&tail, i);
    }
    printf("Original list: ");
    printList(head);

    head = reverseList(head, tail);
    printf("Reversed list: ");
    printList(head);
    delete_list(&head);
}

void Task2() {
    printf("Task 2:\n");

    Node* head1 = (Node*)calloc(sizeof(Node), 1);
    Node* tail1 = head1;
    for (int i = 1; i < 10; i++) {
        push_back(&tail1, i);
    }

    Node* head2 = (Node*)calloc(sizeof(Node), 1);
    Node* tail2 = head2;
    for (int i = 1; i < 10; i++) {
        push_back(&tail2, i);
    }

    printList(head1);
    printList(head2);
    printf("Are they equal: %s\n\n", compare(head1, head2) ? "true" : "false");

    head2 = reverseList(head2, tail2);
    printList(head1);
    printList(head2);
    printf("Are they equal: %s\n", compare(head1, head2) ? "true" : "false");

    delete_list(&head1);
    delete_list(&head2);
}

void Task3() {
    printf("Task 3:\n");

    Node* head1 = (Node*)calloc(sizeof(Node), 1);
    Node* tail1 = head1;
    head1->value = 9;
    for (int i = 8; i > 6; i--) {
        push_back(&tail1, i);
    }

    Node* head2 = (Node*)calloc(sizeof(Node), 1);
    Node* tail2 = head2;
    head2->value = 7;
    for (int i = 8; i > 3; i--) {
        push_back(&tail2, i);
    }

    printf("First number: ");
    printList(head1);
    printf("Second number: ");
    printList(head2);

    Node* result = add(head1, head2);
    printf("Result (a + b): ");
    printList(result);

    delete_list(&head1);
    delete_list(&head2);
    delete_list(&result);
}

Node* reverseList(Node* head, Node* tail) {
    Node* current = head;
    Node* temp = NULL;
    while (current != NULL) {
        // swap next and prev pointers
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        // move to next node
        current = temp;
    }

    // return new head
    return tail;
}

bool compare(Node *h1, Node *h2) {
    Node* current1 = h1;
    Node* current2 = h2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->value != current2->value) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    if (current1 != NULL || current2 != NULL) {
        return false;
    }
    return true;
}

Node* add(Node* h1, Node* h2) {
    Node* current1 = get_tail(h1);
    Node* current2 = get_tail(h2);
    Node* resultHead = (Node*)calloc(sizeof(Node), 1);

    int carry = 0;

    while (current1 != NULL && current2 != NULL) {
        int sum = current1->value + current2->value + carry;
        carry = sum / 10;
        sum = sum % 10;
        push_front(&resultHead, sum);
        current1 = current1->prev;
        current2 = current2->prev;
    }
    while (current1 != NULL) {
        int sum = current1->value + carry;
        carry = sum / 10;
        sum = sum % 10;
        push_front(&resultHead, sum);
        current1 = current1->prev;
    }
    while (current2 != NULL) {
        int sum = current2->value + carry;
        carry = sum / 10;
        sum = sum % 10;
        push_front(&resultHead, sum);
        current2 = current2->prev;
    }

    if (carry != 0) {
        push_front(&resultHead, carry);
    }

    remove_elem(&resultHead, get_length(resultHead) - 1);
    return resultHead;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

Node* get_tail(Node* head) {
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

void insert(Node** head, int value, int index) {
    Node* current = *head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (index == 0) {
        push_front(head, value);
        return;
    }

    int i = 0;
    while (i < index - 1) {
        current = current->next;
        i++;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
}

void push_front(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *head;
    newNode->prev = NULL;
    *head = newNode;
}

void push_back(Node** tail, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    (*tail)->next = newNode;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = *tail;
    *tail = newNode;
}

void remove_elem(Node** head, int index) {
    Node* current = *head;
    if (index == 0) {
        *head = current->next;
        free(current);
        return;
    }

    int i = 0;
    while (i < index - 1) {
        current = current->next;
        i++;
    }

    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

void delete_list(Node** head) {
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

Node* get_elem(Node* head, int index) {
    Node* current = head;
    int i = 0;
    while (i < index) {
        current = current->next;
        i++;
    }
    return current;
}

int get_length(Node* head) {
    Node* current = head;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}