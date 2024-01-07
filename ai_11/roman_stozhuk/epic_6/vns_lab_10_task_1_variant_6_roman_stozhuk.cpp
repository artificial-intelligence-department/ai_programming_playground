#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int value=0;
    struct Node *next=nullptr;
    struct Node *prev=nullptr;
};

struct DLinkedList {
    unsigned long size=0;
    Node *head=nullptr;
    Node *tail=nullptr;
};

DLinkedList* createList() {
    DLinkedList *tmp = new DLinkedList;
    tmp->size=0;
    tmp->head=nullptr, tmp->tail=nullptr;
    return tmp;
}

void printList(DLinkedList **list) {
    if(!(*list) || !(*list)->size) {cout << "List is empty";}
    else {
        Node *tmp=(*list)->head;
        while (tmp) {
            cout << tmp->value << ' ';
            tmp=tmp->next;
        }
    }
    cout << '\n';
}

void addToList(DLinkedList **list, double number, int value) {
    Node *toAdd=new Node;
    toAdd->value=value;
    toAdd->next=nullptr;
    toAdd->prev=nullptr;
    if (!((*list)->size)) {
        (*list)->head=toAdd;
        (*list)->tail=toAdd;
    }
    else if (number == 1) {
        Node *next=(*list)->head;
        toAdd->next=next;
        next->prev=toAdd;
        (*list)->head=toAdd;
    }
    else if (number-1 == (*list)->size) {
        Node *prev=(*list)->tail;
        toAdd->prev=prev;
        prev->next=toAdd;
        (*list)->tail=toAdd;
    }
    else if ((*list)->size) {
        Node *prev=(*list)->head;
        Node *next=(*list)->tail;
        for (unsigned long i=1;i<number-1;i++) {
            prev=prev->next;
        }
        next=prev->next;
        toAdd->prev=prev;
        toAdd->next=next;
        prev->next=toAdd;
        next->prev=toAdd;
    }
    (*list)->size++;
}

int deleteFromList(DLinkedList **list, double number) {
    int delVal;
    Node *toDelete=(*list)->head;
    if ((*list)->size==1) {
        delVal=toDelete->value;
        delete (*list)->head;
        (*list)->head=nullptr;
        (*list)->tail=nullptr;
    }
    else if (number == 1) {
        delVal=toDelete->value;
        Node *next=(*list)->head->next;
        delete toDelete;
        (*list)->head=next;
    }
    else if (number == (*list)->size) {
        toDelete=(*list)->tail;
        delVal=toDelete->value;
        Node *prev=(*list)->tail->prev;
        delete toDelete;
        (*list)->tail=prev;
    }
    else if ((*list)->size) {
        for (unsigned long i=0;i<number-1;i++) {
            toDelete=toDelete->next;
        }
        delVal=toDelete->value;
        Node *prev=toDelete->prev;
        Node *next=toDelete->next;
        delete toDelete;
        prev->next=next;
        next->prev=prev;
    }
    (*list)->size--;
    return delVal;
}

void writeListToFile(DLinkedList **list,char *file) {
    ofstream out(file, ios::binary);
    Node *current=(*list)->head;
    for (unsigned long i=0; i<(*list)->size; i++) {
        out << current->value << ' ';
        current=current->next;
    }
    out << '\n';
    out.close();
}

void deleteList(DLinkedList **list) {
    Node *tmp=(*list)->head;
    if (tmp) { delete tmp; }
    (*list)->size=0;
    delete (*list);
    (*list) = nullptr;
}

DLinkedList* restoreListFromFile(char *file) {
    ifstream in(file, ios::binary);
    DLinkedList *restored=createList();
    Node *add=nullptr, *add_next=nullptr;
    int tmp=0;
    in >> tmp;
    if(tmp) {
        add_next = new Node;
        add_next->next=nullptr;
        add_next->prev=nullptr;
        add_next->value=tmp;
        restored->head=add_next;
        restored->head=add_next;
        restored->size++;
    }
    while(1) {
        in >> tmp;
        if(in.eof()) {break;}
        add=add_next;
        add_next=new Node;
        add->next=add_next;
        add_next->prev=add;
        add_next->value=tmp;
        add_next->next=nullptr;
        restored->size++;
    }
    restored->tail=add_next;
    in.close();
    return restored;
}

int main() {
    DLinkedList *list=createList();
    printList(&list);

    addToList(&list, 1, 10);
    addToList(&list, 2, 12);
    addToList(&list, 3, 31);
    addToList(&list, 4, 9);
    addToList(&list, 5, 200);
    addToList(&list, 6, -3);
    addToList(&list, 7, 55);
    printList(&list);

    addToList(&list, 1, deleteFromList(&list, 5));
    printList(&list);

    addToList(&list, 1, deleteFromList(&list, 5));
    printList(&list);

    char file[]="abc.txt";
    writeListToFile(&list, file);
    deleteList(&list);
    printList(&list);

    list = restoreListFromFile(file);
    printList(&list);

    deleteList(&list);
    return 0;
}