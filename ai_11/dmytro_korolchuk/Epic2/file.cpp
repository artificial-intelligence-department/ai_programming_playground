#include <iostream>
using namespace std;

int main(){
  int i,j,x;
  cin>>i;
  cin>>j;
  int matrix[i][j];
  for(int n = 0; n<i; n++ ){
    for(int n2 =0; n2<j; n2++){
      cin>>matrix[n][n2]; 
    }
  }
  
  for(int n = 0; n<i; n++ ){
    for(int n2 =0; n2<j; n2++){
      cin>>x;
      matrix[n][n2]+=x;
    }
  }
  
  for(int n = 0; n<i; n++ ){
    for(int n2 =0; n2<j; n2++){
      cout<<matrix[n][n2]<<' '; 
    }
    cout<<endl;  
  }
}
