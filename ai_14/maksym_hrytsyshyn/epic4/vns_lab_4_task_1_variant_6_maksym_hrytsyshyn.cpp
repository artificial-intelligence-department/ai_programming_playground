#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int size=12;
    srand(time(0));
    int array[size];
    for(int a=0; a<size; ++a) {
        array[a]=rand();
        cout << array[a] << " ";
    }

    int index;
    do {cout << "\nEnter the index of the array element you want to delete: ";
    cin >> index;}
    while (index<0 || index>(size-1));

    for (int a = index; a < size; ++a) {
        array[a] = array[a+1];
    }
    --size;

    int a=0;
    while(a<size-1) {
        if(array[a] % 2 == 0) {
            ++size;
            for (int b = size-1; b > a+1; --b) {
                array[b] = array[b-1];
            }
            array[a+1] = array[a] + 2;
            break;
        }
        a++;
    }

    for(int a=0; a<size; ++a) {
        cout << array[a] << " ";
    }
}
