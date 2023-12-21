#include<iostream>
using namespace std;

class linkedlist {
    private:

    struct node {
        int key;
        node* next;
        node(int value) : key(value), next(nullptr) {}
    
    };

    node* head;

    void createnode(int value) {
        node* newNode = new node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }


    public: 
    linkedlist() : head(nullptr) {}

    
    void createlist(int n){
        int value;
        for(int i=0; i<n; i++){
            cin>>value;
            createnode(value);
        }
    }

    void showlist(){
        node* temp = head;

        if(temp==nullptr){
            cout<<"list is empty\n";
            return;
        }

        while (temp != nullptr) {
            cout << temp->key << " ";
            temp = temp->next;
        } 
        cout << "\n";
    }

    void reverse(){
        node* current = head;
        node* prev = nullptr;
        node* next = nullptr;

        while(current!=nullptr){
            next = current->next;
            current->next = prev;
            prev = current; 
            current = next;
        }

        head = prev;
    }
   

};

int main(){
    linkedlist list; 
    int n;
    cin>>n;

    list.createlist(n);
    list.showlist();

    cout<<"\n";

    list.reverse();
    list.showlist();

}