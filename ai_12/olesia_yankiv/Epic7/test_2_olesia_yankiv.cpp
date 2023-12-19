#include <iostream>
#include <cmath>
#include <string>
//the field length is 110

using namespace std;
 
int main()
{
    cout<<"Enter Your last name"<<endl;
    string lastName; //string variable
    cin>>lastName; //input and output
    
    

    double widthWithLetters = lastName. length()* 0.8; // double variable
    double fieldArea = 110*3*12;
    int numLetter = static_cast <int> (fieldArea / widthWithLetters);
    double centralConvert = 3* 39.3701; // 3 meters converted to inches

  // here we will describe the program how to read text in both cases (left to right and right to left)
    double startLeftPosition = (fieldArea - centralConvert) /2 ;
    double endLeftPosition = startLeftPosition + centralConvert;

    double endRightPosition = fieldArea - startLeftPosition;
    double startRightPosition = endRightPosition - centralConvert;
    //display the result
    //cout<< "Your last name read left to right within the central 3 meters "<<endl;

    //for (double i = startLeftPosition; i < endLeftPosition; i+= widthWithLetters)
    //{
       //int index = static_cast<int> (i/ widthWithLetters);
       //if (index >= 0 && index < lastName. length() ) // logical operator 'and'
      // {
        //cout<<lastName[index];
       //}

   // }
    //cout<<endl;
    
    //cout<< "Your last name read right to left within the central 3 meters "<<endl;

   // for (double i = startRightPosition; i < endRightPosition; i+= widthWithLetters)
    //{
       //int index = static_cast<int> (i/ widthWithLetters);
       //if (index >= 0 && index < lastName. length() ) 
      // {
          //cout<<lastName[index];
      // }

    //}
    //cout<<endl;

    cout<<"Letters that will fit in that field size"<<endl; //if-else clause
     if (numLetter >= lastName.length())
    {
        for (int i = 0; i < lastName.length(); ++i) //for function
        {
            cout << lastName[i];
        }
    }
    else
    {
        cout << "Error! Your name does not fit" << endl;
    }
    cout << endl;
 cout<<endl;
 return 0;

}
