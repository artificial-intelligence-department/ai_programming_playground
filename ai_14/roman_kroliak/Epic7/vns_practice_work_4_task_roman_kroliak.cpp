#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int j = 1;
    for (int i = 0; i < 5; i++) {
        cout << pow(j, 2) << " ";
        j+=2;
    }
    return 0;
}