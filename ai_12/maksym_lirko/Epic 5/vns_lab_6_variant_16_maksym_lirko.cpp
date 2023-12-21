#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main() 
{
    string sentences = "hello hello today is is tuesday";
    bool Repeated_WORD;
    cout << "Text: " << sentences;
    istringstream iss(sentences);
    string word;
    map<string, int> counter;

    while (iss >> word) 
    { 
        counter[word]++; 
    }

    cout<<endl;
    for (auto &words : counter) 
    {
        if (words.second == 1)
        {
            cout << "\nWord that appears in the text only 1 time: \n";
            cout << words.first << " - meets " << words.second << " time\n";
            Repeated_WORD = true;
        }
    }

    if (Repeated_WORD != true) 
    { 
        cout << "\nWord that appears in the text only 1 time not found\n"; 
    }

    return 0;
}