#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

void printvec(vector <string> vec){
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
}

void findwords(string** word, int& WordIndex, string str){
    word[0] = new string;
    for (int i = 0; i < str.size(); i++){
        if (str[i] != ' '){
            *word[WordIndex] += str[i];
        } 
        else{
            WordIndex++;
            word[WordIndex] = new string;
        }
    }
}

int main(){
    string str;
    getline(cin, str);
    int WordIndex = 0;
    string **word = new string *[str.size()];
    vector<string> digit;
    vector<string> letter;
    vector<string> mixed;

    findwords(word, WordIndex, str);

    for (int i = 0; i <= WordIndex; i++){
        bool Digit = false;
        bool NotDigit = false;

        for (int j = 0; j < (*word[i]).size(); j++){
            if (isdigit((*word[i])[j])){
                Digit = true;
            }
            else if (isalpha((*word[i])[j])){
                NotDigit = true;
            }
        }

        if (Digit && !NotDigit){
            digit.push_back(*word[i]);
        } 
        else if (!Digit && NotDigit){
            letter.push_back(*word[i]);
        } 
        else{
            mixed.push_back(*word[i]);
        }
    }
    printvec(digit);
    printvec(letter);
    printvec(mixed);

    for (int i = 0; i <= WordIndex; i++){
        delete word[i];
    }
    delete[] word;

    return 0;
}