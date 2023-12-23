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
        cout<<" and wear something warm, its  cold outside.";
        }
   }
   else if (weather=="sunny"){
     cout<<"You dont need a coat today";
   }else{
    cout<<"Choose another option "<<endl;
   }
   
   if(weather=="cloudy"||weather=="windy"||weather=="snowy"){
    cout<<"\nBetter stay at home and relax\n";
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
    cout<<"\nGo outside!";
   }
   else if(weather=="rainy"){
    cout<<"\nIts perfect time to read a book!";
   }
  
   switch(weather[0]){
        
       case  'r':
       
               cout<<"\nand better put on rubber boots.";
               break;
        case 'c' :
        
        case 'w' :
        
               cout<<"\nand better put on casual shoes.";
               break;
        
               
        case  's':
        
            if(weather=="snowy"){
              cout<<"\nand better put on boots.";
               break;}
            else if(weather=="sunny"){
        
               cout<<"\nand better put on flip-flops.";
               break;}
               
    }
    return 0;

}