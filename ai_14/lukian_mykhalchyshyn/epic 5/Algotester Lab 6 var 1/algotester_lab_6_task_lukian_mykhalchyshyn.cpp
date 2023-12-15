#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>

using namespace std;

int main() 
{
    int all_words, min_words;

    cin >> all_words;
    cin >> min_words;

    map <string, int> words_amount; // структура words_amount, яка зберігає кількість слів

    vector <string> words (all_words);

    for (int i = 0; i < all_words; ++i) 
    {
        cin >> words[i];

        transform (words[i].begin(), words[i].end(), words[i].begin(), ::tolower); //перетворення слова в нижній регістр
        words_amount[words[i]]++;
    }

    set <char> unique_letters;
    
    for (const auto & word : words) 
    {
        if (words_amount[word] >= min_words) // додавання букв з слів, які зустрілись min_words разів
        {
            unique_letters.insert (word.begin(), word.end());
        }
    }

    if (unique_letters.empty()) 
    {
    cout << "Empty!\n";
    }
    else 
    {
        cout << unique_letters.size() << endl;

        for (auto reverse = unique_letters.rbegin(); reverse != unique_letters.rend(); ++ reverse) // зворотній порядок виводу
        {
            cout << *reverse;

            if (next (reverse) != unique_letters.rend()) 
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}