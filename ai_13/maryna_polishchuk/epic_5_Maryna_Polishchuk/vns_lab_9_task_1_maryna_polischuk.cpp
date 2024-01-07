#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

int CheckHowManyVowel(string str, int startPos, int endPos)
{
    int vowelCount = 0;
    // Проходження через символи в заданому діапазоні
    for (int i = startPos; i <= endPos; ++i) {
        char currentChar = tolower(str[i]); // Переведення в нижній регістр для порівняння з голосними
        // Перевірка, чи є поточний символ голосним
        if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u')
            ++vowelCount;
    }

    return vowelCount;
}

bool CheckIfMoreThan2Words(string line, string &largestVowelWord, int &maxVovels)
{
    line += ' ';
    int result = 0, temp = 0;
    bool isWordStarted = false;

    int wordStartIndex;
    for(int i = 0; i < line.size(); i++)
    {
        if(line[i] != ' ' && !isWordStarted)
        {
            temp = i;
            wordStartIndex = i;
            isWordStarted = true;
        }
        if(line[i] == ' ' && isWordStarted)
        {
            result++;
            isWordStarted = false;

            int num = CheckHowManyVowel(line, wordStartIndex, i);
            if(num > maxVovels)
            {
                maxVovels = num;
                largestVowelWord = "";
                for (int j = 0; j < i - wordStartIndex; j++)
                    largestVowelWord += line[wordStartIndex+j];
            }
        }
    }

    return result > 2;
}

int main ()
{
    ifstream var1("file1.dat");
    ofstream output("file2.dat");
    string str, largestVowelWord = "";
    int maxVovels = 0;

    while(getline(var1, str))
    {
        if (CheckIfMoreThan2Words(str, largestVowelWord, maxVovels))
            output << str << endl;
    }

    cout << "largestVowelWord: " << largestVowelWord;

    return 0;
}