#include <iostream>
#include <ctime>
using namespace std;

class List {
private:
    struct Node{
        int data;
        Node* next;
    };
    Node* head;
    void copy(const List& other){
        if (other.head == nullptr){
            head = nullptr;
        } else {
            head = new Node{other.head->data, nullptr};
            Node *current = head;
            Node *otherCurrent = other.head;
            while (otherCurrent->next != nullptr) {
                current->next = new Node{otherCurrent->next->data, nullptr};
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
    }
public:
//    Constructors
    List()
            : head(nullptr)
    {};
    List(const List& other)
            : head(nullptr)
    {
        copy(other);
    };
//    Add methods
    void pushBack(const int& value){
        if (head == nullptr){
            head = new Node{value, nullptr};
        } else{
            Node* current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = new Node{value, nullptr};
        }
    };
//    Remove methods
    void remove(const int& value){
        Node* previous = nullptr;
        Node* current = head;
        while(current != nullptr){
            if (current->data == value){
                if (previous == nullptr){
                    head = current->next;
                } else{
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    };
    void clear() {
        while(head != nullptr){
            Node* current = head;
            head = head->next;
            delete current;
        }
    };
//    Print method
    void print() const {
        if (head == nullptr){
            cout << "List is empty\n";
        } else{
            Node* current = head;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    };
    static void print(Node* node) {
        if (node == nullptr){
            cout << "List is empty\n";
        } else{
            Node* current = node;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    };
//    Reverse method
    Node* reverse() {
        List rev(*this);
        Node* current = rev.head;
        Node* next_r;
        Node* prev_r = nullptr;
        while(current != nullptr){
            next_r = current->next;
            current->next = prev_r;
            prev_r = current;
            current = next_r;
        }
        rev.head = prev_r;
        return rev.head;
    };
//    Compare method
    static bool compare(Node* h1, Node* h2){
        Node* current1 = h1;
        Node* current2 = h2;
        while(current1 != nullptr && current2 != nullptr){
            if (current1->data != current2->data){
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        return (current1 == nullptr && current2 == nullptr);
    };
    [[nodiscard]] bool compare(const List& other) const {
        return compare(head, other.head);
    }
//    Big numbers add method
    static List add(Node* h1, Node* h2){
        Node* current1 = h1;
        Node* current2 = h2;
        List sum_list;
        int remainder = 0;
        while(current1 != nullptr || current2 != nullptr){
            int sum = remainder;
            if (current1 != nullptr) {
                sum += current1->data;
                current1 = current1->next;
            }
            if (current2 != nullptr) {
                sum += current2->data;
                current2 = current2->next;
            }
            remainder = sum / 10;
            sum_list.pushBack(sum%10);
        }
        if (remainder > 0){
            sum_list.pushBack(remainder);
        }
        return sum_list;
    };
    [[nodiscard]] List add(const List& other) const {
        return add(head, other.head);
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    cout << "Reverse list demo: \n";
    List list;
    for (int i = 0; i < 10; ++i)
        list.pushBack(i);
    list.print();
    List::print(list.reverse());
    cout << "Compare lists demo: \n";
    List list1;
    List list2;
    for (int i = 0; i < 10; ++i)
        list1.pushBack(i);
    list1.print();
    for (int i = 0; i < 20; i+=2)
        list2.pushBack(i);
    list2.print();
    list1.compare(list2) ? cout << "Equal\n" : cout << "Not equal\n";
    cout << "Add big numbers demo: \n";
    List list3;
    for (int i = 0; i < 20; ++i)
        list3.pushBack(rand() % 10);
    List::print(list3.reverse());
    List list4;
    for (int i = 0; i < 15; ++i)
        list4.pushBack(rand() % 10);
    cout << string(10, ' ');
    List::print(list4.reverse());
    List::print(list3.add(list4).reverse());
    list.clear();
    list1.clear();
    list2.clear();
    list3.clear();
    list4.clear();
    return 0;
}
