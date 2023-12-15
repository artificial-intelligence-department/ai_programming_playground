#include <iostream>

using namespace std;

int main(){
long int n=0;

cin>>n;

int count=0;

int arr[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    for(int i=0; i<9; i++)
    {
        count += n/arr[i];
        n %= arr[i];
    
    }

    cout<<count<<endl;

    return 0;
}

