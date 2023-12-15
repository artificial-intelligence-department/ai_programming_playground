#include<iostream>
#include<string>
#include<vector>

int findMin(std::vector<int> numbers){
    int minimum = numbers[0];
    for(int i = 1;i < numbers.size();i++){
        if(minimum > numbers[i])
            minimum = numbers[i];
    }
    return minimum;
}

int findMin(std::string text){
    int MinLen = text.size();
    int LenCounter = 0;
    for(int i = 0;i < text.size();i++){
        if(text[i] == ' ' || i == (text.size()-1)){
            if(LenCounter < MinLen)
                MinLen = LenCounter;
            LenCounter = 0;
        }
        LenCounter += 1;
    }
    return MinLen;
}

int main(){
    using namespace std;
    string text = "ad bad ddra dfa d";
    vector<int> numb = {1,2,3,4,5,6,1};

    cout << findMin(text);
    cout << findMin(numb);

    return 0;
}