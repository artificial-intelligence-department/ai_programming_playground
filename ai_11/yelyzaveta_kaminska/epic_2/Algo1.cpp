#include <iostream>  
#include <cmath>  
using namespace std; 
int main() {  
  long long int H,M,h,m; 
  cout << "Enter number of mans:" << endl; 
  cin >> M; 
  cout << "Enter number of hitpoints:" << endl; 
  cin >> H; 
 
  bool point = true; 
   
  for(int i = 0; i<3;i++)  { 
    cin >> h >> m ; 
    if( h>0 & m>0) 
        point = false; 
    H -= h;  
    M -= m; 
  } 
  if (H>0 & M>0 & point) 
    cout << "YES"; 
  else  
    cout << "NO"; 
  return 0;   
 
}
