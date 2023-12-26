#include <iostream>
using namespace std;

class Doubly_Linked_List {
private:
    struct Element_of_linked_list {
        int data;
        Element_of_linked_list* previous;
        Element_of_linked_list* next;
    };

    Element_of_linked_list* head;
    Element_of_linked_list* tail;

public:
    Doubly_Linked_List() {
        head = nullptr;
        tail = nullptr;
    }

    void print() const {
        Element_of_linked_list* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void insert() {
        int index, n;
        cin >> index >> n;

        Element_of_linked_list* current = head;
        for (int i = 0; i < index; i++) {
            if (current == nullptr) {
                return; 
            }
            current = current->next;
        }

        for (int i = 0; i < n; i++) {
            Element_of_linked_list* new_element = new Element_of_linked_list();
            cin >> new_element->data;

            if (current == nullptr) {
                new_element->previous = tail;
                if (tail != nullptr) {
                    tail->next = new_element;
                }
                tail = new_element;
                if (head == nullptr) {
                    head = new_element;
                }
            } else {
                new_element->next = current;
                new_element->previous = current->previous;
                if (current->previous != nullptr) {
                    current->previous->next = new_element;
                } else {
                    head = new_element;
                }
                current->previous = new_element;
            }
        }
    }

    void size() const {
        Element_of_linked_list* current = head;
        int sizeee = 0;
        while (current != nullptr) {
            current = current->next;
            sizeee++;
        }
        cout << sizeee << endl;
    }

    void get() const {
        int index;
        cin >> index;

        Element_of_linked_list* current = head;
        for (int i = 0; i < index; i++) {
            if (current == nullptr) {
                return; 
            }
            current = current->next;
        }

        if (current != nullptr) {
            cout << current->data << endl;
        }
    }

    void set() {
        int index, new_value;
        cin >> index >> new_value;

        Element_of_linked_list* current = head;
        for (int i = 0; i < index; i++) {
            if (current == nullptr) {
                return;  
            }
            current = current->next;
        }

        if (current != nullptr) {
            current->data = new_value;
        }
    }

    void erase() {
        int index, quantity;
        cin >> index >> quantity;

        Element_of_linked_list* current = head;
        for (int i = 0; i < index; i++) {
            if (current == nullptr) {
                return;  
            }
            current = current->next;
        }

        for (int i = 0; i < quantity && current != nullptr; i++) {
            Element_of_linked_list* next_element = current->next;
            if (current->previous != nullptr) {
                current->previous->next = next_element;
            } else {
                head = next_element;
                if (head != nullptr) {
                    head->previous = nullptr;
                }
            }
            if (next_element != nullptr) {
                next_element->previous = current->previous;
            }
            delete current;
            current = next_element;
        }

        if (current == nullptr) {
            tail = head;
            while (tail != nullptr && tail->next != nullptr) {
                tail = tail->next;
            }
        }
    }

    void request(int n) {
        for (int i = 0; i < n; i++) {
            string request;
            cin >> request;
            if (request == "print") {
                print();
            } else if (request == "insert") {
                insert();
            } else if (request == "size") {
                size();
            } else if (request == "get") {
                get();
            } else if (request == "set") {
                set();
            } else if (request == "erase") {
                erase();
            }
        }
    }
};

int main() {
    Doubly_Linked_List List;
    int Q;
    cin >> Q;
    List.request(Q);

    return 0;
}
