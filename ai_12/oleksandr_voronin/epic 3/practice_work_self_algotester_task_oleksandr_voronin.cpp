#include <iostream>

using namespace std;

int main(){
   long long int n;
    cin >> n;
    long long int array[n];
    long long int result=0;
    
    for(int i=0;i < n;i++){
         
         cin >> array[i];
         array[i] -= 1;
        result += array[i];
    }
    
    cout <<result;
    return 0;
}