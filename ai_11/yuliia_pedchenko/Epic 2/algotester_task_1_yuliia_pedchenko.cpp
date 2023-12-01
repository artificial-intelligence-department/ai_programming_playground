#include <iostream>

using namespace std;

int main() {
long long cubes[5];

for(int i=0; i<5; i++)
    {
        long long int c;
        cin >> c;
        if (c <= 0){ 
            cout << "ERROR";
        return 0;
        }
        else if (i > 0 && c > cubes[i-1]){
            cout << "LOSS";
            return 0;
        }
        cubes[i]=c;
}
cout << "WIN";
return 0;
}

