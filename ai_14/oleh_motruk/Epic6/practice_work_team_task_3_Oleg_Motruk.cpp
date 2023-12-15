#include <iostream>
#include <sstream>
using namespace std;

class Node {
private:
    int data;
    Node* next;

public:
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    int get_data() {
        return data;
    }

    Node* get_next() {
        return next;
    }

    void set_next(Node* nextNode) {
        next = nextNode;
    }

    static Node* add(Node* n1, Node* n2) {
        Node* result = nullptr;
        Node* tail = nullptr;
        int carry = 0;

        while (n1 != nullptr || n2 != nullptr || carry != 0) {
            int sum = carry;
            if (n1 != nullptr) {
                sum += n1->get_data();
                n1 = n1->get_next();
            }
            if (n2 != nullptr) {
                sum += n2->get_data();
                n2 = n2->get_next();
            }
            carry = sum / 10;
            sum %= 10;

            Node* temp = new Node(sum);
            if (result == nullptr) {
                result = temp;
                tail = temp;
            } else {
                temp->set_next(result);
                result = temp;
            }
        }
        return result;
    }

    static void print(Node* head) {
        Node* current = head;
        while (current != nullptr) {
            cout << current->get_data();
            current = current->get_next();
        }
        cout << endl;
    }

    static void printReverse(Node* head) {
        if (head == nullptr) {
            return;
        }
        printReverse(head->get_next());
        cout << head->get_data();
    }



    static Node* createlist(const string& input) {
        Node* head = nullptr;
        Node* tail = nullptr;

        for (size_t i = 0; i < input.length(); ++i) {
            int num = input[i] - '0';
            Node* temp = new Node(num);
            
            if (head == nullptr) {
                head = temp;
                tail = temp;
            } else {
                tail->set_next(temp);
                tail = temp;
            }
        }
    return head;
}

};

int main() {
    string input;

    cout << "Enter first number: ";
    getline(cin, input);
    Node* number1 = Node::createlist(input);


    cout << "Enter second number: ";
    getline(cin, input);
    Node* number2 = Node::createlist(input);

    cout << "First number: ";
    Node::print(number1);

    cout << "Second number: ";
    Node::print(number2);

    Node* result = Node::add(number1, number2);
    cout << "Sum of numbers: ";
    Node::print(result);

    return 0;
}