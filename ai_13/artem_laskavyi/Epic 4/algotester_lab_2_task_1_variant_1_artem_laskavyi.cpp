#include <iostream>
#include <algorithm>
using namespace std;

int main(){
 
 int N, m1, m2, result; //N - к-сть чисел масиву, m - втома
 cin >> N;
 int r[N];
 
 for (int i=0; i<N; i++){ //elements input
  cin >> r[i];
 }

sort(r, r+N); 

m1 = r[N-2] - r[0]; // with second greatest value
m2 = r[N-1] - r[1]; // with second smallest value

if(N==1 || N==2){
    result = 0;
}else{
    result = (m1<m2)? m1 : m2;
}
cout << result << endl;
return 0;
}