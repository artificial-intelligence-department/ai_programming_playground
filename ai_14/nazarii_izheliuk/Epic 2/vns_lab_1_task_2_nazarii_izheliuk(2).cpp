#include<iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter value for n: ";
    cin >> n;
    cout << "Enter value for m: ";
    cin >> m;
    m--;
    if(m < n)
        cout << "True";
    else
        cout << "False";
    return 0;
}