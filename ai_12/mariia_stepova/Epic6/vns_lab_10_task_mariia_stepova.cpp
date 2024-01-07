#include <iostream>
#include <fstream>
#include <string>


using namespace std;


struct Node {
   string data;
   Node* next;
   Node* prev;


   Node(const string& data) : data(data), next(nullptr), prev(nullptr) {}
};


class DoublyLinkedList {
public:
   Node* head;
   Node* tail;


   DoublyLinkedList() : head(nullptr), tail(nullptr) {}


   void push_back(const string& value) {
       Node* newNode = new Node(value);
       if (tail == nullptr) {
           head = tail = newNode;
       } else {
           tail->next = newNode;
           newNode->prev = tail;
           tail = newNode;
       }
   }


   void printList() {
       Node* current = head;
       if (current == nullptr) {
           cout << "Список порожній" << endl;
           return;
       }
       while (current != nullptr) {
           cout << current->data << " ";
           current = current->next;
       }
       cout << endl;
   }


   void deleteByKey(const string& key) {
       Node* current = head;
       while (current != nullptr) {
           Node* nextNode = current->next;
           if (current->data == key) {
               if (current->prev != nullptr) {
                   current->prev->next = current->next;
               } else {
                   head = current->next;
                   if (head != nullptr) {
                       head->prev = nullptr;
                   }
               }
               if (current->next != nullptr) {
                   current->next->prev = current->prev;
               } else {
                   tail = current->prev;
                   if (tail != nullptr) {
                       tail->next = nullptr;
                   }
               }
               delete current;
           }
           current = nextNode;
       }
   }


   void addAtPosition(const string& data, int position) {
       Node* newNode = new Node(data);
       if (position == 0) {
           newNode->next = head;
           if (head != nullptr) {
               head->prev = newNode;
           }
           head = newNode;
           if (tail == nullptr) {
               tail = newNode;
           }
       } else {
           Node* current = head;
           for (int i = 0; i < position; ++i) {
               if (current == nullptr) {
                   cout << "Помилка: Зазначена позиція перевищує довжину списку" << endl;
                   return;
               }
               current = current->next;
           }
           if (current != nullptr) {
               newNode->prev = current->prev;
               newNode->next = current;
               if (current->prev != nullptr) {
                   current->prev->next = newNode;
               } else {
                   head = newNode;
               }
               current->prev = newNode;
           }
       }
   }


   void writeTo(const string& file) {
       ofstream outFile(file);
       Node* current = head;
       while (current != nullptr) {
           outFile << current->data << endl;
           current = current->next;
       }
       outFile.close();
   }


   void readFrom(const string& file) {
       ifstream inFile(file);
       string line;
       while (getline(inFile, line)) {
           push_back(line);
       }
       inFile.close();
   }


   void clearList() {
       Node* current = head;
       while (current != nullptr) {
           Node* next = current->next;
           delete current;
           current = next;
       }
       head = tail = nullptr;
   }


   ~DoublyLinkedList() {
       clearList();
   }
};


int main() {
   DoublyLinkedList myList;


   myList.push_back("Список");
   myList.push_back("рядків");
   myList.push_back("для");
   myList.push_back("запису");


   cout << "Початковий список:" << endl;
   myList.printList();


   myList.deleteByKey("для");


   cout << "Список після видалення:" << endl;
   myList.printList();


   myList.addAtPosition("важливих", 2);
   cout << "Список після додавання:" << endl;
   myList.printList();


   myList.writeTo("myList.txt");


   myList.clearList();


   cout << "Список після очищення:" << endl;
   myList.printList();


   myList.readFrom("myList.txt");


   cout << "Список після відновлення:" << endl;
   myList.printList();


   return 0;
}
