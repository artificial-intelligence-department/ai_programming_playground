#include<iostream>
#include<string>

bool IsPalindrome(std::string word,int LeftPos,int RightPos){
    if(LeftPos >= RightPos)
        return true;

    if(word[LeftPos] == word[RightPos])
        return IsPalindrome(word,LeftPos += 1,RightPos -= 1);
    else    
        return false;

}

int main(){
    using namespace std;

    string WordToCheck;
    cout << "Enter word to detect palindrome: " << endl;
    cin >> WordToCheck;

    string answer = (IsPalindrome(WordToCheck,0,WordToCheck.size() - 1)) ? "true" : "false";
    cout << answer;

    return 0;
}