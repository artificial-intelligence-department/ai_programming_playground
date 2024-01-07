#include <iostream>
#include <list>
using namespace std;

class DblLinkedList{
private:
    struct Node{
        int data;
        Node *prev;
        Node *next;
    };

    Node *head;
    Node *tail;
    size_t size;
public:
    void Show(){
        if(size == 0){
            cout << "List is empty" << endl;;
            return;
        }

        Node *current = head;
        while (current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void PushBack(const int& value){
        if(size == 0){
            head = new Node{value, nullptr, nullptr};
            tail = head;
        }else{
            tail->next = new Node{ value, tail, nullptr};
            tail = tail->next;
        }
        size++;
    }

    void PushFront(int &value){
        if(size == 0){
            head = new Node{value, nullptr,nullptr};
            tail = head;
        }else{
            Node* newHead = new Node{value, nullptr, head};
            head->prev = newHead;
            head = newHead;
        }
        size++;
    }

    void Remove(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                if (head == current) {
                    if (size == 1) {
                        delete head;
                        head = nullptr;
                        tail = nullptr;
                    } else {
                        Node* tmp = head;
                        head = head->next;
                        head->prev = nullptr;
                        delete tmp;
                    }
                } else if (tail == current) {
                    Node* tmp = tail;
                    tail = tail->prev;
                    tail->next = nullptr;
                    delete tmp;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                }
                size--;
                return;
            }
            current = current->next;
        }
    }

};

int main(){
    DblLinkedList list;
    int k = 3;
    cout << "List: " ;
    for (int value = 0; value < 10; value++){
        list.PushBack(value);
    }
    list.Show();

    cout << "List after deletion: ";
    for (int i = 0; i < k; i++){
        list.Remove(i);
    }
    
    list.Show();

    cout << "List after adding elements: ";
    for (int i = 0; i < k ; i++){
        list.PushFront(i);
    }
    list.Show();

}
