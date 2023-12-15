#include <iostream>
using namespace std;
int main(){
string s;
string sCompressed;
int numOfRepetitions=1;
cin>>s;
for(int i=0;i<s.size();i++){
  if(s[i]==s[i+1]){
numOfRepetitions++;
}else{
sCompressed+=s[i]+(numOfRepetitions>1?to_string(numOfRepetitions):"");
numOfRepetitions=1;
}  
}
cout<<sCompressed;    
     return 0;
}