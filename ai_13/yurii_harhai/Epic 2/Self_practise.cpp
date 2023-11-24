#include <iostream>
#include <string>
using namespace std;

int main(){

    unsigned int amount {};
    cout << "Enter ur ammount of money: ";
    cin >> amount;
    string names[6] = {"hryvnia", "50kop", "25kop", "10kop", "5kop", "1kop" };
    int nominal[6] = {100, 50, 25, 10, 5, 1};

    int sonic[6] = {};

    for (int i = 0; i < 6; i++) {
        sonic[i] = amount/nominal[i];
        cout << names[i] << ": " << sonic[i] << endl;
        amount %= nominal[i];
    }
       
  
    return 0;
}