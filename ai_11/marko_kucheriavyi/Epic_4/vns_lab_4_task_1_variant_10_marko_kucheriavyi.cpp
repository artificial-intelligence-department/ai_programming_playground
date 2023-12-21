#include <iostream>
#include <random>
using namespace std;
int random(){
    random_device rd; // this is used to obtain seed for the random generator
    mt19937 gen(rd()); // mt199937 is a widely used random number generator 
    uniform_int_distribution <int> distribution(1,10); 
    int RandomNumber = distribution(gen);
    return RandomNumber;
}
void printarray(int* array, int len){
    for (int i = 0; i < len; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}
void changearray(int*& array, int len){
    int* newarray = new int[len - 2];
    for (int i = 0; i < len - 5; i++){
        newarray[i] = array[i+5];
    }
    for (int i = len - 5; i < len - 2; i++){
        newarray[i] = random();
    }
    delete [] array;
    array = newarray;
}
int main(){
    const int len = 10;
    int* array = new int[len];
    for (int i = 0; i < len; i++){
        array[i] = random();
    }
    printarray(array, len);
    changearray(array, len);
    printarray(array, len - 2);
    return 0;
}