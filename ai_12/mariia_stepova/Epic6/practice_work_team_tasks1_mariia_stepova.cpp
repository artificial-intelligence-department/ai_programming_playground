#include <iostream>


struct Node {
   int data;
   Node* next;
   Node(int val) : data(val), next(nullptr) {}
};


class LinkedList {
public:
   Node* reverse(Node* head) {
       Node* prev = nullptr;
       Node* current = head;
       Node* next = nullptr;


       while (current != nullptr) {
           next = current->next;
           current->next = prev;
           prev = current;
           current = next;
       }


       return prev; // новий початок списку
   }


   void printList(Node* node) {
       while (node != nullptr) {
           std::cout << node->data << " ";
           node = node->next;
       }
       std::cout << std::endl;
   }
};


int main() {
   using namespace std;


   LinkedList list;
   Node* head = new Node(1);
   head->next = new Node(2);
   head->next->next = new Node(3);
   head->next->next->next = new Node(4);


   cout << "Оригінальний список: ";
   list.printList(head);


   head = list.reverse(head);


   cout << "Обернутий список: ";
   list.printList(head);


   return 0;
}
