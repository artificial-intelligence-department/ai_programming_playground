#include <iostream>
#include <fstream>
using namespace std;


struct Node {
    string data;
    Node* next;
    Node* prev;
};

class LinkedList {
  private:
    Node* head; Node* end;
  public:
    
    LinkedList(){
      head = NULL;
      
    } 
     void insert_at_the_beginning(string new_data) {
        Node* newNode = new Node;
        newNode->data = new_data;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
    }

    void print() {
      Node* temp = head;
      if(temp != NULL) {
        
        while(temp != NULL) {
          cout<<temp->data<<" ";
          temp = temp->next;
        }
        cout<<endl;
      } else {
        cout<<"The list is empty.\n";
      }
    } 


    void delete_by_key(string key) {
    Node* curr = head;
    while (curr != NULL && curr->data != key) {
        curr = curr->next;
    }

    if (curr != NULL) {
        if (curr->prev != NULL) { //якшо вузол не голова
            curr->prev->next = curr->next;
        } else {
             head = curr->next;
        }
         if (curr->next != NULL) {
            curr->next->prev = curr->prev;
        }
        delete curr;
    } else {
        cout << "Element not found:(" << endl;
    }
}
    void write_to_file(const string& file_name) {
        ofstream writeFile(file_name);

        Node* curr = head;
        while (curr != nullptr) {
            writeFile << curr->data << " ";
            curr = curr->next;
    }

        writeFile.close();
}
   void delete_all_nodes() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "All nodes are deleted successfully.\n";
}
  void read_from_file(const string& file_name) {
        ifstream readFile(file_name);

        if (!readFile.is_open()) {
            cout << "This file can not be opened:(" << endl;
            return;
        }

       
        delete_all_nodes();

        string value;
        while (readFile >> value) {
            insert_at_the_beginning(value);
        }

        readFile.close();

        if (head != NULL) {
            cout << "List has been read from the file." << endl;
        } else {
            cout << "The  list is empty " << endl;
        }
    }
};


int main() {
    LinkedList DoubleLinkedList;

    DoubleLinkedList.insert_at_the_beginning("hello");
    DoubleLinkedList.insert_at_the_beginning("car");
    DoubleLinkedList.insert_at_the_beginning ("wallpaper");
    DoubleLinkedList.insert_at_the_beginning ("shop");
    DoubleLinkedList.insert_at_the_beginning ("phone");
    cout<<"The list consists of: ";
    DoubleLinkedList.print();
    DoubleLinkedList.delete_by_key("shop");
    cout<<"The list after deleting key element: ";
    DoubleLinkedList.print();
    DoubleLinkedList.insert_at_the_beginning ("day");
    cout<<"The list after insertig a new element: ";
    DoubleLinkedList.print();

    DoubleLinkedList.write_to_file("list.txt");

   
    DoubleLinkedList.read_from_file("list.txt");
    DoubleLinkedList.print();
    
    return 0;
}