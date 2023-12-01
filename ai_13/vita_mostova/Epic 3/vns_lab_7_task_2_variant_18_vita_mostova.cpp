#include <iostream>
#include<string.h>
using namespace std;
int find_max(int arr[],int length);
int find_max(char *s);
int main(){

int myArray[]={3,35,47,76};
char s[]="Find the largest word";

cout<<find_max(myArray,4)<<endl;
cout<<find_max(s)<<endl;

     return 0;
}

int find_max(int arr[],int length){
int max=arr[0];
    for(int i=0;i<length;i++){
        
        if (arr[i]>max) 
            max=arr[i];
           }return max;
       

}
int find_max(char *s){
    int len=strlen(s);
    int count=0;
    int max = -1;
    char nonwords[]=" .,!?";
    int i=0;
     while(i<len){
        count=0;
while(i<len){
    if(strchr(nonwords,s[i])!=NULL)
    break;
    i++;
    
    count++;
}
if (count>max){
    max=count;
}
   while(i<len){
    if(strchr(nonwords,s[i])==NULL)
    break;
    i++;
   }  }
   return max;
} 