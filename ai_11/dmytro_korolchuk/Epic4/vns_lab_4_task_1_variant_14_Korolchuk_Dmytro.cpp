#include <iostream>
#include <ctime>

using namespace std;

int main(){
    int n;
    cin>>n;
    int array[n];
    srand(time(0));
    for(int i = 0; i < n; i++){
        array[i] = rand() % 10;
    }
    for(int i = 0; i < n; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

    if (n % 2 != 0) {
        int middleIndex = n / 2;
        for (int i = middleIndex; i < n - 1; i++) {
            array[i] = array[i + 1];
        }
        --n;
    }

    for (int i = 0; i < n / 2; i++) {
        int temp = array[i];
        array[i] = array[n - i - 1];
        array[n - i - 1] = temp;
    }
    
    for(int i = 0; i < n; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    n+=3;

    for (int i = n - 3 - 1; i >= 0; i--) {
        array[i + 3] = array[i];
    }

    for (int i = 0; i < 3; i++) {
        array[i] = array[i+10]-2;
    }

    for(int i = 0; i < n; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}