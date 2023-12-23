#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top; // верхівка стеку

public:
    Stack() : top(nullptr) {}

    // Перевірка на порожність стеку
    bool isEmpty() {
        if (top == nullptr)
        {
            return true;
        }
        
        return false;
    }

    // Додавання елемента до стеку
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " added to the stack." << endl;
    }

    // Видалення елемента зі стеку
    void pop() {
        if (isEmpty()) {
            cout << "stack is empty.It is impossible to add the element." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " deleted from the stack." << endl;
        delete temp;
    }

    // вивід верхнього елемента стеку (без видалення)
    void peek() {
        if (isEmpty()) {
            cout << "stack is empty." << endl;
            return;
        }
        cout << "the top of the stack: " << top->data << endl;
    }

    
};

int main() {
    Stack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    stack.peek();

    stack.pop();
    stack.peek();

    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}
