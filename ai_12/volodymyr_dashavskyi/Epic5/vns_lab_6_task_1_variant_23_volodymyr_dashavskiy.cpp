#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    const int maxLength = 255;
    char buffer[maxLength];

    cout << "Type in the sentence: ";
    cin.getline(buffer, maxLength, '.');

    istringstream iss(buffer);
    string word;
    int shortestWordLength = maxLength;

    while (iss >> word)
    {
        int wordLength = word.length();
        if (wordLength < shortestWordLength)
        {
            shortestWordLength = wordLength;
        }
    }

    cout << "The lenght of the shortest word is: " << shortestWordLength << endl;

    return 0;
}