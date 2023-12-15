//
// Created by olehio-p on 11/29/2023.
//
#include <algorithm>
#include <stdexcept>
#include <string>
#include <iostream>


class Stack{
    private:
        int capacity;
        int* array;
        int end;
    public:
        void push(int elem);
        int pop();
        void printStack();
        explicit Stack(int _capacity = 100) {
            end = 0;
            capacity = _capacity;
            array = new int[capacity];
        }
        ~Stack() {
            delete[] array;
        }
};

void Stack::push(int elem) {
    if(end >= capacity) {
        int* new_array = new int[capacity + (int)(capacity * 0.75)];
        std::copy(array, array+end, new_array);
        capacity += (int)(capacity * 0.75);
        delete[] array;
        array = new_array;
    }
    array[end++] = elem;
}

int Stack::pop() {
    if(end > 0) {
        return array[end--];
    } else {
        throw std::out_of_range("The Stack is empty");
    }
}

void Stack::printStack() {
    std::string str = "Stack{";
    if(end == 0) {
        std::cout << "Stack{}" << std::endl;
        return;
    }
    for(int i = 0; i < end; i++) {
        str += std::to_string(array[i]);
        if(i != end-1) {
             str += ", ";
        } else {
            str += "}";
        }
    }
    std::cout << str << std::endl;
}

int main(int argc, char const *argv[])
{
    Stack stack = *new Stack(10);
    stack.push(10);
    stack.push(9);
    stack.printStack();
    stack.pop();
    stack.printStack();
    stack.pop();
    stack.printStack();
    stack.push(10);
    stack.push(9);
    stack.push(8);
    stack.push(7);
    stack.push(6);
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);
    stack.push(0);
    stack.printStack();
    return 0;
}
