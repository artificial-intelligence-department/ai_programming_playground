//algotester 1681 - Соціальна дистанція
#include <iostream>

using namespace std;

int main(){
    long long position[10000];
    int number;
    cin >> number;
    for(int i = 0; i < number; i++){
        cin >> position[i];
    }
    for(int i = 0; i < number-1; i++){
        if(position[i+1]-position[i]<2){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}