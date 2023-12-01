#include <iostream>

using namespace std;

int main(){
    int m[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int inp;
    int amount = 0;

    cin >> inp;

    while(inp != 0){
        for(int nominal : m){
            if(nominal <= inp){
                inp -= nominal;
                amount++;
                break;
            }
        }
    }
    
    cout << amount;

    return 0;
}