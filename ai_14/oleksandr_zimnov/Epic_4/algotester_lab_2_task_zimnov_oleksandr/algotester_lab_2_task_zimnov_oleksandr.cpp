#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    int N, a, b, c;
    cout << "Enter size of massive: ";
    cin >> N;
    while(N < 1 || N > pow(10, 5)){
        cout << "Enter size of massive again (it's must be from 1 to 100000): ";
        cin >> N;
    }
    int* r = new int[N];
    cout << "Enter numbers for the massive: " << endl;
    for (int i = 0; i < N; i++) {
        cout << "Enter " << i+1 << " number: ";
        cin >> r[i];
        while(r[i] < 0 || r[i] > pow(10, 5)){
            cout << "Enter " << i+1 << " number again (it's must be from 0 to 100000): ";
            cin >> r[i];
        }
    }
        cout<<"Enter number a: ";
        cin>>a;
    while(a<0 || a>pow(10,5)){
        cout<<"Enter number a again (from 0 to 100000): ";
        cin>>a;
    }
        cout<<"Enter number b: ";
        cin>>b;
    while(b<0 || b>pow(10,5)){
        cout<<"Enter number b again (from 0 to 100000): ";
        cin>>b;
    }
        cout<<"Enter number c: ";
        cin>>c;
    while(c<0 || c>pow(10,5)){
        cout<<"Enter number c again (from 0 to 100000): ";
        cin>>c;
    }
    int* newR = new int[N]; 
    int newN = 0; 

for (int i = 0; i < N; i++) {
    if (r[i] != a && r[i] != b && r[i] != c) {
            newR[newN] = r[i];
            newN++;
    }
}   
    int* newR2 = new int[newN]; 

for (int i = 0; i < newN; i++) {
            newR2[i] = newR[i];
    if (i!=0) {
            newR2[i] += newR[i-1];
    }
}
if(newN!=0){
    cout<<newN-1<<endl;
}else{
    cout<<newN<<endl;
}
for (int i = 1; i < newN; i++) {
    cout<<newR2[i]<<" ";
} 
    return 0;
}
