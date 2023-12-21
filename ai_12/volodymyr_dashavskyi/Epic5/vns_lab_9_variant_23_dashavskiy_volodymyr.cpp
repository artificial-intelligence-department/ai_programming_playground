#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> splitWords(const string &line)
{
    vector<string> words;
    istringstream iss(line);
    string word;
    while (iss >> word)
    {
        words.push_back(word);
    }
    return words;
}

bool hasDuplicateWords(const string &line)
{
    vector<string> words = splitWords(line);
    sort(words.begin(), words.end());
    return adjacent_find(words.begin(), words.end()) != words.end();
}

string findWordWithMostAs(const string &line)
{
    vector<string> words = splitWords(line);
    string wordWithMostAs;

    for (const string &word : words)
    {
        size_t countAs = count(word.begin(), word.end(), 'a');
        if (countAs > count(wordWithMostAs.begin(), wordWithMostAs.end(), 'a'))
        {
            wordWithMostAs = word;
        }
    }

    return wordWithMostAs;
}

void writeToFile(const string &fileName, int numLines)
{
    ofstream file(fileName);

    if (!file.is_open())
    {
        cerr << "Unable to open file: " << fileName << endl;
        return;
    }

    cout << "Enter " << numLines << " lines of text:" << endl;

    for (int i = 0; i < numLines; ++i)
    {
        string line;
        cout << "Line " << i + 1 << ": ";
        getline(cin, line);
        file << line << endl;
    }

    cout << "Data has been written to the file: " << fileName << endl;

    file.close();
}

void copyLinesWithDuplicateWords(const string &sourceFileName, const string &destinationFileName)
{
    ifstream sourceFile(sourceFileName);
    ofstream destinationFile(destinationFileName);

    if (!sourceFile.is_open() || !destinationFile.is_open())
    {
        cerr << "Unable to open files for copying." << endl;
        return;
    }

    string line;
    while (getline(sourceFile, line))
    {
        if (hasDuplicateWords(line))
        {
            destinationFile << line << endl;
        }
    }

    cout << "Lines with duplicate words have been copied to: " << destinationFileName << endl;

    sourceFile.close();
    destinationFile.close();
}

int main()
{
    const string fileNameF1 = "F1.txt";
    const string fileNameF2 = "F2.txt";
    const int numLines = 10;

    writeToFile(fileNameF1, numLines);
    copyLinesWithDuplicateWords(fileNameF1, fileNameF2);

    ifstream fileF1(fileNameF1);

    if (fileF1.is_open())
    {
        string line;
        string wordWithMostAs;

        while (getline(fileF1, line))
        {
            string currentWordWithMostAs = findWordWithMostAs(line);
            if (currentWordWithMostAs.size() > wordWithMostAs.size())
            {
                wordWithMostAs = currentWordWithMostAs;
            }
        }

        fileF1.close();

        if (!wordWithMostAs.empty())
        {
            cout << "The word with the most 'a' characters in F1.txt is: " << wordWithMostAs << endl;
        }
        else
        {
            cout << "No words with 'a' characters found in F1.txt." << endl;
        }
    }
    else
    {
        cerr << "Unable to open file: " << fileNameF1 << endl;
    }

    return 0;
}
