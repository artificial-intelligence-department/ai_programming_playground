#include <iostream>
#include <cmath>
using namespace std;

int main(){
  float n,pown,factorial;
  cin>>n;
  factorial = 1;
  float sum = 0;
  float an = 1;
  for(int i = 1; i <= n; ++i) {
    pown = i;
    factorial *= i;
    pown = pow(pown,pown);
    an=(factorial)/(3*pown); //поточний елемент ряду
    if(an<0.0001){ //перевірка точності
      break;
    }
    else{
      sum+=an; 
    }
  }
  cout<<sum;

}


