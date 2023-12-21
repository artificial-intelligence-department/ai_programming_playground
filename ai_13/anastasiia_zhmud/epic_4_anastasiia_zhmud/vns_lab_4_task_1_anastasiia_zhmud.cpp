#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
void output1(struct Node* element) {

    for (int i = 0; i < 7; i++)
    {
        cout<<element->data<<" ";
        element = element->prev;
    }
    cout<<endl;
}
void del(struct Node* array[5], int value) {
    int k=0, n=0;
    struct Node* arr1[5];
    for(int i=0; i<5; i++){
    if(array[i]->data==value){
            delete array[i];
            array[i] = nullptr;
            k++;
    }
        if(array[i]!=NULL){
        arr1[n]=array[i];
        cout<<array[i]->data<<" ";
        array[i] = array[i]->next;
        n++;}
        if(i==4) break;
   }
   for(int i=0; i<2; i++){
    cout<<arr1[i]->data<<" ";
   }

}

int main(){
    int max=0;
    cout<<"Enter array:  ";
    struct Node* array[5];
    for(int i=0; i<5; i++){
        int k=0;
        array[i]=NULL;
        array[i]=(struct Node*)malloc(sizeof(struct Node));
        cin>>k;
        array[i]->data=k;
        if(array[i]->data>max){
            max=array[i]->data;
        }
    }
    struct Node* head=array[0];
    for(int i=0; i<5; i++){
        if(i==0){
            array[i]->prev=array[4];
            array[i]->next=array[i+1];
        } else if(i==4){
            array[i]->prev=array[i-1];
            array[i]->next=array[0];
        } else{
            array[i]->prev=array[i-1];
            array[i]->next=array[i+1];
        }
    }
    int k=0;
    output1(array[4]);
    del(array, max);
    cout<<endl;
}