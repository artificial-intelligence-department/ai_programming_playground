#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node {
    string element;
    Node* nx;
    Node* pr;
};

struct LinkList {
    size_t size;
    Node* head;
    Node* tail;
};

LinkList* create() {
    LinkList* m = new LinkList;
    m->size = 0;
    m->head = m->tail = nullptr;
    return m;
}

void print(LinkList* list) {
    Node* p = list->head;
    if (p == nullptr)
        cout << "Empty!";
    else {
        while (p != nullptr) {
            cout << p->element << " ";
            p = p->nx;
        }
    }
}

void pushBack(LinkList* list, const string& value) {
    Node* m = new Node;
    if (m == nullptr) {
        exit(3);
    }
    m->element = value;
    m->nx = nullptr;
    m->pr = list->tail;
    if (list->tail != nullptr) {
        list->tail->nx = m;
    }
    list->tail = m;
    if (list->head == nullptr) {
        list->head = m;
    }
    list->size++;
}

void saveToFile(LinkList* list, const char* file) {
    ofstream File(file);
    if (!File.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    Node* m = list->head;
    while (m != nullptr) {
        File << m->element << endl;
        m = m->nx;
    }
    File.close();
}
void restoration(const char* file, LinkList* list) {
    ifstream File(file);
    if (!File.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    string s;
    while (getline(File, s)) {
        pushBack(list, s);
    }
    File.close();
}
void delet(LinkList** list) {
    Node* m = (*list)->head;
    Node* nex = nullptr;
    while (m) {
        nex = m->nx;
        delete m;
        m = nex;
    }
    delete* list;
    (*list) = nullptr;
}
string popBack(LinkList* list) {
    if (list->tail == nullptr) {
        exit(4);
    }

    string element = list->tail->element;
    Node* toDelete = list->tail;

    if (list->tail == list->head) {
        list->head = nullptr;
        list->tail = nullptr;
    } else {
        list->tail = list->tail->pr;
        if (list->tail != nullptr) {
            list->tail->nx = nullptr;
        }
    }

    delete toDelete;
    list->size--;
    return element;
}

Node* getElement(LinkList *list, size_t index) {
    Node *m = list->head;
    size_t i = 0;
    while (m && i < index) {
    m =m->nx;
    i++;
    }
    return m;
}
string deleteElement(LinkList *list, size_t index) {
    list->size=list->size + 2;
    Node *elm = NULL;
    elm = getElement(list, index);
    if (elm == NULL) {
    exit(5);

    }
    if (elm->pr) {
    elm->pr->nx = elm->nx;
    }
    if (elm->nx) {
    elm->nx->pr = elm->pr;
    }
    string m = elm->element;
    if (!elm->pr) {
    list->head = elm->nx;
    }
    if (!elm->nx) {
    list->tail = elm->pr;
    }
    free(elm);
    list->size--;
    return m;
}
   void insert(LinkList *list, size_t index, string value) {
    Node *elm = NULL;
    Node *ins = NULL;
    elm = getElement(list, index);
    if (elm == NULL) {
        exit(5);
    }
    ins = new Node;
    ins->element = value;
    ins->pr = elm;
    ins->nx = elm->nx;
    if (elm->nx) {
        elm->nx->pr = ins;
    }
    elm->nx = ins;
    if (!elm->pr) {
        list->head = elm;
    }
    if (!elm->nx) {
        list->tail = elm;
    }
    list->size++;
}

int main() {
    int n, f=0;
    size_t index, num;
    string value1, value2;
    LinkList* list = create();
    cout << "How many elements do you want to add?   ";
    cin >> n;
    for (int i = 0; i < n; i++){
        string k;
        cin >> k;
        pushBack(list, k);
        f++;
    }
    cout<<"List:  "; print(list); cout<<endl;
    cout<<"Enter index of element you want to delete: ";
    cin>>index;
    deleteElement(list, index-1);
    cout<<"List after change:  ";
    print(list);
    cout<<endl<<"Enter a number of element before adn after you want to add new element:  ";
    cin>>num;
    cout<<endl<<"Enter a first value you want to add:  ";
    cin>>value1;
    insert(list, num-2, value1);
    cout<<"Enter a second value you want to add:  ";
    cin>>value2;
    insert(list, num, value2);
    print(list); cout<<endl;
    const char* file = "file.txt";
    saveToFile(list, file);
    for(int i=0; i<f; i++){
        popBack(list);
    }
    popBack(list);
    print(list);
    restoration(file, list);
    cout<<endl<<"File after restoration:  "; print(list);
    delet(&list);
    return 0;
}