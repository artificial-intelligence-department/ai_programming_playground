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

    bool compare(linkedlist& otherlist ){
        node* h1 = this->head;
        node* h2 = otherlist.head;

        while(h1!=nullptr && h2!=nullptr){
            if(h1->key!=h2->key){
                return 0;
            }
            h1=h1->next;
            h2=h2->next;
        }

        if(h1!=h2){
            return 0;
        }

        return 1;
    }
   
};
  
int main(){
    linkedlist list1, list2;
    int n1, n2;

    cin>>n1;
    list1.createlist(n1);

    cin>>n2;
    list2.createlist(n2);

    if(list1.compare(list2)){
        cout<<"True";
    } else {
        cout<<"False";
    }

    return 0;

}