#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int key;
    Node* next;
    Node* prev;
};

class DynamicList {
private:
    Node* head;

public:
    DynamicList() : head(nullptr) {}

    void create_list() {
        head = nullptr;
        cout << "Created an empty list." << endl;
    }

    void add_element(int value) {
        Node* new_node = new Node;
        new_node->key = value;
        new_node->next = nullptr;
        new_node->prev = nullptr;

        if (head == nullptr) {
            head = new_node;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
    }

    void remove_element(int position) {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        if (position == 1) {
            head = temp->next;
            delete temp;
            cout << "Element at position " << position << " removed from the list." << endl;
            return;
        }

        for (int i = 1; temp != nullptr && i < position - 1; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position exceeds the list size." << endl;
            return;
        }

        Node* next_node = temp->next->next;
        delete temp->next;
        temp->next = next_node;
        cout << "Element at position " << position << " removed from the list." << endl;
    }

    void add_to_beginning(int value) {
        Node* new_node = new Node;
        new_node->key = value;
        new_node->next = head;
        new_node->prev = nullptr;
        
        if (head != nullptr) {
            head->prev = new_node;
        }
        head = new_node;
        cout << "Added element with key " << value << " to the beginning of the list." << endl;
    }

    void print_list() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head;
        cout << "List elements: ";
        while (current != nullptr) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

    void write_to_file(string filename) {
        ofstream file(filename);

        if (!file) {
            cout << "Failed to open file for writing." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            file << current->key << " ";
            current = current->next;
        }

        file.close();
        cout << "List written to file " << filename << "." << endl;
    }

    void clear_list() {
        Node* current = head;
        Node* temp;

        while (current != nullptr) {
            temp = current;
            current = current->next;
            delete temp;
        }

        head = nullptr;
        cout << "List cleared." << endl;
    }

    void restore_from_file(string filename) {
        clear_list();

        ifstream file(filename);
        int value;

        if (!file) {
            cout << "Failed to open file for restoring the list." << endl;
            return;
        }

        while (file >> value) {
            add_element(value);
        }

        file.close();
        cout << "List restored from file " << filename << "." << endl;
    }

    void delete_list() {
        clear_list();
        cout << "List deleted." << endl;
    }
};

int main() {
    DynamicList my_list;
    my_list.create_list();

    int numberOfElements;
    cout << "Enter the number of elements to add: ";
    cin >> numberOfElements;

    cout << "Enter the elements: ";
    for (int i = 0; i < numberOfElements; ++i) {
        int element;
        cin >> element;
        my_list.add_element(element);
    }

    my_list.print_list();
    my_list.write_to_file("my_list.txt");

    int positionToRemove;
    cout << "Enter the position of the element to remove: ";
    cin >> positionToRemove;
    my_list.remove_element(positionToRemove);

    my_list.print_list();

    int elementToAdd;
    cout << "Enter the element to add at the beginning: ";
    cin >> elementToAdd;
    my_list.add_to_beginning(elementToAdd);

    my_list.print_list();
    my_list.write_to_file("my_list.txt");

    my_list.delete_list();
    my_list.print_list(); 

    my_list.restore_from_file("my_list.txt");
    my_list.print_list();

    my_list.delete_list();
    return 0;
}
