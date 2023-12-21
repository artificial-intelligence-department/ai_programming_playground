#include <iostream>
#include <string>

using namespace std;

int main() {

  string s;
  string word;

  cout << "Введіть рядок: ";
  getline(cin, s);

  while (getline(cin, word)) {
    bool has_vowel = false;
    for (int i = 0; word[i] != '\0'; i++) {
      if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'y' || word[i] == 'u') {
        has_vowel = true;
        break;
      }
    }

    if (!has_vowel) {
      cout << word << " ";
    }
  }

  cout << endl;

  return 0;
}