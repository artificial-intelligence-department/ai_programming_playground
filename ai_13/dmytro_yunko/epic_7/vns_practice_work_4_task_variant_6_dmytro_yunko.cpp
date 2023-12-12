#include <iostream>
using namespace std;

int main() {
  
  int n, x, sum, count;
  
  cout << "Enter the number";
  cin >> n;
  
  x = 2; 
  sum = 0; 
  count = 0; 
  
  while (count < n) {
    
    sum += x;
    
    x += 2;
    
    count++;
    cout<< count<<endl;
  }
  
  cout << "Sum: " << sum << endl;
  return 0;
}
