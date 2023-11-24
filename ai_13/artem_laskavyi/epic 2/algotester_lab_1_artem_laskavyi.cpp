#include <iostream>
#include <algorithm>
using namespace std;

int main(){ 
  
long int h[4]; 
long int d[4]; 
bool flipped = false;
long int h_max, h_min;

for (int i=0; i<4; i++){ 
    cin >> h[i];
}

for (int i=0; i<4; i++){ 
    cin >> d[i];
}

for(int i=0; i<4; i++){

    h[i] = h[i] - d[i];

    h_max = *max_element(h, h+4); 
    h_min = *min_element(h, h+4);

    if(h_max >= 2*h_min){
    flipped = true;
    }
}

if(flipped == false && h_min > 0){
    cout << "YES" << endl;
}else if(h_min < 0){
    cout << "ERROR" << endl;
}else{
    cout << "NO" << endl;
}
    return 0;
}
