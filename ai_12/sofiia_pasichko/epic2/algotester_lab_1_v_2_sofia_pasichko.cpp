#include <iostream>

using namespace std;
int main () {
long long k[4], d[4], h[4];
int i;

for(i=0;i<4;++i)
cin>>k[i];

for(i=0;i<4;++i)
cin>>d[i];

for(i=0;i<4;++i)
h[i]=k[i]-d[i];

if(h[0]<0 || h[1]<0 || h[2]<0 || h[3]<0) {
    cout << "ERROR" << endl;
} else if (h[0] <= k[1]/2 || h[1] <= k[2]/2 || h[2] <= k[3]/2 ) {
    cout << "NO" << endl;
} else if (h[0]==h[1] && h[1]==h[2] && h[2]==h[3]) {
    cout << "YES";
} else {
   cout << "NO"<<endl;
}
return 0;
}

