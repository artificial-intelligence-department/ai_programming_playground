#include <iostream>
float function(float a, float b){
float result = a/b;

return result;

}
float  numerator(float a,float d){

float numerator = a*d;

return numerator;
}

float  denominator(float b, float c){

float denominator = b*c;

return denominator;}







int main(){
using namespace std;
float number1;
float number2;
cout << "-----------Ділення десяткових дробів------------ \n";
cout << "введіть перше число:";
cin >> number1;
cout << "введіть друге число:";
cin >> number2;
float answear = function(number1,number2);
cout << answear << endl;


cout << "----------Ділення звичайних дробів------------\n";
float number3;
float number4;
cout << "введіть перше число(спочатку чисельник, потім знаменник):\n";
cin >> number1;
cout << "/";
cin >> number2;
cout << "введіть друге число(спочатку чисельник, потім знаменник):\n";
cin >> number3;
cout << "/";
cin >> number4;

answear = numerator(number1,number4);
float answear1 = denominator(number2,number3);
cout << "відповідь:" << answear  << "/" << answear1;







    return 0;
}