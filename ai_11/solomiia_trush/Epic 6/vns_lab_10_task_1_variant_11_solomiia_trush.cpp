#include <iostream>
#include <fstream>
using namespace std;

struct Element_of_linked_list {
    char data;
    Element_of_linked_list* previous;
    Element_of_linked_list* next;
};

Element_of_linked_list* head;
Element_of_linked_list* tail;

void print (Element_of_linked_list* head) {
    Element_of_linked_list* element = head;
    if (element == NULL) {
        cout << "The list is empty" << endl;
    } else {    
        while (element != NULL) {
            cout << element->data << " ";
            element = element->next;
        }
    }
    cout << endl;
}

Element_of_linked_list* create (int n) {
    Element_of_linked_list* head = NULL;

    for (int i=0; i<n; i++) {  
        Element_of_linked_list* new_element = new Element_of_linked_list();
        
        if (i==0 && head!=NULL) {
            new_element->next = head;
            head->previous = new_element;
            head = new_element;
        } else if (i==0 && head==NULL) {
            head = new_element;
        } else {
            Element_of_linked_list* previous_element = head;
            for (int j=0; j<i-1; j++) {
                previous_element = previous_element->next;
            }
            new_element->previous = previous_element;
            new_element->next = previous_element->next;
            if (previous_element->next != NULL) {
                previous_element->next->previous = new_element;
            }
            previous_element->next = new_element;
        }
    }
    return head;
}

void insert () {
    cout << "Enter the position to add elements : ";
    int index;
    cin >> index;
    
    cout << "Enter how many elements you want to add : ";
    int n;
    cin >> n;
    
    cout << "Enter the elements : " ;
    for (int i=0; i<n; i++) {  
        Element_of_linked_list* new_element = new Element_of_linked_list();
        cin >> new_element->data;
        
        if (index==0 && head!=NULL) {
            new_element->next = head;
            head->previous = new_element;
            head = new_element;
        } 
        if (index==0 && head==NULL) {
            head = new_element;
            tail = new_element;
        }
        if (index!=0) {
            Element_of_linked_list* previous_element = head;
            for (int j=0; j<index-1; j++) {
                previous_element = previous_element->next;
            }
            new_element->previous = previous_element;
            new_element->next = previous_element->next;
            if (previous_element->next != NULL) {
                previous_element->next->previous = new_element;
            }
            previous_element->next = new_element;
        }
        index++;
    }

    Element_of_linked_list* element = head;
    while (element->next!=NULL) {
        element = element->next;
    }
    tail = element;

}

void delete_element_with_set_value () {
    cout << "Enter the element to delete : ";
    char input;
    cin >> input;

    Element_of_linked_list* needed_element = head;
    while (needed_element != NULL && input != needed_element->data) {
        needed_element = needed_element->next;
    }

    if (needed_element != NULL) {
        Element_of_linked_list* previous = needed_element->previous;
        if (needed_element->previous != NULL) {
            needed_element->previous->next = needed_element->next;
            if (needed_element->next != NULL) {
                needed_element->next->previous = needed_element->previous;
            }
        } else {
            head = needed_element->next;
            if (needed_element->next != NULL) {
                needed_element->next->previous = NULL;
            }
        }
        delete needed_element;
    }
}

void write_in_file (Element_of_linked_list* head) {
    Element_of_linked_list* element = head;
    ofstream file_with_list("doubly_linked_list_file.txt", ios::out | ios::trunc);
    if (file_with_list.is_open()) {
        while (element != NULL) {
            file_with_list << element->data;
            element = element->next;
        }
        file_with_list.close();
    }
}

void delete_list(Element_of_linked_list*& head) {
    while (head != nullptr) {
        Element_of_linked_list* temp = head;
        head = head->next;
        delete temp;
    }
}

void restore(Element_of_linked_list*& head) {
    ifstream file_with_list("doubly_linked_list_file.txt");
    if (file_with_list.is_open()) {
        string line;
        getline(file_with_list, line);
        for (char c : line) {
            Element_of_linked_list* new_element = new Element_of_linked_list();
            new_element->data = c;

            if (head == nullptr) {
                head = tail = new_element;
            } else {
                tail->next = new_element;
                new_element->previous = tail;
                tail = new_element;
            }
        }
        file_with_list.close();
    }
}

int main () {
    int n = 10;
    head = create(n);
    cout << "The list have been created" << endl;
    print(head);

    insert();
    print(head);

    delete_element_with_set_value();
    print(head);

    write_in_file(head);
    cout << "The list have been written in file" << endl;
    
    delete_list(head);
    cout << "The list have been destroyed" << endl;
    print(head);

    restore(head);
    cout << "The list have been restored" << endl;
    print(head);
    
    delete_list(head);

}