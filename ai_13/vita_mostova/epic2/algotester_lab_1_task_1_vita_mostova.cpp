#include <iostream>
using namespace std;
int main(){
     long long int H;
     long long int M;
     cout<<"The number of hitpoints: "<<endl;
     cin>>H;
     cout<<"The number of manna: "<<endl;
     cin>>M;
      
     for(int i=0;i<3;i++){
        long long int hi;
        long long int mi;    
        cout<<"Type in the value of h["<<i<<"]"<<endl;
        cin>>hi;
        cout<<"Type in the value of m["<<i<<"]"<<endl;
        cin>>mi;
        H-=hi;
        M-=mi;
        if((hi>0 && mi>0) || (H<=0 || M<=0)){
                cout<<"NO"; 
                return 0;
            }         
        }
        if(H>0 && M>0){
            cout<<"YES";
        
        }else{ cout<<"NO";}
   

    return 0;
}