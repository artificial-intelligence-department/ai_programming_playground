#include<iostream>
#include<fstream>
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

    void addnode(int position, int value){
        int count = 1; 

        if(position<=0){
            cout<<"wrong position!\n";
            return;
        }

        node* newNode = new node(value);

        if (position == 1 || head == nullptr) {
            newNode->next = head;
            head = newNode;
            return;
        }

        node* temp = head;

        while (temp != nullptr && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "wrong position (larger than list)\n";
            return;
        }

    newNode->next = temp->next;
    temp->next = newNode;

    }

    void deletenode(int position){
        int count = 1; 
        node* temp = head;
        node* previous = nullptr;

        if(position<=0){
            cout<<"wrong position!\n";
            return;
        }

        while (temp != nullptr && count!=position) {
            previous = temp;
            temp = temp->next;
            count++;
        }

        if(temp==nullptr){
            cout<<"element not found\n";
        }

        if(previous==nullptr){
            head = temp->next;
        } else {
            previous->next = temp->next;
        }

        delete temp;

    }

    void showlist() {
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

    void deletelist() {
        node* current = head;
        node* next = nullptr;

        while (current!=nullptr) {
            next = current->next;
            delete current;
            current = next;
        }

        head = nullptr; 
    }
    
    void writetofile(){
        ofstream f("Linkedlist.dat");

        if(f.bad()){
            cout<<"error\n";
            return;
        }

        node* current = head;
        while(current!=nullptr){
            f<< current->key<<" ";
            current = current->next;
        }

        f.close();
    }

    void getlistfromfile(){
        ifstream f("Linkedlist.dat");

        if(f.bad()){
            cout<<"error 2\n";
            return;
        }

        int value;
        while(f >> value){
            createnode(value);
        }

        f.close();

    }

    
};

int main(){
    linkedlist list;
    int num, pos, value;
    cin>>num;

    list.createlist(num);

    cout<<"\n";

    list.showlist();

    cout<<"\n";

    cout<<"What position?\n";
    cin>>pos;
    cout<<"Value?\n";
    cin>>value;
    
    list.addnode(pos, value);

    list.showlist();
    cout<<"\nWhat do you want to delete?\n";
    cin>>pos;

    list.deletenode(pos);
    cout<<"\n";
    list.showlist();

    cout<<"\n";

    list.writetofile();

    list.deletelist();
    list.showlist();

    list.getlistfromfile();
    cout<<"\n";
    list.showlist();

    list.deletelist();

    return 0;
}