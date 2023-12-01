#include <iostream>
#include <vector>

using namespace std;

int main(){
  int ken;
  cin>>ken;
  vector <int> dp(ken,1),array(ken);
  for(int i =0;i<ken;i++){
    cin>>array[i];
  }
  for(int i = 1; i<ken; i++){
    for(int j = 0; j<i;j++){
      if(array[j]<array[i]){
        dp[i]=max(dp[i],dp[j]+1);
      }
    }
  }
  int ans =1;
  for(int i =0; i<ken;i++){
    if(ans < dp[i])
    {
      ans = dp[i];
    }
  }
  cout<<ans;
}
