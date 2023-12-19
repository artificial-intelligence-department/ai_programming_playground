#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct Node {
    int value;
    Node* next = NULL;
    Node(int value) {
        this->value = value;
    }
};

Node* push_back(Node* first, int arg) {
    Node* node = new Node(arg);
    if (first == NULL) {
        return node;
    }
    else {
        Node* elem = first;
        // go to end of list
        while (elem->next != NULL) {
            elem = elem->next;
        }
        elem->next = node;
    }
    return first;
}

Node* reverse(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    else {
        Node* elem = head;
        Node* nextElem = elem->next;
        head->next = NULL;
        while(nextElem != NULL) {
            Node* p = nextElem->next;
            nextElem->next = elem;
            elem = nextElem;
            nextElem = p;
        }
        return elem;
    }
}

bool compare(Node* h1, Node* h2) {
    if (h1 == h2) {
        return true;
    }
    while (h1 != NULL && h2 != NULL && h1->value == h2->value) {
        h1 = h1->next;
        h2 = h2->next;
        if (h1 == h2) {
            return true;
        }
    }
    return false;
}

ostream& operator<<(ostream& out, const Node* list) {
    if (list != NULL) {
        out << (list->value) << " " << list->next;
    }
    return out;
}

Node* saveStrNumberInList(char* str) {
    Node* head = NULL;
    Node* elem = NULL;
    auto size = strlen(str);
    for (int i = 0; i < size; i++) {
        char ch = str[size - i - 1];
        int n = atoi(&ch);
        Node* node = new Node(n);
        if (head == NULL) {
            head = node;
            elem = node;
        }
        else {
            elem->next = node;
            elem = node;
        }
    }
    return head;
}

int listLength(const Node* head) {
    int result = 0;
    const Node* elem = head;
    while (elem != NULL) {
        result++;
        elem = elem->next;
    }
    return result;
}

ostream& operator<<(ostream& out, const Node head) {
    int length = listLength(&head);
    string result;
    for (int i = 0; i < length; i++) {
        result += " ";
    }
    int i = 0;
    const Node* elem = &head;
    while (elem != NULL) {
        string str = to_string(elem->value);
        result[length - 1 - i] = str[0];
        elem = elem->next;
        i++;
    }
    out << result;
    return out;
}

Node* add(Node* n1, Node* n2) {
    Node* resultHead = NULL;
    Node* elem = NULL;
    
    int shift = 0;
    while (n1 != NULL || n2 != NULL) {
        int v1 = 0;
        int v2 = 0;
        
        if (n1 != NULL) {
            v1 = n1->value;
            n1 = n1->next;
        }
        if (n2 != NULL) {
            v2 = n2->value;
            n2 = n2->next;
        }
        
        int r = v1 + v2 + shift;
        
        int rv = r % 10;
        shift = r / 10;
        
        Node* newNode = new Node(rv);
        if (resultHead == NULL) {
            resultHead = newNode;
            elem = newNode;
        }
        else {
            elem->next = newNode;
            elem = newNode;
        }
    }
    if (shift != 0) {
        Node* newNode = new Node(shift);
        elem->next = newNode;
    }
    
    return resultHead;
}

int main() {
    
    Node* list1 = push_back(NULL, 5);
    push_back(list1, 6);
    push_back(list1, 7);
    cout << "list1: " << list1 << "\n";
    
    Node* listReversed = reverse(list1);
    cout << "listReversed: " << listReversed << "\n";
    
    Node* list2 = push_back(NULL, 7);
    push_back(list2, 6);
    push_back(list2, 5);
    cout << "list2: " << list2 << "\n";
    cout << (compare(listReversed, list2) ? "listReversed == list2" : "listReversed != list2") << "\n";
    
    Node* list3 = push_back(NULL, 7);
    push_back(list3, 6);
    cout << "list3: " << list3 << "\n";
    cout << (compare(listReversed, list3) ? "listReversed == list3" : "listReversed != list3") << "\n";
    Node* list4 = push_back(NULL, 7);
    push_back(list4, 6);
    push_back(list4, 7);
    cout << "list4: " << list4 << "\n";
    cout << (compare(listReversed, list4) ? "listReversed == list4" : "listReversed != list4") << "\n";
    
    Node* number1 = saveStrNumberInList("485934593485934593945349932884858585");
    cout << *number1 << "\n";
    Node* number2 = saveStrNumberInList("123");
    cout << *number2 << "\n";

    Node* result = add(number1, number2);
    cout << *result << "\n";
    
    return 0;
}