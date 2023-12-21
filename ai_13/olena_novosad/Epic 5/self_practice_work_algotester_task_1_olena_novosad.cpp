#include <iostream>

using namespace std;

bool findCharAndRemove(string& word, char ch) {
    auto size = word.size();
    for (int j = 0; j < size; j++) {
        if (word[j] == ch) {
            word.erase(j, 1);
            return true;
        }
    }
    return false;
}

int main() {
    string word;
    string name;
    
    cin >> word;
    cin >> name;
    
    bool result = true;
    auto nameSize = name.size();
    for (int i = 0; i < nameSize; i++) {
        if (!findCharAndRemove(word, name[i])) {
            result = false;
            break;
        }
    }
    cout << (result ? "YES" : "NO") << "\n";
    
    return 0;
}