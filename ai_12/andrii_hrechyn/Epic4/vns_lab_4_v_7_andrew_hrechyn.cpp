#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
int length = 10, indexnext;
int array[length];

for(int i = 0; i < length; i++)
    {
        array[i] = rand() % 10;
        cout << array[i] << " ";
    }
cout << endl;


for(int j = length - 1; j >= 0; j--){
    if(array[j] == 0){
        for(int i = j; i < length - 1; i++){
            array[i] = array[i+1];
                }
    length--;
    j--;
    break;
    }
}
for(int i = 0; i < length; i++){
    cout << array[i] << " ";
        }
cout << endl;

int Index = 3;
    for(int i = length-1; i > Index; i--){
        array[i+1] = array[i];
    }
    length++;
array[Index+1]=100;

for(int i = 0; i < length; i++){
    cout << array[i] << " ";
        }
    return 0;
}