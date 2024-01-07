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

void deleteList(DLinkedList **list) {
    Node *tmp=(*list)->head;
    if (tmp) { delete tmp; }
    (*list)->size=0;
    delete (*list);
    (*list) = nullptr;
}

DLinkedList* reverseList(DLinkedList **original) {
    DLinkedList *reversed=createList();
    if((*original)->size) {
        Node *tmp=(*original)->tail;
        addToList(&reversed, 1, tmp->value);
        for (unsigned long i=2;i<=(*original)->size;i++) {
            tmp=tmp->prev;
            addToList(&reversed, i, tmp->value);
        }
    }
    return reversed;
}

bool compareLists(DLinkedList **first_L, DLinkedList **second_L) {
    bool same=true;
    Node *first=(*first_L)->head, *second=(*second_L)->head;
    if ((*first_L)->size != (*second_L)->size) {same=false;}
    else {
        for (unsigned long i=0;i<(*first_L)->size;i++) {
            if (first->value != second->value) {same=false; break;}
            first=first->next, second=second->next;
        }
    }
    return same;
}

DLinkedList* addLists(DLinkedList **first_L, DLinkedList **second_L) {
    DLinkedList *result=createList();
    Node* first=(*first_L)->head;
    Node* second=(*second_L)->head;
    short carry=0;
    unsigned long index=1;
    while (first || second || carry) {
        int sum=(first!=nullptr?first->value:0)+(second!=nullptr?second->value:0)+carry;
        carry=sum/10;
        addToList(&result, index, sum%10);
        if(first!=nullptr)first=first->next;
        if(second!=nullptr)second=second->next;
        index++;
    }
    return result;
}

int main() {
    DLinkedList *list=createList();
    printList(&list);

    addToList(&list, 1, 2);
    addToList(&list, 2, 3);
    addToList(&list, 3, 4);
    addToList(&list, 4, 5);
    addToList(&list, 5, 6);
    addToList(&list, 6, 7);
    addToList(&list, 7, 8);
    printList(&list);

    DLinkedList *reversed=reverseList(&list);
    printList(&reversed);

    cout << (compareLists(&list, &reversed)?"true":"false") << endl;
    cout << (compareLists(&list, &list)?"true":"false") << endl;

    DLinkedList *sum=addLists(&reversed, &list);
    printList(&sum);
    deleteList(&list), deleteList(&reversed), deleteList(&sum);
    return 0;
}