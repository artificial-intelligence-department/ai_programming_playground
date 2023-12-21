#include <iostream>
#include <string>


bool ispalindrom(const std::string& str, int start, int end){


if(start >= end)
return true;

if(str[start] == str[end]){
return ispalindrom(str, start+1,end-1);
}
else{
 return false;
}
}

bool ispalindrom(int a){
std::string s = std::to_string(a);
int b = s.size();
    

return ispalindrom(s,0,b-1);
}





int main(){
    using namespace std;
    string word;
    int number;
cout << "Введіть слово:";
cin >> word;

bool answear = ispalindrom(word, 0, size(word)-1);
if(answear == true)
cout << "Word " << word << " is palindrom" << endl;

else if(answear == false)
cout << "Word " << word << " isn't palindrom" << endl;


else{
    cout << "error" << endl;
}

cout << "Введіть число:";
cin >> number;
answear = ispalindrom(number);
if(answear == true)
cout << "Number " << number << " is palindrom" <<endl;

else if(answear == false)
cout << "Number " << number << " isn't palindrom" << endl;


else{
    cout << "error" <<endl;
}






    return 0;
}