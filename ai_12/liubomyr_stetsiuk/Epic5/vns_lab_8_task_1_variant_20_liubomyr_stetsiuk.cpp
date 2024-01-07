#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int countVowels(string str)
{
    int count = 0;
    for (char c : str)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    ifstream fileF1("F1.txt");
    ofstream fileF2("F2.txt");

    if (!fileF1.is_open() || !fileF2.is_open())
    {
        cout << "Не вдалося відкрити файли F1 або F2.\n";
        return 1;
    }

    vector<string> lines;
    string line;

    while (getline(fileF1, line))
    {
        lines.push_back(line);
    }

    vector<string> uniqueLines;

    for (const auto &currentLine : lines)
    {
        vector<string> words;
        string word = "";

        for (char c : currentLine)
        {
            if (c != ' ')
            {
                word += c;
            }
            else
            {
                words.push_back(word);
                word = "";
            }
        }
        words.push_back(word);

        for (const auto &testLine : lines)
        {
            if (testLine != currentLine)
            {
                vector<string> testWords;
                string testWord = "";

                for (char c : testLine)
                {
                    if (c != ' ')
                    {
                        testWord += c;
                    }
                    else
                    {
                        testWords.push_back(testWord);
                        testWord = "";
                    }
                }
                testWords.push_back(testWord);

                bool foundMatch = false;
                for (const auto &word : words)
                {
                    if (find(testWords.begin(), testWords.end(), word) != testWords.end())
                    {
                        foundMatch = true;
                        break;
                    }
                }
                if (foundMatch)
                {
                    uniqueLines.push_back(testLine);
                }
            }
        }
    }

    for (const auto &line : uniqueLines)
    {
        fileF2 << line << '\n';
    }

    string lastLine = uniqueLines.empty() ? "" : uniqueLines.back();

    int vowelCount = countVowels(lastLine);

    cout << "Кількість голосних букв у останньому рядку файлу F2: " << vowelCount << endl;

    fileF2 << "\nКількість голосних букв у останньому рядку: " << vowelCount;

    fileF1.close();
    fileF2.close();

    return 0;
}
