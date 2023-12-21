#include <iostream>
#include <vector>


int main(){
using namespace std;
string word;
cin >> word;
vector<char> letter;
vector<long int> capacity;
int n = 0;
int c = 0;
if(size(word)== 1){
cout << word;
return 0;
}
for(int i = 0; i+1<size(word);i++){
    letter.push_back(word[i]);
    capacity.push_back(0);
for(int j = i; j< size(word); j++){
n = j-1;
if(word[i] == word[j])
capacity[c] += 1; 
else{

break;
}



}
i = n;
 if(n == size(word)-2){
    if(word[n+1] != word[n]){
    letter.push_back(word[i+1]);
    capacity.push_back(1);
    break;
    }
 }
 
    
 


c += 1;
    

}
for(int n = 0; n < size(letter);n++){
if(capacity[n] == 1)
cout << letter[n];

else{
cout << letter[n] << capacity[n];
}
}









    return 0;
}