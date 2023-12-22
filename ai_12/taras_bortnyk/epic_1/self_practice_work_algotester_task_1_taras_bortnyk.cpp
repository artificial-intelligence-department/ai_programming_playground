#include<iostream>
using namespace std;

int main() {
    int n, n1=0;
    cin >> n;  
    
         int money[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 9; i++) {
        n1 += n/ money[i];
    
        n %= money[i];
    }

    cout <<n1 << endl;
    

    return 0;
}