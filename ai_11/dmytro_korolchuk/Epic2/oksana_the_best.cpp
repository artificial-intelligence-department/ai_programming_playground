#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int ans = 1;
  long min;
  long max;

  vector <long> table(4),gen_z(4);
    for(int i =0;i<4;i++){
    cin>>table[i];
  }
  for(int i =0;i<4;i++){
    cin>>gen_z[i];
  }

  for(int i=0;i<4;i++){
    if(gen_z[i]>table[i]) {
        cout << "ERROR" << endl;
        ans = -1;
        break;
      }
    table[i]-=gen_z[i];
    min = *min_element(table.begin(), table.end()); 
    max = *max_element(table.begin(), table.end());
    if(max >= 2*min){
      ans = 0;
    }
  }
  if(ans == 1){
    if(max==min){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
  else if(ans == 0){
    cout<<"NO"<<endl;
  } 
  return 0;
}
