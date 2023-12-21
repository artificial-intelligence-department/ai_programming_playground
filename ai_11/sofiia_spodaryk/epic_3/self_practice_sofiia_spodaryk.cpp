#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    string word;
    cin >> word;

    set<char> letters;

    for (int i = 0; i < word.length(); ++i) {
        char letter = word[i];
        letters.insert(letter);
    }

    cout << letters.size() << endl;

    return 0;
}