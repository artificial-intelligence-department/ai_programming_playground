#include <iostream>

using namespace std;

struct Queue{
    int* queue;
    int count;
};

void createQueue(Queue& q){
    q.count = 0;
    q.queue = new int[q.count];
}

void enqueue(Queue& q, int number){
    int new_size = q.count + 1;
    int* arr = new int[new_size];
    for(int i = 0; i < q.count; i++){
        arr[i]=q.queue[i];
    }
    arr[q.count]=number;
    delete[] q.queue;
    q.count = new_size;
    q.queue = arr;
}

void dequeue(Queue& q){
    if(q.count==0){
        cout << "queue is empty" << endl;
        return;
    }
    int new_size = q.count - 1;
    int* arr = new int [new_size];
    for(int i = 0; i<q.count-1; i++){
        arr[i]=q.queue[i+1];
    }
    delete[] q.queue;
    q.count=new_size;
    q.queue = arr;
}

void showQueue(Queue& q){
    if(q.count == 0){
        cout << "the queue is empty" << endl;
    } else {
        for(int i = 0; i < q.count; i++){
            cout << q.queue[i] << " ";
        }
        cout << endl;
    }
}

void deleteQueue(Queue& q){
    delete[] q.queue;
    q.count=0;
}

int main(){
    Queue q;
    createQueue(q);
    int req;
    cout << "enter the count of requests:" << endl;
    cin >> req;
    for(int i = 0; i < req; i++){
        string str;
        cout << "enter the name of operation (push, pop, show): ";
        cin >> str;
        if(str == "push"){
            int number;
            cout << "enter the number: " << endl;
            cin >> number;
            enqueue(q, number);
        } else if(str == "pop"){
            dequeue(q);
        } else if(str == "show"){
            showQueue(q);
        }
    }
    return 0;
}