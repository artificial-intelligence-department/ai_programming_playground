#include <iostream>

using namespace std;

int main() {
    int q[7];
    int start = 0, ends = 0;

    cout << "Please enter 7 elements: " << endl;

    for (int h = 0; h < 7; h++) {
        int a;
        cin >> a;
        q[ends++] = a;
    }

    if (start < ends) {
        cout << "the first element of the queue: " << q[start] << endl;

        start++;

        cout << "new first queue element (after deletion): " << q[start] << endl;

        cout << "the last element of the queue: " << q[ends - 1] << endl;
        cout << "the queue is full!" << endl;
    }
    else {
        cout << "The queue is empty!" << endl;
    }

    return 0;
}