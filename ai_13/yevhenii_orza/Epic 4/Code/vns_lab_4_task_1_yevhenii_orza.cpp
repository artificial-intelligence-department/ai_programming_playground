#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main (){
    
    int array[10];
    int indexOfMax, indexOfMin;
    int midle, sum, num;
        for(int i = 0; i < 10; i++){
            int random = rand() % 1000;
            array[i] = random;
        }
        for(int i = 0; i<10; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    int n = sizeof(array) / sizeof(array[0]);
    int min = *min_element(array, array + n);
    int max = *max_element(array, array + n);

     for(int i = 0; i < 10; i++){
        if(array[i] >= max ){                     
        indexOfMax = i;            
    }

        if(array[i] <= min){
            indexOfMin = i;
    }
    }
    array[indexOfMax] = min;
    array[indexOfMin] = max;
    for(int i = 0; i<10; i++){
            cout << array[i] << " ";
        }
        
    cout << endl;

    for (int i = 0; i < 10; i++) {
        num = array[i];
        sum += num;
    }

    midle = sum / 10;
    cout << midle << endl;
    int midle10 = (((midle/100)*10) + midle);
    cout << midle10 << endl;
    int newSize = 0;
    for (int i = 0; i < 10; i++) {
        if (array[i] < midle10) {
            array[newSize] = array[i];
            newSize++;
        }
    }
    for(int i = 0; i < newSize; i++){
        cout << array[i] << " ";
    }

    return 0;
}