#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Doubly linked list

typedef struct StrListNode {
    char* value;
    struct StrListNode* next;
    struct StrListNode* prev;
} Node;

Node* create_node(char* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = node->prev = NULL;
    return node;
}

void printList(Node* head);

void insert(Node** head, char* value, int index);
void push_front(Node** head, char* value);
void push_back(Node** tail, char* value);

void remove_elem(Node** head, int index);
void delete_list(Node** head);

Node* get_elem(Node* head, int index);
Node* get_tail(Node* head);

int index_of(Node* head, char* value);

int get_length(Node* head);

// End doubly linked list

void insert_k(Node** head, char* value, char* key, int count);

Node* read_from_file(FILE* f);
void write_to_file(FILE* f, Node* head);
Node* seed();

int main() {
    FILE *file = fopen("input.txt", "r");
    Node *head = NULL;

    // seed the file with some data
    if (file == NULL) head = seed();
    else {
        head = read_from_file(file);
        fclose(file);
        if (head == NULL) head = seed();
    }

    printList(head);

    // Task 1
    printf("Enter the index of the element to remove: ");
    int index;
    scanf_s("%d", &index);
    getc(stdin); // clear stdin (remove \n from buffer)
    remove_elem(&head, index);

    // Task 2
    char *key = (char *) calloc(sizeof(char), 256);
    printf("Enter the key of element: ");
    fgets(key, 256, stdin);

    int count;
    printf("Enter the count of elements to insert: ");
    scanf_s("%d", &count);
    getc(stdin); // clear stdin (remove \n from buffer)

    char *value = (char *) calloc(sizeof(char), 256);
    printf("Enter the value of the element to insert: ");
    fgets(value, 256, stdin);

    insert_k(&head, value, key, count);

    printList(head);

    file = fopen("input.txt", "w+");
    write_to_file(file, head);
    fclose(file);

    delete_list(&head);
    return 0;
}

Node* read_from_file(FILE* f) {
    char* line;
    int len = 256;

    Node* head = NULL, *tail = NULL;

    while (!feof(f)) {
        line = (char*)calloc(sizeof(char), len);
        fgets(line, len, f);

        if (line == NULL) break;

        if (head == NULL) head = tail = create_node(line);
        else push_back(&tail, line);
    }

    return head;
}
void write_to_file(FILE* f, Node* head) {
    Node* current = head;
    while (current != NULL) {
        fprintf(f, "%s", current->value);
        if (current->value[strlen(current->value) - 1] != '\n')
            fprintf(f, "\n");
        current = current->next;
    }
}
Node* seed() {
    FILE* f = fopen("input.txt", "w+");
    Node *head = create_node("Line 0");
    Node *tail = head;

    for (int i = 1; i <= 10; ++i) {
        char *str = (char *) malloc(sizeof(char) * 10);
        strcpy_s(str, 10, "Line ");
        char num[5];
        itoa(i, num, 10);
        strcat(str, num);
        push_back(&tail, str);
    }

    write_to_file(f, head);
    fclose(f);
    return head;
}

void insert_k(Node** head, char* value, char* key, int count) {
    Node* current = *head;
    int ind = index_of(current, key);

    if (ind == -1) {
        perror("Key not found\n");
        return;
    }

    for (int i = 0; i < count; ++i)
        insert(head, value, ind + 1);
    for (int i = 0; i < count; ++i)
        insert(head, value, ind);
}

void printList(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }
    while (current != NULL) {
        printf("%s", current->value);
        current = current->next;
    }
}

int index_of(Node* head, char* value) {
    Node* current = head;
    int i = 0;
    while (current != NULL) {
        if (strcmp(current->value, value) == 0) return i;
        current = current->next;
        i++;
    }
    return -1;
}

Node* get_tail(Node* head) {
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

void insert(Node** head, char* value, int index) {
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

void push_front(Node** head, char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *head;
    newNode->prev = NULL;
    *head = newNode;
}

void push_back(Node** tail, char* value) {
    Node* newNode = create_node(value);
    (*tail)->next = newNode;
    newNode->value = value;
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