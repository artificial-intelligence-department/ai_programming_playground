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

    void createnodefront(int value) {
        node* newNode = new node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = nullptr;
        } else {
            newNode->next = head;
            head = newNode;
        }
        return;
    }

    public: 
    linkedlist() : head(nullptr) {}

    
    void createlist_pushback(int n){
        int value;
        for(int i=0; i<n; i++){
            cin>>value;
            createnode(value);
        }
    }

    void createlist_pushfront(int n){
        int value;
        for(int i=0; i<n; i++){
            cin>>value;
            createnodefront(value);
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
    
    linkedlist addnumbers(linkedlist& l2){
    
        int rem = 0;
        int sum;

        linkedlist listsum;

        node* temp1 = head;
        node* temp2 = l2.head;
       

        while(temp1!=nullptr&&temp2!=nullptr){
            
            sum = temp1->key + temp2->key;

            sum += rem;
            rem = sum/10;
            sum = sum%10;

            listsum.createnodefront(sum);

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
            if(temp1==nullptr&&temp2!=nullptr){
                while(temp2!=nullptr){
                    sum = temp2->key + rem;
                    
                    rem = sum/10;
                    sum = sum%10;

                    listsum.createnode(sum);

                    temp2 = temp2->next;
                }
                if(rem!=0)
                    listsum.createnode(rem);

            } else if (temp2==nullptr&&temp1!=nullptr){
                while(temp1!=nullptr){
                    sum = temp1->key + rem;
                    
                    rem = sum/10;
                    sum = sum%10;

                    listsum.createnodefront(sum);

                    temp1 = temp1->next;
                }
                if(rem!=0)
                    listsum.createnodefront(rem);

            } else if(temp1==nullptr&&temp2==nullptr&&rem!=0){
                listsum.createnodefront(rem);
            }

        
        return listsum;
    }
};


int main(){
    linkedlist list1, list2;
    int n1, n2;

    cin>>n1;
    list1.createlist_pushfront(n1);

    cin>>n2;
    list2.createlist_pushfront(n2);

    linkedlist listsum = list1.addnumbers(list2);

    cout<<"\n";
    listsum.showlist();

    return 0;
}