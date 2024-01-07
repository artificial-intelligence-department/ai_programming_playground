#include <iostream>
#include <ctime>
using namespace std;

struct Element_of_linked_list {
    int data;
    Element_of_linked_list* previous;
    Element_of_linked_list* next;
};

Element_of_linked_list* create (int n) {
    srand(time(NULL));
    Element_of_linked_list* head = NULL;
    int index = 0;    

    for (int i=0; i<n; i++) {  
        Element_of_linked_list* new_element = new Element_of_linked_list();
        int number = rand()%21;
        new_element->data = number;
        
        if (index==0 && head!=NULL) {
            new_element->next = head;
            head->previous = new_element;
            head = new_element;
        } else if (index==0 && head==NULL) {
            head = new_element;
        } else {
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

    return head;
}

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

void reverse_list (Element_of_linked_list*& head)  { 
    Element_of_linked_list* temp = NULL; 
    Element_of_linked_list* current = head;
    
    while (current != NULL) {   
        temp = current->previous; 
        current->previous = current->next; 
        current->next = temp;             
        current = current->previous; 
    }
    if(temp != NULL ) {
        head = temp->previous;
    }  
}

bool compare (Element_of_linked_list* head1, Element_of_linked_list* head2) { 
    Element_of_linked_list* element1 = head1;
    Element_of_linked_list* element2 = head2;

    while (element1 != nullptr && element2 != nullptr) {
        if (element1->data != element2->data) {
            cout << "Lists are different." << endl;
            return false;
        }
        element1 = element1->next;
        element2 = element2->next;
    }
    cout << "Lists are the same." << endl;
    return element1 == nullptr && element2 == nullptr;
}

void delete_list(Element_of_linked_list*& head) {
    while (head != nullptr) {
        Element_of_linked_list* temp = head;
        head = head->next;
        delete temp;
    }
}

Element_of_linked_list* add(Element_of_linked_list* number1, Element_of_linked_list* number2) {
    Element_of_linked_list* result = nullptr;
    Element_of_linked_list* current = nullptr;
    int carry = 0;

    while (number1 || number2 || carry) {
        int data1 = (number1 ? number1->data : 0);
        int data2 = (number2 ? number2->data : 0);
        int sum = data1 + data2 + carry;

        carry = sum / 10;

        Element_of_linked_list* new_element = new Element_of_linked_list();
        new_element->data = sum % 10;

        if (!result) {
            result = current = new_element;
            current->previous = nullptr;  // Set previous to nullptr for the first element
        } else {
            current->next = new_element;
            new_element->previous = current;
            current = new_element;
        }

        if (number1) number1 = (number1->next ? number1->next : nullptr);
        if (number2) number2 = (number2->next ? number2->next : nullptr);
    }

    return result;
}



int main () {

    int n = 10;
    Element_of_linked_list* head1 = create(n);
    print(head1);

    Element_of_linked_list* head2 = create(n);
    print(head2);

    compare(head1, head2);

    reverse_list(head2);
    print(head2);

    compare(head1, head2);

    delete_list(head1);
    delete_list(head2);
    
    int n1, n2;

    cout << "Enter numbers to add : ";
    cin >> n1 >> n2;

    Element_of_linked_list* number1 = new Element_of_linked_list;
    number1->data = n1;
    number1->next = nullptr;
    number1->previous = nullptr;

    Element_of_linked_list* number2 = new Element_of_linked_list;
    number2->data = n2;
    number2->next = nullptr;
    number2->previous = nullptr;

    Element_of_linked_list* result = add(number1, number2);
    reverse_list(result);
    print(result);
    return 0;
    
}