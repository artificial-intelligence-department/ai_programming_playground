#include<iostream>
#include<vector>
using namespace std;
int biggestnumber(vector<int>vector, int length){
    int maximum = 0;
    for(int i= 0; i<length; i++)
        maximum = max(maximum,vector[i]);
    
    return maximum;
}
int main(){
    int teethamount, sharpness;
    int i;
    int counter = 0;
        cin>> teethamount>> sharpness;

    vector<int> teeth(teethamount);
    vector<int> buffer(teethamount);
        
        for(i=0;i<teethamount;i++)
            cin>>teeth[i];
        
        for(i=0;i<teethamount;i++){
            if(teeth[i]>=sharpness){
                counter++;
                buffer[i] = counter;
            } else{
                counter = 0; 
                buffer[i] = counter;
              }
        }
    
        cout<<biggestnumber(buffer, teethamount);
            
        return 0;
}