#include <iostream>


class Node {
public:
   int data;
   Node* prev;
   Node* next;
   Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};


class DoublyLinkedList {
private:
   Node* head;
   Node* tail;
   int size;


public:
   DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}


   void insert(int index, int n, int* arr) {
       if (index < 0 || index > size) {
           std::cout << "Invalid index for insertion." << std::endl;
           return;
       }


       for (int i = 0; i < n; ++i) {
           Node* newNode = new Node(arr[i]);
           if (head == nullptr) {
               head = newNode;
               tail = newNode;
           } else if (index == 0) {
               newNode->next = head;
               head->prev = newNode;
               head = newNode;
           } else if (index == size) {
               tail->next = newNode;
               newNode->prev = tail;
               tail = newNode;
           } else {
               Node* temp = head;
               for (int j = 0; j < index - 1; ++j) {
                   temp = temp->next;
               }
               newNode->next = temp->next;
               newNode->prev = temp;
               temp->next->prev = newNode;
               temp->next = newNode;
           }
           ++size;
           ++index;
       }
   }


   void erase(int index, int n) {
       if (index < 0 || index >= size || n <= 0) {
           std::cout << "Invalid index or number of elements to erase." << std::endl;
           return;
       }


       while (n > 0 && index < size) {
           Node* temp;
           if (index == 0) {
               temp = head;
               head = head->next;
               if (head != nullptr) {
                   head->prev = nullptr;
               }
           } else if (index == size - 1) {
               temp = tail;
               tail = tail->prev;
               if (tail != nullptr) {
                   tail->next = nullptr;
               }
           } else {
               Node* curr = head;
               for (int i = 0; i < index; ++i) {
                   curr = curr->next;
               }
               temp = curr;
               curr->prev->next = curr->next;
               curr->next->prev = curr->prev;
           }
           delete temp;
           --size;
           --n;
       }
   }


   int getSize() {
       return size;
   }


   int get(int index) {
       if (index < 0 || index >= size) {
           std::cout << "Invalid index to get element." << std::endl;
           return -1; // Return a default value indicating an error
       }


       Node* temp = head;
       for (int i = 0; i < index; ++i) {
           temp = temp->next;
       }
       return temp->data;
   }


   void set(int index, int value) {
       if (index < 0 || index >= size) {
           std::cout << "Invalid index to set element." << std::endl;
           return;
       }


       Node* temp = head;
       for (int i = 0; i < index; ++i) {
           temp = temp->next;
       }
       temp->data = value;
   }


   friend std::ostream& operator<<(std::ostream& os, DoublyLinkedList& list) {
       Node* temp = list.head;
       while (temp != nullptr) {
           os << temp->data << " ";
           temp = temp->next;
       }
       return os;
   }


   ~DoublyLinkedList() {
       Node* temp = head;
       while (temp != nullptr) {
           Node* next = temp->next;
           delete temp;
           temp = next;
       }
       head = nullptr;
       tail = nullptr;
       size = 0;
   }
};


int main() {
   int Q;
   std::cin >> Q;
   DoublyLinkedList list;


   while (Q--) {
       std::string query;
       std::cin >> query;
       if (query == "insert") {
           int index, n;
           std::cin >> index >> n;
           int* arr = new int[n];
           for (int i = 0; i < n; ++i) {
               std::cin >> arr[i];
           }
           list.insert(index, n, arr);
           delete[] arr;
       } else if (query == "erase") {
           int index, n;
           std::cin >> index >> n;
           list.erase(index, n);
       } else if (query == "size") {
           std::cout << list.getSize() << std::endl;
       } else if (query == "get") {
           int index;
           std::cin >> index;
           std::cout << list.get(index) << std::endl;
       } else if (query == "set") {
           int index, value;
           std::cin >> index >> value;
           list.set(index, value);
       } else if (query == "print") {
           std::cout << list << std::endl;
       } else {
           std::cout << "Invalid query." << std::endl;
       }
   }


   return 0;
