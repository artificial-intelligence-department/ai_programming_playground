#include <iostream>
using namespace std;

int main() {
  
  double l, w, h, v;
  
  cout << "Enter the length, width and height of the parallelepiped (in centimeters) in one line."<<endl;
  
  cin >> l >> w >> h;
  
  v = l * w * h;
  
  cout << "The volume of the parallelepiped is "<< v <<endl;
  return 0;

}
