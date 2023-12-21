#include <iostream>
#include <string>
using namespace std;

int numberOfWordsBeginWithA(const string& words) {
    int number = 0;
    string word;

    for (char letter : words) 
    {
        if (isspace(letter)) 
        {
            if (tolower(word[0]) == 'a') {
                number++;
            }
            word.clear(); //очищую слово, бо переходжу на наступне, є пробіл
        }
        else
        {
            word += letter;
        }
    }

    if (tolower(word[0]) == 'a') 
    {
        number++;
    }

    return number;
}

int main() 
{
    string WORD;

    cout << "Enter a string: ";
    getline(cin, WORD); //щоб також оброблялись пробіли

    int NUMBER = numberOfWordsBeginWithA(WORD);
    cout << "Number of words that begin with letter 'a' is: " << NUMBER << endl;

    return 0;
}
