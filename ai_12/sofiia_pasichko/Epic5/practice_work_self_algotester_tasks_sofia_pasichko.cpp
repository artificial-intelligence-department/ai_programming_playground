#include <iostream>
using namespace std;
int main() {
int n, k1=15, k, p, z;
cin>>n;

char *line=new char[n];
for (int i=0; i<n; ++i) {
    cin >> line[i];
}

for (int i=0; i<n; ++i) {
if (line[i] == 'k' ) {
    k1=max(k1-1, 0);
}
else if (line[i] == 'p' ) {
    if (k1!=0) {
        k1=15;
    } else {
        k1=0;
    }
}
else if (line[i] == 'z' ) {
    if (k1!=0) {
        k1=0;
    } else {
        k1=15;
    }
}
}
cout << k1 << endl;
delete[] line;
return 0;
}