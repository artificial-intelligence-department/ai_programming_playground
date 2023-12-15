#include <iostream>
using namespace std;

int main() {
    long int n=0;
    cin >> n;

    int bills[]={500,200,100,50,20,10,5,2,1};
    int billNumber=0;
    int a=0;
    while (a<9 || n>0){
        billNumber += n/bills[a];
        n %= bills[a];
        a++;
    }
    cout << billNumber << endl; 

    return 0;  
}