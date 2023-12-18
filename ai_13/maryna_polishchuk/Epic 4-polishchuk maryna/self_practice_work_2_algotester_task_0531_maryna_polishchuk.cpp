//веселі каруселі
# include <iostream>
using namespace std;  

int main (){
       int k, n, quan=0;
       cin >> k; 
       cin >> n;
    int c[n];
    
    for (int i=0; i<n; i++)
    {
        cin >> c [i];
    }
      for (int i= 0; i< n; i++)
  {
      for (int  j=0; j< n-1-i; j++)
      {
          if (c[j]>c[j+1])
          {
             int temp=c[j];
             c[j]=c[j+1];
             c[j+1]= temp;
          }
      }
  }
    for (int j=0; j<n; j++){
        if (k < c[j]){
           break;
        }
        k=k-c[j];
        quan ++; 
    }
    cout << quan;
return 0;
}
