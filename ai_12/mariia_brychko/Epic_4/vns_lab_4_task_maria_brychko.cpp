#include <iostream>
#include <random>
using namespace std;

const int N = 100;
int a[N];

void print(int array[], int sizearray) {
    for (int i = 0; i < sizearray; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main () {

    int realsize;
    cout << "Enter the actual length of the array (no more than 100): ";
    cin >> realsize;

    while (realsize <= 0 || realsize > N) {
        cout << "Incorrect array length" << endl;
        cout << "Enter the actual length of the array (no more than 100): ";
        cin >> realsize;
    }

    random_device r;                                  
    mt19937 gen(r());                               
    uniform_int_distribution<> distrib(0, 1000);        

    int randomNumber = distrib(gen);  

    for (int i = 0; i < realsize; i++) {
        a[i] = distrib(gen);
    }

    cout << "Initial array:" << endl;
    print(a, realsize);

int deletev; 
bool foundv = false;

do {
    cout << "Enter the value to remove from the array: ";
    cin >> deletev;

    foundv = false;
    for (int i = 0; i < realsize; i++) {
        if (a[i] == deletev) {
            for (int j = i; j < realsize - 1; ++j) {
                a[j] = a[j + 1];
            }
            foundv = true;
            --realsize;
            break;
        }
    }

    if (!foundv) {
        cout << "The element with the value " << deletev << " was not found in the array." << endl;
    }
} while (!foundv);

     while (!foundv) { 
        cout << "The element with the value " << deletev << " was not found in the array." << endl;
        cout << "Enter the value to remove from the array: ";
        cin >> deletev;
     }

        cout << "The array after removing the first element with a value " << deletev << ":" << endl;
        print(a, realsize);
    

    int K;
    cout << "Enter the number of elements to cycle to the right: ";
    cin >> K;

    while (K<1 || K > realsize) {
        cout << "Incorrect number." << endl;
        cout << "Enter the number of elements to cycle to the right: ";
        cin >> K;
    }

int b[K];
for (int i = 0; i < K; ++i) {
    b[i] = a[realsize - K + i];
}

for (int i = realsize - 1; i >= K; i--) {
    a[i] = a[i - K];
}

for (int i = 0; i < K; ++i) {
    a[i] = b[i];
}

cout << "Array after cyclic shift by " << K << " elements to the right:" << endl;
print(a, realsize);

    return 0;
}
