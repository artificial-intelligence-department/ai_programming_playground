#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> wordList, selectedWordsList;
    vector<char> finalCharacters;
    vector<char>::iterator charIter;
    long long totalWords, position;
    cin >> totalWords >> position;
    position -= 1;

    for (int i = 0; i < totalWords; i++)
    {
        string tempWord;
        cin >> tempWord;
        wordList.push_back(tempWord);
    }

    for (auto &word : wordList)
    {
        for (auto &character : word)
        {
            character = tolower(character);
        }
    }

    sort(wordList.begin(), wordList.end());

    for (int i = 0; i < totalWords; i++)
    {
        if (i + position < totalWords)
        {
            if (wordList[i] == wordList[i + position])
            {
                string temp = wordList[i];
                selectedWordsList.push_back(temp);
            }
        }
    }

    if (selectedWordsList.empty())
    {
        cout << "Empty!";
        return 0;
    }

    for (auto &word : selectedWordsList)
    {
        for (auto &character : word)
        {
            finalCharacters.push_back(character);
        }
    }

    sort(finalCharacters.begin(), finalCharacters.end());
    charIter = unique(finalCharacters.begin(), finalCharacters.end());
    finalCharacters.resize(distance(finalCharacters.begin(), charIter));
    reverse(finalCharacters.begin(), finalCharacters.end());

    size_t finalSize = finalCharacters.size();
    cout << finalSize << endl;

    for (char character : finalCharacters)
    {
        cout << character << " ";
    }

    return 0;
}
