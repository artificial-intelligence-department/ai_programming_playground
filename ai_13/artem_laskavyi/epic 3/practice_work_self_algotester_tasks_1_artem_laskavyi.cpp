#include <iostream>
using namespace std;

int main(){ 
    unsigned int n;
    cin >> n;
    unsigned int a[n];
    unsigned long int eat = 0;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<n; i++){
        eat += (a[i]- 1);
    }
    cout << eat << endl;
    return 0;
}

