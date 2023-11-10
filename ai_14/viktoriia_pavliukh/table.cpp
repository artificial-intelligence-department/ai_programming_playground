#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int hmax = -1, hmin = -1;
    string result="-";
    long h[4];
    long d[4];

    for(int i=0; i<4; i++){
        cin>>h[i];
        if(h[i] >= pow(10, 12) || h[i] < 0){
            cout<<  "NO";
            return 0;
        }
        if(h[i] > hmax || hmax == -1)
        {hmax = h[i];}
        if(h[i] < hmin || hmin == -1)
        {hmin = h[i];}
    }
    if(hmax>=2*hmin){
        result="NO";
    }
    for(int i=0; i<4; i++) {
        cin >> d[i];
        if (d[i] >= pow(10, 12) || d[i] < 0) {
            cout << "NO";
            return 0;
        }
    }
    for(int i=0; i<4; i++){
        h[i]-=d[i];
        if(h[i]<0){
            result="ERROR";
            break;
        }
        if(h[i] > hmax)
        {hmax = h[i];}
        if(h[i] < hmin)
        {hmin = h[i];}
        if(hmax>=2*hmin){
            result="NO";
        }
    }
    if(h[0]==h[1] && h[1]==h[2] && h[2]==h[3] && hmin!=0 && result=="-"){
        result="YES";
    }
    cout<<result;
}