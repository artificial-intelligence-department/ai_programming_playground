#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> arr;
    int top;

public:
    Stack() : top(-1) {}

    void push(int value) {
        ++top;
        arr.push_back(value);
    }

    bool pop() {
        if (top >= 0) {
            --top;
            arr.pop_back();

            return true;
        }

        return false;
    }

    int seek() {
        if (top >= 0) return arr[top];
        throw std::out_of_range("No such element");
    }

    void erase() {
        while (top >= 0) 
            this->pop();
    }

    void printStack() {
        std::cout << "Stack: ";
        for (int i = 0; i <= top; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    using namespace std;

    Stack myStack;
    int input;

    do {
        cout << "Menu: \n"
            "1 - Add element\n"
            "2 - Remove element\n"
            "3 - Print stack\n"
            "0 - Exit\n"
            "Enter your choice: ";
        cin >> input;

        switch (input) {
            case 1: {
                int element;
                cout << "Enter element: ";
                cin >> element;

                myStack.push(element);
                break;
            }
            case 2: {
                bool isDeleted = myStack.pop();
                cout << (isDeleted
                        ? "Deleted last element" 
                        : "Stack is already empty")
                    << endl;

                break;
            }
            case 3: 
                myStack.printStack();
                break;
            default: 
                break;
        }
    } while (input != 0);

    return 0;
}