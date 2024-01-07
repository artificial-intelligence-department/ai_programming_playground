#include <iostream>
#include <algorithm>                               
using namespace std;

int main () {
long N, min;
cin >> N;
long R [N];

for (long i = 0; i < N; i++){
   cin >> R[i];}

sort(R, R + N);                                  
if (N == 1){
    min = 0;
} else if (R[N-2] - R[0] > R[N-1] - R[1]) {
    min = R[N-1]-R[1];
   }  else if (R[N-2] - R[0] < R[N-1] - R[1]) {
   min = R[N-2] - R[0]; }
cout << min;
return 0;
}




