#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main ( ) {
    int array [100];
    int new_array[100];
    int count, new_count, x;

    cout << "Enter the size of array : ";
    cin >> count;

    new_count = count;

    srand(time(NULL));

    for (int i=0; i<count; i++) {
        array[i]=rand()%101;
        cout << array[i] << " ";
    }

    for (int d=count; d>count-5; d--) {
        new_count--;
    }

    for (int j=0; j<new_count; j++) {
        new_array[j]=array[j];    
    }    

    for (int b=new_count; b>=0; b--) {
        x=new_array[b];
        new_array[b+3]=x;
    }
    
    for (int k=2; k>=0; k--) {
        new_array[k]=new_array[k+1]+2;
    }
    cout << "\n";

    for (int i=0; i<new_count+3; i++) {
        cout << new_array[i] << " ";
    }
}