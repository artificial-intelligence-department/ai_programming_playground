#include <iostream>
#include <string>


using namespace std;


int main() {int n;
    int lostLetters = 0;


    cin >> n;


    cin.ignore();


    for (int i = 0; i < n; i++) {
        string word;
        getline(cin, word);


       for (int j = 1; j <= word.length(); j++) {
    if (word[j-1] == '#') {
        if (word[j - 1] == word[j]) {
            lostLetters--;
        }
        lostLetters++;
    }
}
}
 cout <<  lostLetters << endl;


    return 0;
}
