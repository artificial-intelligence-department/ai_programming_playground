#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int CountWords(char* line){

int sum = 0;
istringstream is(line);
string words;
 while (is >> words) {
        sum++;
    }
return sum;

}
int main (){

    char line[255];
    cout << "Enter elements "<<endl;
    cin.getline(line,'.');
    cout << line <<endl;
    int sumofwords = CountWords(line);
    cout << sumofwords;
    
}