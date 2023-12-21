#include <iostream>
#include <vector>
#include <string>
int main(){
using namespace std;
int result = 0;
string word;
cin >> word;
vector<char> ans = {0};
bool chak = true;
for(int i= 0; i<size(word) ; i++){
char letter = word[i];
for(int j = 1; j < ans.size(); j++ ){
if( letter == ans[j]){
    chak = false;
    break;
}
}


if(chak == true){
result++;
ans.push_back(letter);
}

else if(chak == false)
chak = true;

}

cout << result;
    return 0;
}