
#include <iostream>
#include <string>
using namespace std;




int main()
{
    string wCond ;
    char wCharCond;

    do
    {
         cout <<"\n" << "____________________"<< endl << "\n";
        cout << " sunny;" << endl;
        cout << " rainy" << endl;
        cout << " cloudy" << endl;
        cout << " snowy;" << endl;
        cout << " windy;" << endl;
        cout << "Q = quite" << endl;

        cout << "\nenter your weather conditions:";

        
        cin >> wCond;

       
        if(wCond == "sunny"){
            wCharCond= 'a';
            cout << "you arent gonna need any jacket, dont worry)"<< endl;
            cout << "what a great day for a picnic BTW"<< endl;
            // cout << "Take your favourite shoes"<< endl;

        }else if(wCond == "rainy"){
            wCharCond= 'b';
            cout << "You should take a jacket with you"<< endl;
            cout << "The best weather for a reading indoors "<< endl;
            // cout << "rubber boots - a great idea!"<< endl;
            

        }else if(wCond == "cloudy"){
             wCharCond= 'c';
            cout << "You should take a jacket with you just in case"<< endl;
            cout << "How about visiting a museum today?"<< endl;
            // cout << "You can wear anything you want today"<< endl;
            

        }else if(wCond == "snowy"){
             wCharCond= 'd';
            cout << "You must take a jacket with you"<< endl;
            cout << "A great time to make a snowman"<< endl;
            // cout << "snow boots will warm your feet!"<< endl;


        }else if(wCond == "windy"){
             wCharCond= 'e';
            cout << "You should take a jacket with you"<< endl;
            cout << "Try to lunch a kite if you have one "<<endl;
            // cout << "take some sturdy shoes "<<endl;
            

        }else{
            cout << "Try to enter the weather condition from the list above"<< endl;
            
        }


        switch (wCharCond)
        {
        case 'a':{
            cout << "Take your favourite shoes"<< endl;
            break;
        }
        case 'b':{
             cout << "rubber boots - a great idea!"<< endl;
            break;
        }
        case 'c':{
             cout << "You can wear anything you want today"<< endl;
            break;
        }
        case 'd':{
            cout << "snow boots will warm your feet!"<< endl;
            break;
        }
        case 'e':{
            cout << "take some sturdy shoes "<<endl;
            break;
        }
            
            
        
        default:
            break;
        }
        
      

    } while (wCond != "q" && wCond !="Q" );
    


    return 0;
}
