#include <iostream>
#include <string>
using namespace std;

int main(){
   
    string weather;
    cout<<"What is the weather today? "<<endl;
    cin>>weather;
   if(weather=="cloudy"|| weather=="rainy" || weather== "windy"|| weather=="snowy"){
    cout<<"\nYou need a coat(";
    if(weather=="snowy"){
        cout<<" and put on your hat, its really cold outside.";
        }
    if(weather=="rainy"){
        cout<<" and take an umbrella with you.";
        }
   }
   else if (weather=="sunny"){
     cout<<"Its hot outside. You dont need a coat)";
   }else{
    cout<<"It looks like there is no such option as "<<weather<<".You can choose this options: rainy,cloudy,windy,sunny or snowy."<<"Try again!"<<endl;
   }
   
   if(weather=="cloudy"||weather=="windy"||weather=="snowy"){
    cout<<"\nBetter stay at home and watch your favorite TV series!";
    if(weather=="snowy"){
        cout<<"Or you can play in the snow)";
    }
    if(weather=="windy"){
        cout<<"Or you can fly a kite";
    }
    if(weather=="cloudy"){
        cout<<"Or you can visit a museum";
    }

   }
   else if(weather=="sunny"){
    cout<<"\nGo outside and have fun!";
   }
   else if(weather=="rainy"){
    cout<<"\nIts perfect time to read a book!";
   }
  
   switch(weather[0]){
        
       case  'r':
       
               cout<<"\nIf you do go outside, don`t forget to put on rubber boots.";
               break;
        case 'c' :
        
        case 'w' :
        
               cout<<"\nIf you do go outside, don`t forget to put on casual shoes.";
               break;
        
               
        case  's':
        
            if(weather=="snowy"){
              cout<<"\nIf you do go outside, don`t forget to put on boots.";
               break;}
            else if(weather=="sunny"){
        
               cout<<"\nDon`t forget to put on flip-flops.";
               break;}
               
    }
    return 0;

}