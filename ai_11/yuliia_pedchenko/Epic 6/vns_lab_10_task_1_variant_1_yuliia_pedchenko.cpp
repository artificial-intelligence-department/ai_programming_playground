
// 8. Написати функцію для відновлення списку з файлу.
// 9. Відновити список і роздрукувати його.
// 10.Знищити список.

#include <iostream>
#include <fstream>

using namespace std;

class Node { 
    public:
    int data;
    Node* next;
};

class List {
    public:
    Node* head = nullptr;
    int size = 0;

bool is_empty() {

    if (head == nullptr) return true;
    return false;

}

void create_node_by_number(Node* node, int number) {
    
    if (number < 1) return;

    if (is_empty()) {

        node->next = nullptr;
        head = node;
        size++;

    }

    else if (number == 1) {

        node->next = head;
        head = node;
        size++;
    }

    else if (number > size) {

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = node;
        size++;

    }

    else {

        Node* current = head;
        for (int i = 1; i < number-1; i++) {
            current = current->next;
            }
        node->next = current->next;
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

void delete_node_by_number(int number) {

    if(is_empty() || number < 1 || number > size) return;

    else if(number == 1 && size == 1) {

        delete head;
        head = nullptr;
        size--;

    } 

    else if (number == 1 && size > 1) {

        Node* temp;
        temp = head;
        head = head->next;
        delete temp;
        size--;

    }

    else if (number == size) {

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next->next;
        current->next = nullptr;
        size--;

    }

    else {
        Node* temp;
        Node* current = head;
        for (int i = 1; i < number-1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;

    }
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

void tofile(string path) {

    ofstream tofile;
    tofile.open(path, ios::app);
    Node* current = head;
    for (int i = 0; i < size; i++) {
        tofile << current->data << "\n";
        current = current->next;
    }
    tofile.close();

}

void destroy() {

    Node* del;
    Node* current = head;
    while (current->next != nullptr) {
        del = current;
        current = current->next;
        delete del;
        size--;
    }
    delete current->next;
    size--;
    head = nullptr;

}

void fromfile(string path) {

    int number = 1;
    string line;
    ifstream fromfile;
    fromfile.open(path, ios::app);
    while (getline(fromfile, line)) {
        int data = stoi(line);
        create_node_by_number(data, number);
        number++;
    }
    number--;
    fromfile.close();
}

};

/////////////////////////////////////////// 

int main() {

    List list;
    list.create_node_by_number(3, 1);
    list.create_node_by_number(5, 2);
    list.create_node_by_number(8, 3);
    list.create_node_by_number(1, 4);
    list.create_node_by_number(6, 5);
    list.create_node_by_number(0, 6);
    list.create_node_by_number(11, 7);

    list.print();
    
    cout << "Елемент під яким номером ви хочете знищити?(від 1 до 7)" << endl;
    int a;
    cin >> a;

    list.delete_node_by_number(a);

    list.print();

    cout << "Який елемент і яким номером ви хочете додати?(номер від 1 до 7)" << endl;
    int b, c;
    cin >> b >> c;
    list.create_node_by_number(b, c);

    list.print();

    ofstream destroydata;
    destroydata.open("Dota2.txt", ios::trunc);
    destroydata.close();

    list.tofile("Dota2.txt");

    list.destroy();

    list.print();

    list.fromfile("Dota2.txt");

    list.print();

    list.destroy();

    list.print();

    return 0;
}