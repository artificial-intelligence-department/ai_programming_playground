#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout << "Enter array range: ";
    int N {};
    cin >> N;
    int r[N] {};
    cout << "Enter numbers for array: ";
     
    for (int i = 0; i < N; i++)
    {
        cin >> r[i];  
    }
    
    int first{};
    int second{};
    int third{};
    int NewSize{0};
    int New[N] {};
     cout << "Enter numbers u want to remove from array: ";
     cin >> first >> second >> third;
    
    for (int i=0; i < N; i++){
        if ( r[i] != first && r[i] != second  &&  r[i] != third  ){
            New[NewSize]=r[i];
            NewSize++;
        }
     
     }
     if(NewSize==0)
        cout <<"0";
     else 
     cout << NewSize-1 << endl; 
for (int i = 0; i < NewSize-1; i++)
    {
        cout << New[i]+New[i+1] <<" ";
    } 
    

    return 0;
}