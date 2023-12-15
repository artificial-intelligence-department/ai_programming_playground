#include <iostream>
#include <string>

using namespace std;

int main(){
    string letters;
    string compresed;
    int sum = 1;
    cin >> letters;
    for(int i = 0;i < letters.size();i++)
    {
        if(letters[i]==letters[i+1]){
            sum++;
        }
        else {
           
        if(sum > 1)
        {
            compresed += letters[i] + to_string(sum);
        }
        else
        {
            compresed += letters[i];
        }
        sum = 1;
        }
    }
    cout << compresed;
}