#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    vector<string> inputWords, selectedWords;
    unordered_set<char> uniqueChars;
    int totalWords, position;
    cin >> totalWords >> position;
    position -= 1;

    for (int i = 0; i < totalWords; i++)
    {
        string word;
        cin >> word;
        inputWords.push_back(word);
    }

    for (auto &word : inputWords)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
    }

    sort(inputWords.begin(), inputWords.end());

    for (int i = 0; i < totalWords; i++)
    {
        if (i + position < totalWords && inputWords[i] == inputWords[i + position])
        {
            selectedWords.push_back(inputWords[i]);
        }
    }

    if (selectedWords.empty())
    {
        cout << "Empty!";
        return 0;
    }

    for (auto &selectedWord : selectedWords)
    {
        for (auto &ch : selectedWord)
        {
            uniqueChars.insert(ch);
        }
    }

    vector<char> uniqueCharacters(uniqueChars.begin(), uniqueChars.end());
    sort(uniqueCharacters.rbegin(), uniqueCharacters.rend());

    size_t uniqueCharCount = uniqueCharacters.size();
    cout << uniqueCharCount << endl;

    for (char ch : uniqueCharacters)
    {
        cout << ch << " ";
    }

    return 0;
}
