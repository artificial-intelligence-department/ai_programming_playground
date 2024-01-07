#include <iostream>
#include <string>

using namespace std;

int main (){

string T; // T = Tape = стрічка
cin >> T;

int count = 1;

char Cchar = T[0]; // зарашній елемент масиву

for (int i = 1; i <= T.length(); ++i){

if (T[i] == Cchar) {
    count++;
}
else {
cout << Cchar;
if (count > 1){
    cout << count;
}
Cchar = T[i];
 count = 1;
}
}
return 0;
}