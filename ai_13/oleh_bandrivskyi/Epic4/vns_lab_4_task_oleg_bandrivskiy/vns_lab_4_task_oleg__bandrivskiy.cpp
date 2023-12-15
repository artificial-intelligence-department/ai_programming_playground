#include <iostream>

using namespace std;

int main() {
    int N, K;

    cin >> N;



    cin >> K;

    int circularArray[N];

    for (int i = 0; i < N; ++i) {
        circularArray[i] = i + 1;
    }

    cout << "Масив, починаючи з K-ого елемента і до K+1:" << endl;
    for (int i = 0; i < 2; ++i) {
        cout << circularArray[(K + i) % N] << " ";
    }
    cout << endl;

    int newFirstElement = 0; 
    int newLastElement = N + 1; 


    circularArray[(K - 1 + N) % N] = newFirstElement;
    circularArray[(K + N) % N] = newLastElement;


    cout << "Масив після додавання нових елементів:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << circularArray[i] << " ";
    }
    cout << endl;


    for (int i = 0; i < N; ++i) {
        if (circularArray[i] % 2 != 0) {
            circularArray[i] = 0; 
        }
    }


    cout << "Масив після знищення непарних елементів:" << endl;
    for (int i = 0; i < 2; ++i) {
        cout << circularArray[(K + i) % N] << " ";
    }
    cout << endl;

    return 0;
}