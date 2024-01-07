#include <iostream>
using namespace std;

int main(){
    double sum = 0;
    double number;
    double avarage;

    cout << "Enter 5 fractional number: " << endl;

    for (int i = 1; i <= 5; i++){
        cout << "Enter number " << i << " : ";
        cin >> number;
        
        sum += number;
        avarage = sum/i;
    
        cout << "The arithmetic mean of the sequence: " << avarage << endl;
    } 
    return 0;
}

