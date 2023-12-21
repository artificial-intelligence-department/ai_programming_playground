#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

int add(Node* n1){
    int r = 1;
    int result = 0;
    while(n1 != nullptr){
       result += (n1->data) * r;
       r*= 10;
       n1 = n1 -> next;
    }

    return result;
  
}

int main() {
    Node* number1 = new Node(4);
    number1->next = new Node(8);
    number1->next->next = new Node(9);

   int result = add(number1);
   std::cout << result;

    return 0;
}
