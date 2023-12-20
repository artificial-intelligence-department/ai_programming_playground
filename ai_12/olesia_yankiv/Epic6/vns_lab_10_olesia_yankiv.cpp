#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DblLinkedList {
    size_t size;
    Node *head;
    Node *tail;
} DblLinkedList;

DblLinkedList *createDblLinkedList() {
    DblLinkedList *tmp = (DblLinkedList *)malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

void deleteDblLinkedList(DblLinkedList **list) {
    Node *tmp = (*list)->head;
    Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp->data);
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}

void pushFront(DblLinkedList *list, const char *data) {
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = strdup(data);
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;
    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}

void popFront(DblLinkedList *list) {
    Node *prev;
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    free(prev->data);
    free(prev);
    list->size--;
}

Node *getNth(DblLinkedList *list, size_t index) {
    Node *tmp = list->head;
    size_t i = 0;
    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }
    return tmp;
}

void deleteNth(DblLinkedList *list, size_t index) {
    Node *elm = getNth(list, index);
    if (elm == NULL) {
        printf("Index out of bounds.\n");
        return;
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    free(elm->data);
    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }
    free(elm);
    list->size--;
}

void printList(DblLinkedList *list) {
    Node *p = list->head;
    if (p == NULL) {
        printf("List is empty.\n");
        return;
    }
    do {
        printf("%s ", p->data);
        p = p->next;
    } while (p != NULL);
    printf("\n");
}

void writeFile(DblLinkedList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    Node *current = list->head;
    while (current != NULL) {
        fprintf(file, "%s\n", current->data);
        current = current->next;
    }

    fclose(file);
}

void restoreFromFile(DblLinkedList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        pushFront(list, line);
    }

    fclose(file);
}

int main() {
    DblLinkedList *list = createDblLinkedList();
    int choice;

    do {
        printf("\n Menu\n");
        printf("1. Add element to the front\n");
        printf("2. Delete element from the front\n");
        printf("3. Print the list\n");
        printf("4. Write the list to a file\n");
        printf("5. Delete the list\n");
        printf("6. Restore list from file\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char data[100];
                printf("Enter the element to add: ");
                scanf("%s", data);
                pushFront(list, data);
                break;
            }
            case 2:
                popFront(list);
                break;
            case 3:
                printList(list);
                break;
            case 4: {
                char filename[100];
                printf("Enter the filename: ");
                scanf("%s", filename);
                writeFile(list, filename);
                break;
            }
            case 5:
                deleteDblLinkedList(&list);
                break;
            case 6: {
                char filename[100];
                printf("Enter the filename: ");
                scanf("%s", filename);
                list = createDblLinkedList();
                restoreFromFile(list, filename);
                break;
            }
            case 7:
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}
