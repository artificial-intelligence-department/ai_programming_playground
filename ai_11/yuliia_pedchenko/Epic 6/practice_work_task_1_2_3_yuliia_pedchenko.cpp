#include <iostream>

using namespace std; 

class Node { 
    public:
    int data;
    Node* next;
    Node* previous;
};

class List {
    public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

bool is_empty() {

    if (head == nullptr) return true;
    return false;

}

void reverse() {

    int i = 1;

    Node* start = head;
    Node* end = tail;
    int temp;

    while (i <= (size/2)) {
        temp = start->data;
        start->data = end->data;
        end->data = temp;
        start = start->next;
        end = end->previous;
        i++;
    }

}

void create_node_by_number(Node* node, int number) {
    
    if (number < 1) return;

    if (is_empty()) {

        node->next = nullptr;
        node->previous = nullptr;
        head = node;
        tail = node;
        size++;

    }

    else if (number == 1) {

        node->next = head;
        node->previous = nullptr;
        head = node;
        size++;
    }

    else if (number > size) {

        node->previous = tail;
        tail->next = node;
        tail = node;
        node->next = nullptr;
        size++;

    }

    else {

        Node* current = head;
        for (int i = 1; i < number-1; i++) {
            current = current->next;
            }
        node->next = current->next;
        node->previous = current;        
        current->next = node;
        
        size++;
    }

}

void create_node_by_number(int data, int number) {

    Node* a = new Node();
    a->data = data;
    a->next = nullptr;
    create_node_by_number(a, number);

}

void print() {

    if (size == 0) {
        cout << "Список порожній" << endl;
        return;
    }
    Node* current = head;
    for (int i = 0; i < size; i++) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

}

void print_without_space() {

    if (size == 0) {
        cout << "Список порожній" << endl;
        return;
    }
    Node* current = head;
    for (int i = 0; i < size; i++) {
        cout << current->data;
        current = current->next;
    }
    cout << endl;

}

bool compare(List list1, List list2) {

    Node* start1 = list1.head;
    Node* start2 = list2.head;

    if (list1.size != list2.size) return false;
    for (int i = 0; i < list1.size; i++) {
        if (list1.head->data != list2.head->data) return false;
    }
    return true;

}

List addition(List list3, List list4, List list5) {

    if (list3.size < list4.size) {
        for (int i = list3.size; i < list4.size; i++) {
            list3.create_node_by_number(0, i+1);
        }
    }
    else if (list4.size < list3.size) {
        for (int i = list4.size; i < list3.size; i++) {
            list4.create_node_by_number(0, i+1);
        } 
    } 
    
    Node* start1 = list3.head;
    Node* start2 = list4.head;
    int plus = 0;
    int a;

    for (int i = 1; i <= list3.size; i++) {
        if ((start1->data + start2->data + plus)<10) {
            list5.create_node_by_number(start1->data + start2->data + plus, i);
            plus = 0;
        }
        else if ((start1->data + start2->data + plus)>=10) {
            a = (start1->data + start2->data + plus) % 10;
            list5.create_node_by_number(a, i);
            plus = 1;
        }
        start1 = start1->next;
        start2 = start2->next;
    }

    return list5;

}

};

int main() {

    List list1;
    list1.create_node_by_number(1, 1);
    list1.create_node_by_number(2, 2);
    list1.create_node_by_number(3, 3);
    list1.create_node_by_number(4, 4);
    list1.create_node_by_number(5, 5);
    list1.create_node_by_number(6, 6);
    list1.create_node_by_number(7, 7);
    list1.create_node_by_number(8, 8);

    cout << "Список з парною кількістю елементів: " << endl;
    list1.print();

    List list2;
    list2.create_node_by_number(1, 1);
    list2.create_node_by_number(2, 2);
    list2.create_node_by_number(3, 3);
    list2.create_node_by_number(4, 4);
    list2.create_node_by_number(5, 5);
    list2.create_node_by_number(6, 6);
    list2.create_node_by_number(7, 7);
    // list2.create_node_by_number(8, 8);

    //////////////////////  R E V E R S E  //////////////////////

    cout << "Список з непарною кількістю елементів: " << endl;
    list2.print();

    list1.reverse();
    cout << "Обернений список з парною кількістю елементів: " << endl;
    list1.print();

    list2.reverse();
    cout << "Обернений список з парною кількістю елементів: " << endl;
    list2.print();

    //////////////////////  C O M P A R E  //////////////////////

    cout << boolalpha << "Списки є однаковими - " << list1.compare(list1, list2) << endl;

    //////////////////////  B I G   N U M B E R S  //////////////////////

    List list3;
    List list4;
    List list5;

    list3.create_node_by_number(6, 1);
    list3.create_node_by_number(8, 2);
    list3.create_node_by_number(3, 3);
    list3.create_node_by_number(5, 4);
    list3.create_node_by_number(1, 5);
    list3.create_node_by_number(2, 6);
    list3.create_node_by_number(1, 7);

    cout << "Перше велике число: " << endl;
    list3.print_without_space();

    list4.create_node_by_number(3, 1);
    list4.create_node_by_number(9, 2);
    list4.create_node_by_number(3, 3);
    list4.create_node_by_number(5, 4);
    list4.create_node_by_number(6, 5);
    list4.create_node_by_number(2, 6);
    list4.create_node_by_number(3, 7);
    list4.create_node_by_number(1, 7);

    cout << "Друге велике число: " << endl;
    list4.print_without_space();

    list5 = list5.addition(list3, list4, list5);

    cout << "Сума двох чисел: " << endl;
    list5.print_without_space();

    return 0;
}