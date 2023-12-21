#include <iostream>
#include <vector>
#include <string>
using namespace std;
string remove_paired_words(vector<char>& charVector) {
    int count=0;
    int temp=0;
   for(int i = 0; i < charVector.size(); i++){
       if(charVector[i]==' ') {
           count++;
           if (count % 2 != 0) {
                temp = i;
           }else if (count % 2 == 0){
               charVector.erase(charVector.begin() + temp, charVector.begin() + i );
               i = temp + 1;
               temp = 0;
           }
       }
   }
    charVector.erase(charVector.begin() + charVector.size()-1);
    return string(charVector.begin(), charVector.end());
}

int main() {
    string str;
    cout << "Enter a sentence: ";
    // hello my dear friend how are you
    getline(cin, str);
    vector<char> charVector;
    charVector.assign(str.begin(), str.end());
    charVector.push_back(' ');
    string processed_sentence = remove_paired_words(charVector);
    cout << "Processed sentence: " << processed_sentence << "." << endl;
    return 0;
}