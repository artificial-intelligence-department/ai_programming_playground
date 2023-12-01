#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int num, b, s=-1, help_n, cl;

cout << "Enter number n: ";
cin >> num;
help_n = num;
while (help_n>0){
help_n = help_n/10;
s++;
}
cl = num;

int i=0;
while (cl>0){
b = cl%10;
cl = cl/10;
i = i+b*pow(10,s);
s--;
}
if (i==num){
cout << "Palindrom yes";
}
else{
cout << "Palindrom no";
}
return 0;
}