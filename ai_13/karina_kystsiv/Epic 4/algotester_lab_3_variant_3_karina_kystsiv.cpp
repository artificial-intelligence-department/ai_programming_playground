#include <string>
#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;

    if (s.empty()){
        cout << "String is empty." << endl;
        return 1;
    }

    string compressedS = "";
    char currentChar = s[0];
    int repNum = 1;

    for (size_t i = 1; i < s.length(); ++i){
        if (s[i] == currentChar){
            repNum++;
        } else {
            compressedS += currentChar;
            if (repNum > 1){
                compressedS += to_string(repNum);
            }

            currentChar = s[i];
            repNum = 1;
        }
    }

    compressedS += currentChar;
    if (repNum > 1){
        compressedS += to_string(repNum);
    }

    cout << compressedS << endl;

    return 0;
}
