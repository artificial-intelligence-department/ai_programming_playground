#include <iostream>

using namespace std;

struct FIFO {
    int arr[100000] = {0};
    int size = 0;
    
    int pop() {
        int elem = arr[0];
        int i = 1;
        while (i < size) {
            arr[i - 1] = arr[i];
            i++;
        }
        size--;
        return elem;
    }
    
    bool push(int newElem) {
        if (size < 100000) {
            arr[size] = newElem;
            size++;
            return true;
        }
        else {
            return false;
        }
    }
    
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    FIFO queue;
    queue.push(1);
    queue.print();
    
    queue.push(2);
    queue.print();
    
    queue.push(3);
    queue.print();
    
    queue.pop();
    queue.print();
    
    queue.pop();
    queue.print();
    
    queue.pop();
    queue.print();
    
    return 0;
}