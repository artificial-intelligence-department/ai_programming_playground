#include <iostream>


struct Node {
   int data;
   Node* next;
   Node(int val) : data(val), next(nullptr) {}
};


class LinkedList {
public:
   bool compare(Node* h1, Node* h2) {
       while (h1 != nullptr && h2 != nullptr) {
           if (h1->data != h2->data) {
               return false;
           }
           h1 = h1->next;
           h2 = h2->next;
       }


       return (h1 == nullptr && h2 == nullptr);
   }
};


int main() {
   using namespace std;


   LinkedList list;
   Node* head1 = new Node(1);
   head1->next = new Node(2);
   head1->next->next = new Node(3);


   Node* head2 = new Node(1);
   head2->next = new Node(2);
   head2->next->next = new Node(3);


   cout << "Результат порівняння списків: ";
   if (list.compare(head1, head2)) {
       cout << "Списки ідентичні.\n";
   } else {
       cout << "Списки не ідентичні.\n";
   }


   return 0;
}
