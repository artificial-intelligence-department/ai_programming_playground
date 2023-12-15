//Депутатські гроші

#include <iostream>
using namespace std;

int main(){
    long int n=0;
    cin>>n;

    int counter=0;
    int denominations[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    for(int i=0; i<9; ++i){
        counter+=n/denominations[i];
        n%=denominations[i];
    
    }
    cout<<counter<<endl;
    return 0;
}