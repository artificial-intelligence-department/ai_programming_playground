#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void Show_most_repeated_word(char* s) 
{
    const char stop[] = " ."; 
    char* word = strtok(s, stop);
    unordered_map<string, int> mostRepeated;

    while (word != nullptr) 
    {
        mostRepeated[word]++;
        word = strtok(nullptr, stop);
    }

    // Знаходимо найчастіше повторюване слово
    string most_repeated_word;
    int max = 0;

    for (const auto& klutch_or_num : mostRepeated) 
    {
        if (klutch_or_num.second > max) 
        {
            max = klutch_or_num.second;
            most_repeated_word = klutch_or_num.first;
        }
    }
    cout<<"Найбільше разів повторювалось слово: "<<most_repeated_word;
}

int main(){
    cout<<"Введіть ваш рядок(до 255 елементів): ";
    char s[256];
    gets(s);
    Show_most_repeated_word(s);
    return 0;
}