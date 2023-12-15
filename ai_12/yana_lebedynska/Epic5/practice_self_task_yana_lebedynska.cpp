#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    string word;
    cin >> word;

    set<char> LETTERS;

    for (char letter : word) 
    {   
        LETTERS.insert(letter);
    }

    cout << LETTERS.size() << endl;

    return 0;
}
